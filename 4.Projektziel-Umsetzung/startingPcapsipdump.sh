#!/bin/bash

#check if script called with root privileges
if [ `id -u` != 0 ];then
    echo "You have to start this script with root privileges"
    exit 1
fi

HOMEPATH=$1

if [[ $HOMEPATH == "" ]]
then
	HOMEPATH=/home/all
fi

echo ">>starting pcapsipdump if not already started"
if ! pgrep -x "pcapsipdump" > /dev/null
then
	sudo pcapsipdump -i lo -v 10 -d $HOMEPATH/wiresharkCalls/%Y%m%d-%H%M%S-%f-%t-%i.pcap -U
fi

