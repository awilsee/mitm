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

#store tmp fileNo
if [ ! -f "$WAVPATH/fileNo" ]; then
    echo 0 > $WAVPATH/fileNo
fi
read FILENO < ./$WAVPATH/fileNo
FILENO=$(( $FILENO + 1 ))
echo $FILENO > $WAVPATH/fileNo
FILENO=$(( $FILENO % 5 ))

#converting
echo "$DATE converting pcap to wav..." >> $LOGFILE
echo "$DATE /home/all/pcap2wavgsm.sh -z \"$1/$2\" \"$WAVPATH/recordedCall$FILENO.wav\"" >> $LOGFILE
/home/all/pcap2wavgsm.sh -z wav "$1/$2" "$WAVPATH/recordedCall$FILENO.wav"
echo "$DATE converting pcap to gsm..." >> $LOGFILE
echo "$DATE /home/all/pcap2wavgsm.sh -z \"$1/$2\" \"$GSMPATH/recordedCall$FILENO.gsm\"" >> $LOGFILE
/home/all/pcap2wavgsm.sh -z gsm "$1/$2" "$GSMPATH/recordedCall$FILENO.gsm"
echo "$DATE script ended..." >> $LOGFILE

echo >> $LOGFILE
