#!/bin/bash


echo "SipConnector wird gestartet"

# Osmo-NitB starten
cd ~/osmo-sip-connector/
sudo osmo-sip-connector -c osmo-sip-connector.cfg
