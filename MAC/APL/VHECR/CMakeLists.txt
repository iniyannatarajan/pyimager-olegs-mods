# $Id: CMakeLists.txt 21696 2012-07-26 10:49:50Z loose $

lofar_package(VHECR 1.0 DEPENDS Common ApplCommon APLCommon)

include(LofarFindPackage)
lofar_find_package(Boost REQUIRED COMPONENTS date_time program_options)

##add_definitions(-DBOOST_DISABLE_THREADS)

add_subdirectory(include/VHECR)
add_subdirectory(src)
add_subdirectory(test)
