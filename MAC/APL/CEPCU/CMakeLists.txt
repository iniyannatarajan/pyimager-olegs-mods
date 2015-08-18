# $Id: CMakeLists.txt 23619 2013-02-07 14:48:25Z overeem $

# Do not split the following line, otherwise makeversion will fail!
lofar_package(CEPCU 1.0 DEPENDS Common ApplCommon MACIO GCFTM GCFRTDB APLCommon RTDBCommon OTDB Stream)

include(LofarFindPackage)
lofar_find_package(Boost REQUIRED COMPONENTS date_time)

add_subdirectory(src)
add_subdirectory(test/ApplController)   # Tests currently do NOT compile 
