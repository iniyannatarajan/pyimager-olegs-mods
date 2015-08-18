# $Id: CMakeLists.txt 14280 2009-10-16 13:48:46Z loose $

# Do not split the following line, otherwise makeversion will fail!
lofar_package(RTDBCommon 3.1 DEPENDS Common GCFPVSS GCFRTDB GCFTM MACIO)

add_subdirectory(include/APL/RTDBCommon)
add_subdirectory(src)
add_subdirectory(test)
