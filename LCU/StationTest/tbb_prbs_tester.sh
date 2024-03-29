#!/bin/bash

#
# Test the LVDS interfaces between RCU -> RSP -> TBB using the Pseudo Random generator in the RCUs.
#
# Modified for INT station 14-10-2010 M.J.Norden


let rspboards=`sed -n  's/^\s*RS\.N_RSPBOARDS\s*=\s*\([0-9][0-9]*\).*$/\1/p' /opt/lofar/etc/RemoteStation.conf`
let tbboards=`sed -n  's/^\s*RS\.N_TBBOARDS\s*=\s*\([0-9][0-9]*\).*$/\1/p' /opt/lofar/etc/RemoteStation.conf`
let nof_rcu=8*$rspboards

rm -f prbs_dir*.log
rm -f prbs_dir*.diff
rm -f ./prbs/*.*
rm -r ./prbs/.svn


# Set up RCU and RSP, make sure waveform generator is off
rspctl --rcuprsg=1
sleep 2
rspctl --tbbmode=transient
sleep 1
rspctl --rcuenable=1

sleep 5
# set up TBB
nof_slices=10   # one slice contains 1024 transient (raw data) samples

tbbctl --free
tbbctl --alloc
tbbctl --rec

sleep 1

# Freeze and get the captured data from TBB
cd ./prbs
tbbctl --stop
for ((i = 0; i < $nof_rcu; i++)) do
  tbbctl --readpage=$i,0,$nof_slices
done
cd ..
# Verify the PRBS
python prbs_dir_test.py
rspctl --rcuprsg=0

if [ $tbboards == 6 ]; then
     # This is a NL station
     diff prbs_dir_test.log ./gold/prbs_dir_test.gold > prbs_dir_test.diff
     if [ -e prbs_dir_test.log ] && [ -e ./gold/prbs_dir_test.gold ] && [ -e prbs_dir_test.diff ] && ! [ -s prbs_dir_test.diff ]; then
     # The files exists AND has the diff size 0
         echo "RCU -> RSP -> TBB interfaces test went OK"
     else
         echo "RCU -> RSP -> TBB interfaces test went wrong"
     fi
else
     # This is a INT station
     diff prbs_dir_test.log ./gold/prbs_dir_test_int.gold > prbs_dir_test_int.diff
     if [ -e prbs_dir_test.log ] && [ -e ./gold/prbs_dir_test_int.gold ] && [ -e prbs_dir_test_int.diff ] && ! [ -s prbs_dir_test_int.diff ]; then
     # The files exists AND has the diff size 0
         echo "RCU -> RSP -> TBB interfaces test went OK"
     else
         echo "RCU -> RSP -> TBB interfaces test went wrong"
     fi
fi


