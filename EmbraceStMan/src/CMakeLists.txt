# $Id: CMakeLists.txt 21648 2012-07-19 13:47:13Z diepen $

include(LofarPackageVersion)

lofar_add_library(embracestman
  Package__Version.cc
  EmbraceStMan.cc
  EmbraceColumn.cc
  Register.cc
  )

lofar_add_bin_program(versionembracestman versionembracestman.cc)
lofar_add_bin_program(makemsembrace makemsembrace.cc)

