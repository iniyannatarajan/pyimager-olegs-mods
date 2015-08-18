# $Id: CMakeLists.txt 25638 2013-07-12 06:15:48Z overeem $

include(LofarCTest)

lofar_add_test(tMarshallBlitz tMarshallBlitz.cc)
lofar_add_test(tBlitz tBlitz.cc)
lofar_add_test(tTimestamp tTimestamp.cc)
