# $Id: CMakeLists.txt 14273 2009-10-16 10:08:29Z loose $

lofar_add_bin_program(LogProcessor LogProcessorMain.cc LogProcessor.cc)

install(FILES 
  LogProcessor.conf
  LogProcessor.log_prop
  DESTINATION etc)
