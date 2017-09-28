#!/bin/bash
#
# pcap2wavgsm
# Original Author: Michael Collins <msc@freeswitch.org>
#Standard disclaimer: batteries not included, your mileage may vary...
# Updated by Avi Marcus <avi@bestfone.com>
#
# Accepts arg of pcap file w/only 2 RTP streams
# Creates a .<codec> file and a .wav/.gsm file
# For codecs other than PCMA and PCMU the script calls fs_cli and does a little recording to create the wav/gsm file(s)
# Current codec support: g711a/u, GSM, G722, G729

# check for -h -help or --help

# adjust by Andreas Wilhelm, original from https://gist.github.com/avimar/d2e9d05e082ce273962d742eb9acac16

if [[ $1 == "-h" || $1 == "-help" || $1 == "--help" || $1 == "" ]]
then
    cat <<EOF

pcap2wavgsm is a simple utility to make it easier to extract the audio from a pcap

Dependencies:
   apt-get install -y tshark sox
   yum install wireshark sox
   
Usage:

  pcap2wavgsm [opts] targetCodec filename.pcap [target filename]

Script attempts to create a few files: a .<codec> file and a .gsm or .wav file for each RTP stream

targetCodec has to be wav or gsm

It requires Tshark to be installed on the system. If a codec other than PCMA or PCMU
 is used then the script will attempt to use fs_cli to decode and create a gsm or wav

Supported codecs:
 PCMU (G711 ulaw)
 PCMA (G711 Alaw)
 GSM
 G722 (requires fs_encode)
 G729 (requres fs_encode with mod_com_g729)

Supported options:
 -z  Perform "clean and zip" - After converting to gsm/wav files the program will "clean up"
                               by putting the gsm/wav files into a .tgz file and then removing
                               the .gsm/.wav and .<codec> files from the disk.
EOF

exit
fi

if [[ $1 == "-z" ]]
then
    CLEAN=true
    TARGETCODEC=$2
    CAPFILE=$3
    TARGETFILE=$4
else
    CLEAN=false
    TARGETCODEC=$1
    CAPFILE=$2
    TARGETFILE=$3
fi

LOGDIR=/var/log
TSHARK=`which tshark`
SOX=`which sox`
FSENCODE=`which fs_encode`

if [[ $TSHARK == "" ]]
then
    echo "Tshark not found. Please install Tshark and then re-run this script"
    exit
fi

if [[ $SOX == "" ]]
then
    echo "Sox not found. Please install Sox and then re-run this script"
    exit
fi

# Make sure pcap exists
if [ -f $CAPFILE ]
then
    echo "Found $CAPFILE, working..."
else
    echo "$CAPFILE not found, exiting."
    exit
fi

# Set target file names; default is "pcap2wavgsm.<codec>" and "pcap2wavgsm.gsm"
if [[ $TARGETFILE == "" ]]
then
    TARGETFILE="/tmp/pcap2wavgsm"
else
    echo "Using $TARGETFILE"
fi

echo "Checking $CAPFILE for RTP streams..."

# Locate RTP streams, put into temp file
tshark -n -r $CAPFILE -Y rtp -T fields -e rtp.ssrc -e udp.dstport -Eseparator=, | sort -u > /tmp/pcap2wavgsm.tmp

# Count the RTP streams
num_streams=`grep -c "" /tmp/pcap2wavgsm.tmp`
streams=( $(cat /tmp/pcap2wavgsm.tmp) )

#Extract stream ssrc and port
for item in `seq 1 $num_streams`; do
    index=$((item-1))
    ssrc[$item]=`echo ${streams[$index]} | cut -d, -f1`
    port[$item]=`echo ${streams[$index]} | cut -d, -f2`
done

payload_type=`tshark -n -r $CAPFILE -T fields -e rtp.p_type | grep -P '\d+' | head -n 1`
case $payload_type in
    0) codec='PCMU'
        for item in `seq 1 $num_streams`; do
            convert[$item]="$SOX -t ul -r 8000 -c 1 ${TARGETFILE}_$item.$codec ${TARGETFILE}_$item.$TARGETCODEC"
        done
        ;;
    3) codec='GSM'
        for item in `seq 1 $num_streams`; do
            convert[$item]="$SOX -t gsm -r 8000 -c 1 ${TARGETFILE}_$item.$codec ${TARGETFILE}_$item.$TARGETCODEC"
        done
        ;;
    8) codec='PCMA'
        for item in `seq 1 $num_streams`; do
            convert[$item]="$SOX -t al -r 8000 -c 1 ${TARGETFILE}_$item.$codec ${TARGETFILE}_$item.$TARGETCODEC"
        done
        ;;
    9) codec='G722'
        for item in `seq 1 $num_streams`; do
            convert[$item]="$FSENCODE ${TARGETFILE}_$item.$codec ${TARGETFILE}_$item.$TARGETCODEC"
        done
        ;;
    18) codec='G729'
        for item in `seq 1 $num_streams`; do
            convert[$item]="$FSENCODE -l mod_com_g729 ${TARGETFILE}_$item.$codec ${TARGETFILE}_$item.$TARGETCODEC"
        done
        ;;
esac

if [ -z "$codec" ]; then
    echo "Unable to determine codec from payload type: $payload_type"
    exit
fi

echo "Target files to create:"
for item in `seq 1 $num_streams`; do
    echo "${TARGETFILE}_$item.$codec and ${TARGETFILE}_$item.$TARGETCODEC"
done

echo
for item in `seq 1 $num_streams`; do
    echo "Stream $item ssrc / port: ${ssrc[$item]} / ${port[$item]}"
done
echo

for item in `seq 1 $num_streams`; do
    echo "Extracting payloads $item from ${ssrc[$item]}..."
    tshark -n -r $CAPFILE -Y "rtp.ssrc == ${ssrc[$item]}" -T fields -e rtp.payload > /tmp/pcap2wavgsm.payloads${item} 2> /dev/null
    for payload in `cat /tmp/pcap2wavgsm.payloads${item}`;do IFS=:;for byte in $payload; do printf "\\x$byte" >> ${TARGETFILE}_$item.$codec; done; done
    unset IFS
    command="${convert[$item]}"
    $command
done

# If two streams then assume they're a pair and combine them nicely
if [[ $num_streams == "2" ]]
then
    echo "Combining 2 streams into a single wav/gsm file for convenience"
    # Find shorter recording, calc time diff in samples
    samples1=`soxi -s ${TARGETFILE}_1.$TARGETCODEC`
    samples2=`soxi -s ${TARGETFILE}_2.$TARGETCODEC`

    if [[ $samples1 -gt $samples2 ]]
    then
        longer="${TARGETFILE}_1.$TARGETCODEC"
        shorter="${TARGETFILE}_2.$TARGETCODEC"
        delay=`expr $samples1 - $samples2`
    else
        longer="${TARGETFILE}_2.$TARGETCODEC"
        shorter="${TARGETFILE}_1.$TARGETCODEC"
        delay=`expr $samples2 - $samples1`
    fi

    pad="${delay}s"
    command="$SOX $shorter ${TARGETFILE}_tmp.$TARGETCODEC pad $pad 0s"
    $command

    # Create "combined" file, padding beginning with silence
    command="$SOX -m ${TARGETFILE}_tmp.$TARGETCODEC $longer ${TARGETFILE}_mixed.$TARGETCODEC"
    $command
    rm -fr ${TARGETFILE}_tmp.$TARGETCODEC

fi

if [[ $CLEAN == "true" ]]
then
    echo "Clean option"
    ZIPFILE=${TARGETFILE}.tgz
    rm -fr $ZIPFILE
    /bin/tar czf $ZIPFILE ${TARGETFILE}*$TARGETCODEC > /dev/null 2>& 1
    for item in `seq 1 $num_streams`; do
        rm -fr ${TARGETFILE}_$item.*
    done
    rm -fr $TARGETFILE.tmp
else
    echo "No clean option specified - leaving .<codec> and .gsm/.wav files on system."
fi

echo
echo "Operation complete"
echo
