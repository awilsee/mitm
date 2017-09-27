#!/bin/bash


echo "OsmoBTS wird gestartet"

# OsmoBTS starten
cd /home/mitm/osmo-bts/src/osmo-bts-trx
sudo osmo-bts-trx -c osmo-bts.cfg
