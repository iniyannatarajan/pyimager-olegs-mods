# $Id: CMakeLists.txt 23213 2012-12-07 13:00:09Z loose $

lofar_package(APLCommon 3.1 DEPENDS Common ApplCommon GCFTM MACIO)

include(LofarFindPackage)
lofar_find_package(Blitz REQUIRED)
lofar_find_package(Boost REQUIRED COMPONENTS date_time)

add_definitions(-DBOOST_DISABLE_THREADS)

add_subdirectory(include/APL/APLCommon)
add_subdirectory(src)
add_subdirectory(test)
