# $Id: CMakeLists.txt 14273 2009-10-16 10:08:29Z loose $

# Add path to generated ClockProtocol files to -I path.
include_directories(${PACKAGE_BINARY_DIR}/src/ClockProtocol)

lofar_add_bin_program(StationControl 
  StationControlMain.cc 
  StationControl.cc
  ActiveObs.cc)

target_link_libraries(StationControl clock_protocol)

configure_file(
  ${CMAKE_CURRENT_SOURCE_DIR}/StationControl.conf.in
  ${CMAKE_CURRENT_BINARY_DIR}/StationControl.conf)

install(FILES
  ${CMAKE_CURRENT_BINARY_DIR}/StationControl.conf
  DESTINATION etc)

