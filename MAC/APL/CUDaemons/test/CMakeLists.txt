# $Id: CMakeLists.txt 14273 2009-10-16 10:08:29Z loose $

include(LofarCTest)

lofar_add_test(LDtestMenu LDtestMenu.cc EventPort.cc)
lofar_add_test(ObservationControl dummyLD.cc)
lofar_add_test(tLogClient tLogClient.cc)
