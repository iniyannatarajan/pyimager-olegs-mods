# $Id: CMakeLists.txt 14273 2009-10-16 10:08:29Z loose $

install(PROGRAMS
  flash_images.sh
  restart_images.sh
  view_images.sh
  rsuctl
  rsuctl3
  rsuctl3.pl
  rsuctl3_reset
  flash_tbb.sh
  DESTINATION sbin)

install(FILES
  README.rsuctl
  DESTINATION sbin)
