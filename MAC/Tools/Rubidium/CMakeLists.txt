# $Id: CMakeLists.txt 18495 2011-07-14 21:43:49Z loose $

lofar_add_sbin_program(tci tci.c)

install(PROGRAMS 
  plotrubidium 
  filter.py 
  rr.py 
  rubidium_logger.py 
  rlp.py 
  DESTINATION sbin)

