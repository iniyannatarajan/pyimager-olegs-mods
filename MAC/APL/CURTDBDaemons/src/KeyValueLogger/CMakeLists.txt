# $Id: CMakeLists.txt 14273 2009-10-16 10:08:29Z loose $

lofar_add_bin_program(KeyValueLogger KeyValueLoggerMain.cc KeyValueLogger.cc)

install(FILES KeyValueLogger.conf DESTINATION etc)
