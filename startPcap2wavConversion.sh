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


echo "$DATE converting pcap to wav..." >> $LOGFILE
#echo "$DATE /home/all/pcap2wav.sh -z \"$1/$2\" \"$WAVPATH/$2.wav\"" >> $LOGFILE
#/home/all/pcap2wav.sh -z "$1/$2" "$WAVPATH/$2.wav"
echo "$DATE /home/all/pcap2wav.sh -z \"$1/$2\" \"$WAVPATH/recordedCall.wav\"" >> $LOGFILE
/home/all/pcap2wav.sh -z "$1/$2" "$WAVPATH/recordedCall.wav"
echo "$DATE script ended..." >> $LOGFILE

echo >> $LOGFILE
