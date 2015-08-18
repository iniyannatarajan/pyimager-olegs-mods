# $Id: CMakeLists.txt 23213 2012-12-07 13:00:09Z loose $

lofar_package(Stream 0.1 DEPENDS Common)

include(LofarFindPackage)
lofar_find_package(Boost REQUIRED)

add_subdirectory(include/Stream)
add_subdirectory(src)
add_subdirectory(test)
