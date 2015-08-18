# $Id: CMakeLists.txt 14280 2009-10-16 13:48:46Z loose $

lofar_package(TBB_Protocol 1.0 DEPENDS MACIO)

add_subdirectory(include/APL/TBB_Protocol)
add_subdirectory(src)
