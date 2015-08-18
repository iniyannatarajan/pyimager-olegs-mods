# $Id: CMakeLists.txt 24650 2013-04-19 12:44:31Z schoenmakers $

install(FILES
  config.ccu
  config.maincu
  config.standalone.station
  config.dist.station
  config.dist_test.station
  config.level.maincu
  config.level.ccu
  config.level.station
  progs.ccu
  progs.maincu
  progs.standalone.station
  progs.dist.station
  DESTINATION pvss/config)
