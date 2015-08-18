# $Id: CMakeLists.txt 14280 2009-10-16 13:48:46Z loose $

lofar_package(GCFPVSS 1.0 DEPENDS Common GCFTM)

include(LofarFindPackage)
lofar_find_package(PVSS REQUIRED)

add_subdirectory(include/GCF/PVSS)
add_subdirectory(src)
add_subdirectory(test)
