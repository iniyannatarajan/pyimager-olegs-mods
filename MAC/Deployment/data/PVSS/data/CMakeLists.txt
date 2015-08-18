# $Id: CMakeLists.txt 21564 2012-07-12 09:59:30Z schoenmakers $

file(GLOB pvss_dp_data
  PVSSDataPoints.base
  CtrlDebug.dpl
  *.dpdef
  *.list)
install(FILES
  ${pvss_dp_data}
  DESTINATION pvss/dpdef)
