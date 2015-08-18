# $Id: CMakeLists.txt 23213 2012-12-07 13:00:09Z loose $

lofar_package(TestCtlr 1.0 DEPENDS Common ApplCommon APLCommon MACIO GCFTM)

include(LofarFindPackage)
lofar_find_package(Boost REQUIRED date_time)

add_definitions(-DBOOST_DISABLE_THREADS)

add_subdirectory(src)
