# $Id: CMakeLists.txt 17197 2011-01-26 07:00:53Z diepen $

# Create symbolic link to include directory.
execute_process(COMMAND ${CMAKE_COMMAND} -E create_symlink 
  ${CMAKE_CURRENT_SOURCE_DIR}
  ${CMAKE_BINARY_DIR}/include/${PACKAGE_NAME})

# Install header files.
install(FILES 
  PycExcp.h
  PycBasicData.h
  DESTINATION include/${PACKAGE_NAME})
