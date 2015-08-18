# $Id: CMakeLists.txt 18495 2011-07-14 21:43:49Z loose $

# Do not split the following line, otherwise makeversion will fail!
lofar_package(CASATools 1.0 DEPENDS Common RTCCommon)

include(LofarFindPackage)
lofar_find_package(Casacore COMPONENTS casa measures)
lofar_find_package(Blitz REQUIRED)

add_subdirectory(include/CASATools)
add_subdirectory(src)
add_subdirectory(test)
