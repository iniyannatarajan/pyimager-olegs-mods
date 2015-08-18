# $Id: CMakeLists.txt 29385 2014-05-28 11:41:20Z dijkema $

lofar_package(DPPP 1.0 DEPENDS Common MS AOFlagger ParmDB StationResponse)

include(LofarFindPackage)
lofar_find_package(Casacore COMPONENTS casa ms tables REQUIRED)

add_subdirectory(include/DPPP)
add_subdirectory(src)
add_subdirectory(share)
add_subdirectory(test)
