# $Id: CMakeLists.txt 14280 2009-10-16 13:48:46Z loose $

lofar_package(ALC 2.1 DEPENDS Common Blob Transport)

add_subdirectory(include/ALC)
add_subdirectory(src)
add_subdirectory(test)
