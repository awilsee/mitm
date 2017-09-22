#!/bin/bash


echo "GSM-Netz wird aufgespannt"


./startTransceiver

./startOsmoNitb

./startOsmoBTS






# Transceiver starten (vor der BTS starten)
#cd /home/mitm/osmo-trx
#sudo osmo-trx -f


# Osmo-NitB starten
#cd /home/mitm/openbsc/openbsc/src/osmo-nitb
#osmo-nitb -c /home/mitm/openbsc/openbsc/src/osmo-nitb/openbsc.cfg -l /home/mitm/openbsc/openbsc/src/osmo-nitb/hlr.sqlite3 -P -C --debug=DRLL:DCC:DMM:DRR:DRSL:DNM -M /tmp/bsc_mncc


# OsmoBTS starten
#cd /home/mitm/osmo-bts/src/osmo-bts-trx
#sudo osmo-bts-trx -c osmo-bts.cfg



# Asterisk starten
#sudo asterisk -r


# Wireshark starten
sudo wireshark

