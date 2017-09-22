#!/bin/bash


echo "OsmoNitb wird gestartet"

# Osmo-NitB starten
cd /home/mitm/openbsc/openbsc/src/osmo-nitb
osmo-nitb -c /home/mitm/openbsc/openbsc/src/osmo-nitb/openbsc.cfg -l /home/mitm/openbsc/openbsc/src/osmo-nitb/hlr.sqlite3 -P -C --debug=DRLL:DCC:DMM:DRR:DRSL:DNM -M /tmp/bsc_mncc
