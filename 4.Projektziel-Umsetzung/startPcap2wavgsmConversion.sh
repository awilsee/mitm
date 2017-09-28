#!/bin/bash

DATE=""
datum() {
    DATE=`date "+%Y-%m-%d %H:%M:%S"`
}

#test if another script is running and wait
while test `ps -e | grep startPcap2wavgs | wc -l > 2`
do
    sleep 1
done

LOGFILE=/home/all/startPcap2wavgsmConversion.log
GSMPATH=/home/all/gsmCalls
WAVPATH=/home/all/wavCalls

datum
echo "$DATE script started..." >> $LOGFILE

#check dir and file
if [ ! -d "$1" ]; then
    datum
    echo "$DATE directories '$1' does not exist!" >> $LOGFILE
fi
if [ ! -f "$1/$2" ]; then
    datum
    echo "$DATE file '$2' does not exist!" >> $LOGFILE
fi

#read calling numbers out of filenames
number_A="$(cut -d'-' -f3 <<<"$2")"
number_B="$(cut -d'-' -f4 <<<"$2")"

#filter numbers of slots
if [ "$number_B" = "000001" ] || [ "$number_B" = "000002" ] || [ "$number_B" = "000003" ] || [ "$number_B" = "000004" ] || [ "$number_B" = "000005" ]; then
    exit 1
fi

#exit if no slots
if [ ! -f "/home/all/slots" ]; then
    datum
    echo "$DATE No slots reserved!" >> $LOGFILE
    exit 1
fi

#check if calling numbers have a slot and convert calls to wav/gsm
while read -r line
do
    if [ "$number_A" = "$(cut -d'=' -f1 <<<"$line")" ] || [ "$number_B" = "$(cut -d'=' -f1 <<<"$line")" ]; then
        datum
        echo "$DATE converting pcap to wav..." >> $LOGFILE
        datum
        echo "$DATE /home/all/pcap2wavgsm.sh -z wav \"$1/$2\" \"$WAVPATH/recordedCall$(cut -d'=' -f2 <<<"$line").wav\"" >> $LOGFILE
        /home/all/pcap2wavgsm.sh -z wav "$1/$2" "$WAVPATH/recordedCall$(cut -d'=' -f2 <<<"$line").wav"
        datum
        echo "$DATE converting pcap to gsm..." >> $LOGFILE
        datum
        echo "$DATE /home/all/pcap2wavgsm.sh -z gsm \"$1/$2\" \"$GSMPATH/recordedCall$(cut -d'=' -f2 <<<"$line").gsm\"" >> $LOGFILE
        /home/all/pcap2wavgsm.sh -z gsm "$1/$2" "$GSMPATH/recordedCall$(cut -d'=' -f2 <<<"$line").gsm"
        datum
        echo "$DATE script ended..." >> $LOGFILE
        echo >> $LOGFILE
    fi
done < /home/all/slots
