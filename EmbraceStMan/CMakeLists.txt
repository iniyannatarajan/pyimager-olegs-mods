# $Id: CMakeLists.txt 21648 2012-07-19 13:47:13Z diepen $

lofar_package(EmbraceStMan 1.0 DEPENDS Common)

include(LofarFindPackage)
lofar_find_package(Casacore COMPONENTS casa measures tables REQUIRED)

add_subdirectory(include/EmbraceStMan)
add_subdirectory(src)
add_subdirectory(test)
