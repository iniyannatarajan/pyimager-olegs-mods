# $Id: CMakeLists.txt 22135 2012-09-25 12:33:14Z loose $

include(LofarCTest)

# Create symbolic links to scripts used by the tmakems test script.
get_target_property(_loc getparsetvalue LOCATION)
execute_process(COMMAND ${CMAKE_COMMAND} -E create_symlink
  ${_loc}
  ${CMAKE_CURRENT_BINARY_DIR}/getparsetvalue)
get_target_property(_loc finddproc LOCATION)
execute_process(COMMAND ${CMAKE_COMMAND} -E create_symlink
  ${_loc}
  ${CMAKE_CURRENT_BINARY_DIR}/finddproc)
execute_process(COMMAND ${CMAKE_COMMAND} -E create_symlink
  ${LMWCommon_SOURCE_DIR}/src/startdistproc
  ${CMAKE_CURRENT_BINARY_DIR}/startdistproc)
execute_process(COMMAND ${CMAKE_COMMAND} -E create_symlink
  ${LMWCommon_SOURCE_DIR}/src/socketrun
  ${CMAKE_CURRENT_BINARY_DIR}/socketrun)

lofar_add_test(tMSSplit tMSSplit.cc)
lofar_add_test(tBaselineSelect tBaselineSelect.cc)
lofar_add_test(tVdsMaker tVdsMaker.cc DEPENDS combinevds)
lofar_add_test(tcombinevds DEPENDS combinevds)
lofar_add_test(tmakems 
  DEPENDS makems getparsetvalue finddproc startdistproc socketrun)
