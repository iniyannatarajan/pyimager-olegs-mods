# $Id: CMakeLists.txt 14273 2009-10-16 10:08:29Z loose $

include(LofarCTest)

# Extra preprocessor definitions
add_definitions(-DUSES_NEW_IOSTREAMS)

# Add the directory where the generated C++ headers are stored to the -I path.
include_directories(${PACKAGE_BINARY_DIR}/src)

lofar_add_test(tRTDButilities tRTDButilities.cc)
lofar_add_test(tClaimManager tClaimManager.cc)
