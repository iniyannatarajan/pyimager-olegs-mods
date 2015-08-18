# $Id: CMakeLists.txt 17192 2011-01-25 12:04:52Z overeem $

lofar_package(GCFTM 6.1 DEPENDS Common MACIO)

include(LofarFindPackage)
lofar_find_package(Boost)

add_subdirectory(include/GCF/TM)
add_subdirectory(src)
add_subdirectory(src/TestFramework)
add_subdirectory(test)
