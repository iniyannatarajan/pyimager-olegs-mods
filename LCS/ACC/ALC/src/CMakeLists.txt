# $Id: CMakeLists.txt 14273 2009-10-16 10:08:29Z loose $

include(LofarPackageVersion)

lofar_add_library(alc
  Package__Version.cc
  ACCmd.cc
  DH_ApplControl.cc
  ApplControlComm.cc
  ApplControlClient.cc
  ACSyncClient.cc
  ACAsyncClient.cc
  ApplControlServer.cc)

lofar_add_bin_program(versionalc versionalc.cc)
