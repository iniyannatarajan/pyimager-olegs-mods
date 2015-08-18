# $Id: CMakeLists.txt 16941 2010-12-13 13:59:22Z mol $

lofar_add_bin_program(CEPlogProcessor 
  CEPlogProcessorMain.cc
  CEPlogProcessor.cc)

install(FILES 
  CEPlogProcessor.conf 
  DESTINATION etc)
