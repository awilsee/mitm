#!/bin/bash

HOMEPATH=/home/all

echo ">>creating folder with access of all user"
sudo mkdir -p $HOMEPATH/wiresharkCalls
sudo mkdir -p $HOMEPATH/wavCalls
sudo mkdir -p $HOMEPATH/gsmCalls
echo ""

echo ">>extending permissions"
sudo chmod a=rwx $HOMEPATH
sudo chmod a=rwx $HOMEPATH/wiresharkCalls
sudo chmod a=rwx $HOMEPATH/wavCalls
sudo chmod a=rwx $HOMEPATH/gsmCalls
echo ""

echo ">>copying conversionScript"
cp startPcap2wavgsmConversion.sh $HOMEPATH/.
chmod a=rwx $HOMEPATH/startPcap2wavgsmConversion.sh
echo ""

echo ">>getting pcap2wav"
git clone https://gist.github.com/avimar/d2e9d05e082ce273962d742eb9acac16
cp d2e9d05e082ce273962d742eb9acac16/pcap2wav $HOMEPATH/pcap2wav.sh
chmod a=rwx $HOMEPATH/pcap2wav.sh
echo ""

echo ">>checking dependencies "
if ! which "tshark" > /dev/null
then
	sudo apt-get install -y tshark sox
fi
echo ""

echo ">>installing pcapsipdump"
if ! which "svn" > /dev/null
then
	sudo apt-get install -y subversion
fi
svn checkout https://svn.code.sf.net/p/pcapsipdump/code/trunk pcapsipdump-code
cd pcapsipdump-code
make
sudo make install
cd ..
echo ""

echo ">>starting pcapsipdump if not already started"
if ! pgrep -x "pcapsipdump" > /dev/null
then
	sudo pcapsipdump -i lo -v 10 -d $HOMEPATH/wiresharkCalls/%Y%m%d-%H%M%S-%f-%t-%i.pcap -U
fi
echo ""

echo ">>installing incron if not already installed.."
if ! which "incrond" > /dev/null
then
	sudo apt-get install -y incron
fi
echo ""
echo ""

echo ">>YOU have manually to do that:"
echo ">>append your username into '/etc/incron.allow'"

echo ">>starting service with 'systemctl start incron.service'"

echo ">>add job with 'incrontab -e' and append following line:"
echo "/home/all/wiresharkCalls IN_CREATE /home/all/startPcap2wavConversion.sh \$@ \$#"
echo ""

