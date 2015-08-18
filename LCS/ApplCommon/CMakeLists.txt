# $Id: CMakeLists.txt 17851 2011-04-26 09:58:48Z diepen $

lofar_package(ApplCommon 3.1 DEPENDS Common)

include(LofarFindPackage)
lofar_find_package(Boost COMPONENTS date_time regex)

add_subdirectory(include/ApplCommon)
add_subdirectory(src)
add_subdirectory(test)
