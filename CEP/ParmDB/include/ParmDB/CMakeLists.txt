# $Id: CMakeLists.txt 21603 2012-07-16 14:15:46Z diepen $

# List of header files that will be installed.
set(inst_HEADERS
  Axis.h
  AxisMapping.h
  Box.h
  Grid.h
  ParmValue.h
  ParmSet.h
  ParmMap.h
  ParmCache.h
  ParmDBMeta.h
  ParmDB.h
  ParmDBBlob.h
  ParmDBCasa.h
  ParmDBLocker.h
  Parm.h
  ParmFacadeRep.h
  ParmFacadeLocal.h
  ParmFacadeDistr.h
  ParmFacade.h
  PatchInfo.h
  SourceData.h
  SourceDB.h
  SourceDBBlob.h
  SourceDBCasa.h
  SourceInfo.h
)

# Create symbolic link to include directory.
execute_process(COMMAND ${CMAKE_COMMAND} -E create_symlink 
  ${CMAKE_CURRENT_SOURCE_DIR}
  ${CMAKE_BINARY_DIR}/include/${PACKAGE_NAME})

# Install header files.
install(FILES ${inst_HEADERS} DESTINATION include/${PACKAGE_NAME})
