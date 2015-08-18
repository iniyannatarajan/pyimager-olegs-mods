# $Id: CMakeLists.txt 14280 2009-10-16 13:48:46Z loose $

lofar_package(TestSuite 1.0 DEPENDS Common)

add_subdirectory(include/TestSuite)
add_subdirectory(src)
