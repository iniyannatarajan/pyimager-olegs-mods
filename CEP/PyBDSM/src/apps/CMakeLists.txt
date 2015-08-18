# $Id: CMakeLists.txt 20828 2012-05-02 11:24:10Z loose $

configure_file(
  ${CMAKE_CURRENT_SOURCE_DIR}/pybdsm.in
  ${CMAKE_CURRENT_BINARY_DIR}/pybdsm @ONLY)

install(PROGRAMS 
  ${CMAKE_CURRENT_BINARY_DIR}/pybdsm
  DESTINATION bin)
  
