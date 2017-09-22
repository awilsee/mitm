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
cp pcap2wavgsm.sh $HOMEPATH/.
chmod a=rwx $HOMEPATH/pcap2wavgsm.sh
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

sudo chmod +x startingPcapsipdump.sh
./startingPcapsipdump.sh $HOMEPATH

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
echo "/home/all/wiresharkCalls IN_CREATE /home/all/startPcap2wavgsmConversion.sh \$@ \$#"
echo ""

