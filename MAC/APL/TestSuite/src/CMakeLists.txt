# $Id: CMakeLists.txt 14273 2009-10-16 10:08:29Z loose $

include(LofarPackageVersion)

lofar_add_library(testsuite 
  Package__Version.cc
  suite.cpp
  test.cpp)

lofar_add_bin_program(versiontestsuite versiontestsuite.cc)
