# $Id: CMakeLists.txt 18492 2011-07-14 21:07:51Z loose $

include(LofarPackageVersion)

# Create symbolic link in binary include directory to current directory.
execute_process(COMMAND ${CMAKE_COMMAND} -E create_symlink
  ${CMAKE_CURRENT_SOURCE_DIR}
  ${CMAKE_BINARY_DIR}/include/${PACKAGE_NAME})

# Add MAC protocols (generates a .ph and .cc file from a .prot file)
include(MACAddProtocol)
mac_add_protocol(SHM_Protocol "${MACIO_SOURCE_DIR}/autogen")

# Add the directory where the generated C++ headers are stored to the -I path.
include_directories(${PACKAGE_BINARY_DIR}/src)

# Add the current source directory to the -I path.
include_directories(${CMAKE_CURRENT_SOURCE_DIR})

lofar_add_library(shminfoserver
  Package__Version.cc
  SHMInfoServer.cc
  SHMSession.cc
  SHM_Protocol.cc
  XCStatistics.cc
  RspStatus.cc)
add_dependencies(shminfoserver SHMInfo_Server-SHM_Protocol)

lofar_add_bin_program(versionshminfo_server versionshminfo_server.cc)
lofar_add_bin_program(SHMInfoServer SHMInfoServerMain.cc)
