# $Id: CMakeLists.txt 18364 2011-06-30 15:00:24Z mol $

include(LofarPackageVersion)

# Create symbolic link in binary include directory to current directory.
execute_process(COMMAND ${CMAKE_COMMAND} -E create_symlink
  ${CMAKE_CURRENT_SOURCE_DIR}
  ${CMAKE_BINARY_DIR}/include/CUDaemons)

lofar_add_library(cudaemons Package__Version.cc)

lofar_add_bin_program(versioncudaemons versioncudaemons.cc)

add_subdirectory(CTStartDaemon)
add_subdirectory(ServiceBroker)
