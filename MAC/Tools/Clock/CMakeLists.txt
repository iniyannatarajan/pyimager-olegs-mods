# $Id: CMakeLists.txt 14273 2009-10-16 10:08:29Z loose $

if(HAVE_SYS_TIMEPPS_H)
  lofar_add_sbin_program(ppsctl ppsctl.c)
endif(HAVE_SYS_TIMEPPS_H)

install(PROGRAMS plotclock DESTINATION sbin)
