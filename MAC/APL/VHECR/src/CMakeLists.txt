# $Id: CMakeLists.txt 16182 2010-08-18 08:29:47Z donker $

include(LofarPackageVersion)

set(vhecr_LIB_SRCS
  Package__Version.cc
  VHECRTask.cc
  VHECRsettings.cc
  TBBTrigger.cc
  TBBReadCmd.cc)

set(vhecr_PROGRAMS
  versionvhecr
)

lofar_add_library(vhecr ${vhecr_LIB_SRCS})

foreach(prog ${vhecr_PROGRAMS})
  lofar_add_bin_program(${prog} ${prog}.cc)
endforeach(prog ${vhecr_PROGRAMS})
