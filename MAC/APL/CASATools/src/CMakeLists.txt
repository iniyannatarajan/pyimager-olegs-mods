# $Id: CMakeLists.txt 18495 2011-07-14 21:43:49Z loose $

include(LofarPackageVersion)

lofar_add_library(casatools
  Package__Version.cc
  CasaConverter.cc)

lofar_add_bin_program(versioncasatools versioncasatools.cc)

