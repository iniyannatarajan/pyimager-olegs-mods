# $Id: CMakeLists.txt 23688 2013-02-12 11:04:05Z schoenmakers $

lofar_package(OTDB_SQL 1.0)
install(PROGRAMS
  fresh_database
DESTINATION sbin)

file(GLOB otdb_sql_files
  *.sql)
install(FILES
  ${otdb_sql_files}
  update_all_functions.sh
  DESTINATION sbin/sql)

