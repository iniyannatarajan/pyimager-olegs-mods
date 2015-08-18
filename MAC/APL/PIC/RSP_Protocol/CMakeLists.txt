# $Id: CMakeLists.txt 14280 2009-10-16 13:48:46Z loose $

lofar_package(RSP_Protocol 6.0 DEPENDS Common MACIO RTCCommon)

include(LofarFindPackage)
lofar_find_package(Blitz REQUIRED)

add_subdirectory(include/APL/RSP_Protocol)
add_subdirectory(src)
add_subdirectory(test)
