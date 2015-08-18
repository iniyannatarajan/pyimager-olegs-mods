# $Id: CMakeLists.txt 14280 2009-10-16 13:48:46Z loose $

lofar_package(AMCBase 2.0 DEPENDS Common Blob Transport)

add_subdirectory(include/AMCBase)
add_subdirectory(src)
add_subdirectory(test)
