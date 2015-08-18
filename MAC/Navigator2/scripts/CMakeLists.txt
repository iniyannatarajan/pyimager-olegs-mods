# $Id: CMakeLists.txt 23329 2012-12-13 13:51:59Z coolen $

add_subdirectory(libs)

install(FILES
  claim.ctl
  gcf_cwd.ctl
  monitorAlarms.ctl
  monitorStationAlarms.ctl
  monitorStateChanges.ctl
  monitorStateReset.ctl
  readStationConfigs.ctl
  readStationBGPconnections.ctl
  transferMPs.ctl
  DESTINATION pvss/scripts)
