#!/bin/bash


echo "OsmoNitb wird gestartet"

# Osmo-NitB starten
cd ~/openbsc/openbsc/src/osmo-nitb
sudo osmo-nitb -c openbsc.cfg -l hlr.sqlite3 -P -C --debug=DRLL:DCC:DMM:DRR:DRSL:DNM -M /tmp/bsc_mncc
