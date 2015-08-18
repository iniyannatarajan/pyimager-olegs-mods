# $Id: CMakeLists.txt 14273 2009-10-16 10:08:29Z loose $

include(LofarPackageVersion)

lofar_add_library(amcbase
  Package__Version.cc
  BlobIO.cc
  ConverterClient.cc
  ConverterCommand.cc
  ConverterStatus.cc
  Coord3D.cc
  DH_Request.cc
  DH_Result.cc
  Direction.cc
  Epoch.cc
  Position.cc)

lofar_add_bin_program(versionamcbase versionamcbase.cc)
