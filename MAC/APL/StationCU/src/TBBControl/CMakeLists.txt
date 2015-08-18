# $Id: CMakeLists.txt 21149 2012-06-07 13:04:41Z loose $

lofar_add_bin_program(TBBControl 
  TBBControlMain.cc
  TBBControl.cc
  TBBObservation.cc)

lofar_add_bin_program(trigctl 
  trigctl.cc)

install(FILES
  TBBControl.conf
  DESTINATION etc)

