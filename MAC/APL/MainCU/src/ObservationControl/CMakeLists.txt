# $Id: CMakeLists.txt 23999 2013-02-28 14:51:18Z overeem $

lofar_add_bin_program(ObservationControl
  ObservationControlMain.cc
  ObservationControl.cc)

configure_file(
  ${CMAKE_CURRENT_SOURCE_DIR}/ObservationControl.conf.in
  ${CMAKE_CURRENT_BINARY_DIR}/ObservationControl.conf)

install(FILES
  ${CMAKE_CURRENT_BINARY_DIR}/ObservationControl.conf
  DESTINATION etc)
