# $Id: CMakeLists.txt 15241 2010-03-17 08:31:06Z overeem $

lofar_package(MD_Protocol 6.0 DEPENDS Common MACIO RTCCommon)

include(LofarFindPackage)
#lofar_find_package(Blitz REQUIRED)

add_subdirectory(include/MD_Protocol)
add_subdirectory(src)
add_subdirectory(test)
