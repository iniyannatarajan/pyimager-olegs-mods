# $Id: CMakeLists.txt 14280 2009-10-16 13:48:46Z loose $

lofar_package(RTCCommon 6.0 DEPENDS Common)

include(LofarFindPackage)
lofar_find_package(Blitz REQUIRED)

add_subdirectory(include/APL/RTCCommon)
add_subdirectory(src)
add_subdirectory(test)
