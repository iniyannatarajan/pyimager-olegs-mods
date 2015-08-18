# $Id: CMakeLists.txt 14280 2009-10-16 13:48:46Z loose $

lofar_package(GCFRTDB 1.0 DEPENDS Common GCFPVSS GCFTM MACIO)

add_subdirectory(include/GCF/RTDB)
add_subdirectory(src)
add_subdirectory(test)
