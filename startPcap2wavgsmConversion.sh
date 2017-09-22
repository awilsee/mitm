#!/bin/bash

DATE=`date "+%Y-%m-%d %H:%M:%S"`

LOGFILE=/home/all/startPcap2wavgsmConversion.log
GSMPATH=/home/all/gsmCalls
WAVPATH=/home/all/wavCalls


echo "$DATE script started..." >> $LOGFILE

#check dir and file
if [ ! -d "$1" ]; then
    echo "$DATE directories '$1' does not exist!" >> $LOGFILE
fi
if [ ! -f "$1/$2" ]; then
    echo "$DATE file '$2' does not exist!" >> $LOGFILE
fi

fileName=(`echo $2 | tr '@' ' '`)
if test "$2" != "$fileName"
then
	exit 1
fi

#store tmp fileNo
if [ ! -f "/home/all/fileNo" ]; then
    echo 0 > /home/all/fileNo
fi
read FILENO < ./home/all/fileNo
FILENO=$(( $FILENO + 1 ))
echo $FILENO > /home/all/fileNo
FILENO=$(( $FILENO % 5 ))

#converting
echo "$DATE converting pcap to wav..." >> $LOGFILE
echo "$DATE /home/all/pcap2wavgsm.sh -z wav \"$1/$2\" \"$WAVPATH/recordedCall$FILENO.wav\"" >> $LOGFILE
/home/all/pcap2wavgsm.sh -z wav "$1/$2" "$WAVPATH/recordedCall$FILENO.wav"
echo "$DATE converting pcap to gsm..." >> $LOGFILE
echo "$DATE /home/all/pcap2wavgsm.sh -z gsm \"$1/$2\" \"$GSMPATH/recordedCall$FILENO.gsm\"" >> $LOGFILE
/home/all/pcap2wavgsm.sh -z gsm "$1/$2" "$GSMPATH/recordedCall$FILENO.gsm"
echo "$DATE script ended..." >> $LOGFILE

echo >> $LOGFILE
