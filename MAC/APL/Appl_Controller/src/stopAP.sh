# stopAP.sh nodename procID 
#
# nodename		    hostname[.domain]
# procID			processname<nr>
#
# Stops the given process by killing the process whose pid is in the
# proces.pid file.

# DISABLED this script: startBGL.sh starts all CEP processes
exit

echo -n "Killing process "; cat /opt/lofar/var/run/$2.pid
kill -9 `cat /opt/lofar/var/run/$2.pid`
rm -f /opt/lofar/var/run/$2.pid /opt/lofar/var/run/$2.parset