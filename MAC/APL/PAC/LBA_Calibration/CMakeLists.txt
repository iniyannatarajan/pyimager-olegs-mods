# $Id: CMakeLists.txt 18494 2011-07-14 21:39:24Z loose $

lofar_package(LBA_Calibration 1.0 DEPENDS Common)

include(LofarFindPackage)
lofar_find_package(Matlab REQUIRED)

add_subdirectory(src)
add_subdirectory(test)
