#!/bin/bash

HOMEPATH=/home/all

echo "creating folder with access of all user"
sudo mkdir -p $HOMEPATH/wiresharkCalls
sudo mkdir -p $HOMEPATH/wavCalls

echo "extending permissions"
sudo chmod a=rwx $HOMEPATH
sudo chmod a=rwx $HOMEPATH/wiresharkCalls
sudo chmod a=rwx $HOMEPATH/wavCalls

echo "copying conversionScript"
cp startPcap2wavConversion.sh $HOMEPATH/.
chmod a=rwx $HOMEPATH/startPcap2wavConversion.sh

echo "getting pcap2wav"
git clone https://gist.github.com/avimar/d2e9d05e082ce273962d742eb9acac16
mv d2e9d05e082ce273962d742eb9acac16/pcap2wav $HOMEPATH/pcap2wav.sh
chmod +x $HOMEPATH/pcap2wav.sh

echo "installing pcapsipdump"
svn checkout https://svn.code.sf.net/p/pcapsipdump/code/trunk pcapsipdump-code
cd pcapsipdump-code
make
sudo make install
cd ..

echo "starting pcapsipdump"
sudo pcapsipdump -i lo -v 10 -d $HOMEPATH/wiresharkCalls/%Y%m%d-%H%M%S-%f-%t-%i.pcap -U

echo "Please install incron with:"
echo "sudo apt-get install incron"
echo ""

echo "append your username into '/etc/incron.allow'"

echo "enable incron with 'systemctl enable incrond'"
echo "starting service with 'systemctl start incron.service'"

echo "add job with 'incrontab -e' and append following line:"
echo "/home/all/wiresharkCalls IN_CREATE /home/all/startPcap2wavConversion.sh $$@ $$#"


