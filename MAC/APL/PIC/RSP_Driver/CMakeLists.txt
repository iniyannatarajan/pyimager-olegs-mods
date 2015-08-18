# $Id: CMakeLists.txt 14462 2009-11-16 12:57:29Z schoenmakers $

# Do not split the following line, otherwise makeversion will fail!
lofar_package(RSP_Driver 6.0 DEPENDS ApplCommon Common TestSuite GCFTM MACIO RTCCommon RSP_Protocol)

include(LofarFindPackage)
lofar_find_package(Boost REQUIRED)
lofar_find_package(Blitz REQUIRED)

add_subdirectory(src)
add_subdirectory(test)
