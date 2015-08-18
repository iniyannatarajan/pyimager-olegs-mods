# $Id: CMakeLists.txt 22948 2012-11-23 08:54:47Z loose $

lofar_package(Pipeline-MAC 0.1 DEPENDS APLCommon MACIO)

lofar_find_package(Boost REQUIRED COMPONENTS python)
lofar_find_package(Python 2.6 REQUIRED)

add_subdirectory(src)
add_subdirectory(ep)

#add_subdirectory(test)
