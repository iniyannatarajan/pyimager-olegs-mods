# $Id: CMakeLists.txt 23457 2013-01-07 16:24:03Z loose $

lofar_package(checkhardware 1.0)

# Install files matching regex pattern in current directory and below
install(DIRECTORY . 
  DESTINATION stationtest
  USE_SOURCE_PERMISSIONS
  FILES_MATCHING REGEX "(README\\.txt|\\.(gold|m|py|sh|conf))$"
  PATTERN ".svn" EXCLUDE)
