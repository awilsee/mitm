#!/bin/bash

DATE=`date "+%Y-%m-%d %H:%M:%S"`

LOGFILE=/home/all/startPcap2wavConversion.log
WAVPATH=/home/all/wavCalls


echo "$DATE script started..." >> $LOGFILE

if [ ! -d "$1" ]; then
    echo "$DATE directories '$1' does not exist!" >> $LOGFILE
fi

if [ ! -f "$1/$2" ]; then
    echo "$DATE file '$2' does not exist!" >> $LOGFILE
fi

FILENO=$(ls -l $WAVPATH | wc -l)
FILENO=$(( $FILENO - 1 ))
FILENO=$(( $FILENO / 2 ))
FILENO=$(( $FILENO + 1 ))
FILENO=$(( $FILENO % 5 ))

echo "$DATE converting pcap to wav..." >> $LOGFILE
#echo "$DATE /home/all/pcap2wav.sh -z \"$1/$2\" \"$WAVPATH/$2.wav\"" >> $LOGFILE
#/home/all/pcap2wav.sh -z "$1/$2" "$WAVPATH/$2.wav"
echo "$DATE /home/all/pcap2wav.sh -z \"$1/$2\" \"$WAVPATH/recordedCall$FILENO.wav\"" >> $LOGFILE
/home/all/pcap2wav.sh -z "$1/$2" "$WAVPATH/recordedCall$FILENO.wav"

echo "$DATE script ended..." >> $LOGFILE

echo >> $LOGFILE
