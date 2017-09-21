=======================================
EGPRS and Multi-TRX Setup and Operation
=======================================

The following applications must be built, configured, and installed for EGPRS
support using the Osmocom stack and USRP radio device.

  1. openggsn
  2. osmo-sgsn
  3. openbsc (osmo-nitb)
  4. osmo-pcu
  5. osmo-bts
  6. osmo-trx

Operational notes are below.

  1. EGPRS and Multi-TRX Build
  2. EGPRS Configuration and Run
  3. Multi-TRX Configuration and Run



----------------------------
1. EGPRS and Multi-TRX Build
----------------------------

* openggsn *

Standard install.

  $ git clone git://git.osmocom.org/openggsn
  $ cd openggsn
  $ autoreconf -i
  $ ./configure
  $ make
  $ sudo make install


* openbsc *

Standard install and includes osmo-sgsn. Make sure that dependency c-ares and
gtp and libraries are detected. Otherwise, osmo-sgsn will not be built and
installed.

  $ git clone git://git.osmocom.org/openbsc
  $ cd openbsc/openbsc/
  $ autoreconf -i
  $ ./configure
  $ make
  $ sudo make install


* osmo-bts *

Non-standard install. OsmoBTS requires the EGPRS branch, which is not yet
merged into mainline. OsmoTRX also needs to be enabled at build time using
'--enable-trx'.

  $ git clone -b ttsou/egprs git://git.osmocom.org/osmo-bts 
  $ cd osmo-bts
  $ autoreconf -i
  $ ./configure --enable-trx
  $ make
  $ sudo make install


* osmo-pcu *

Standard install.

  $ git clone git//git.osmocom.org/osmo-pcu
  $ cd osmo-pcu
  $ autoreconf -i
  $ ./configure
  $ make
  $ sudo make install


* osmo-trx *

Standard install.

  $ git clone git//git.osmocom.org/osmo-trx
  $ cd osmo-trx
  $ autoreconf -i
  $ ./configure
  $ make
  $ sudo make install




--------------------------
2. EGPRS Configure and Run
--------------------------

* openbsc *

EGPRS support needs to be enabled in the OpenBSC configuration. The following
configuration sets up 1 transceiver with 6 PDCH channels and 1 full rate TCH
channel.

  openbsc.cfg
  --------------
  ! gprs section
  gprs mode egprs

  ! trx section
  trx 0
   rf_locked 0
   arfcn 51
   nominal power 0
   max_power_red 0
   rsl e1 tei 0
    timeslot 0
     phys_chan_config CCCH+SDCCH4
     hopping enabled 0
    timeslot 1
     phys_chan_config PDCH
    timeslot 2
     phys_chan_config PDCH
    timeslot 3
     phys_chan_config PDCH
    timeslot 4
     phys_chan_config PDCH
    timeslot 5
     phys_chan_config PDCH
    timeslot 6
     phys_chan_config PDCH
    timeslot 7
     phys_chan_config TCH/F

To run OpenBSC, start the osmo-nitb application.

  $ osmo-nitb -c openbsc.cfg


* osmo-bts *

There is no EGPRS or GPRS specific configuration in OsmoBTS. Start OsmoBTS with
the configuration file.

  $ osmo-bts-trx -c osmo-bts.cfg

 
* osmo-trx *

OsmoTRX needs to be configured from the command line to enable EGPRS modulation
support. The following command enables EDGE with additional options as described
below. There is no configuration file for OsmoTRX.

  $ sudo osmo-trx -e -l INFO -g

    -e         EDGE 8-PSK support
    -l INFO    Logging level INFO
    -g         GPS frequency reference


* osmo-pcu *

OsmoPCU configuration file needs to be modified for EGPRS. The following
lines enable EGPRS and MCS-4 and MCS-9 on the downlink and uplink respectively.

  osmo-pcu.cfg
  ------------
  pcu
   egprs only
    mcs 4 9

Start OsmoPCU from the command line with the configuration file.

  $ sudo osmo-pcu osmo-pcu.cfg


* osmo-sgsn *

There is no EGPRS or GPRS specific configuration for the SGSN.

  $ osmo-sgsn -c osmo-sgsn.cfg


* openggsn *

There is no EGPRS or GPRS specific configuration for the GGSN. The '-f' and '-d'
options set foreground operation and debug output respectively.

  $ sudo /usr/local/bin/ggsn -c ggsn.conf -f -d 




----------------------------------
3. Multi-TRX Configuration and Run
----------------------------------

* openbsc *

OpenBSC configuration file needs modification for multi-TRX operation. The
following TRX configuration sets up 3 transceivers with PDCH channels and a few
full rate TCH channels.

Important:

ARFCN values for trx 1 and 2 must be exactly 4 and 8 GSM channels higher than
the base frequency on trx 0. Because all channels are multiplexed onto a single
physical RF carrier, multi-TRX spacing between channels is 800 kHz and is not
configurable.

  openbsc-mc.cfg
  --------------
  trx 0
   rf_locked 0
   arfcn 51
   nominal power 0
   max_power_red 0
   rsl e1 tei 0
    timeslot 0
     phys_chan_config CCCH+SDCCH4
     hopping enabled 0
    timeslot 1
     phys_chan_config PDCH
    timeslot 2
     phys_chan_config PDCH
    timeslot 3
     phys_chan_config PDCH
    timeslot 4
     phys_chan_config PDCH
    timeslot 5
     phys_chan_config PDCH
    timeslot 6
     phys_chan_config PDCH
    timeslot 7
     phys_chan_config PDCH
  trx 1
   rf_locked 0
   arfcn 55
   nominal power 0
   max_power_red 0
   rsl e1 tei 0
    timeslot 0
     phys_chan_config PDCH
    timeslot 1
     phys_chan_config PDCH
    timeslot 2
     phys_chan_config PDCH
    timeslot 3
     phys_chan_config PDCH
    timeslot 4
     phys_chan_config PDCH
    timeslot 5
     phys_chan_config PDCH
    timeslot 6
     phys_chan_config PDCH
    timeslot 7
     phys_chan_config TCH/F
  trx 2
   rf_locked 0
   arfcn 59
   nominal power 0
   max_power_red 0
   rsl e1 tei 0
    timeslot 0
     phys_chan_config PDCH
    timeslot 1
     phys_chan_config PDCH
    timeslot 2
     phys_chan_config PDCH
    timeslot 3
     phys_chan_config PDCH
    timeslot 4
     phys_chan_config PDCH
    timeslot 5
     phys_chan_config PDCH
    timeslot 6
     phys_chan_config PDCH
    timeslot 7
     phys_chan_config TCH/F

To run OpenBSC with multi-TRX, start the osmo-nitb application normally.

  $ osmo-nitb -c openbsc.cfg


* osmo-bts *

OsmoBTS configuration file and command line change for multi-TRX operation. In
the configuration file, note the additional phy instance and trx lines.

  osmo-bts-mc.cfg
  ---------------
  phy 0
   instance 0
   instance 1
   instance 2
   osmotrx rx-gain 25
 
  bts 0
   band 900
   ipa unit-id 1234 0
   oml remote-ip 127.0.0.1
   settsc
   gsmtap-sapi ccch
   gsmtap-sapi pdtch
   trx 0
    phy 0 instance 0
   trx 1
    phy 0 instance 1
   trx 2
    phy 0 instance 2

The number of transceiver instances must also be specified on the command line.

  $ osmo-bts-trx -c osmo-bts-mc.cfg -t 3


* osmo-trx *

OsmoTRX needs to be configured from the command line for multi-TRX operation.
The following command enables multi-TRX and EDGE with additional options as
shown below.

  $ sudo osmo-trx -m -c 3 -e -l INFO -g

    -m         Multi-TRX
    -c 3       3 ARFCN channels
    -e         EDGE 8-PSK support
    -l INFO    Logging level INFO
    -g         GPS frequency reference


* osmo-pcu *

No change from single carrier operation.


* osmo-ggsn *

No change from single carrier operation.


* openggsn *

No change from single carrier operation.
