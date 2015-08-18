# $Id: CMakeLists.txt 25962 2013-08-07 10:19:39Z schoenmakers $

# All env. control python scripts and libs to sbin 
file (GLOB ecfiles *.py)
install(PROGRAMS
  ${ecfiles}
  DESTINATION sbin)

install(PROGRAMS poweruphba.sh DESTINATION sbin)
