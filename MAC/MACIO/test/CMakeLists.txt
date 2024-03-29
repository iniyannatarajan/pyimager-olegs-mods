# $Id: CMakeLists.txt 26238 2013-08-26 17:37:25Z amesfoort $

include(LofarCTest)

include(LofarFindPackage)
lofar_find_package(Boost)

include(MACAddProtocol)
mac_add_protocol(Echo_Protocol "${PACKAGE_SOURCE_DIR}/autogen")
mac_add_protocol(testprotocol "${PACKAGE_SOURCE_DIR}/autogen")
mac_add_protocol(Clone_Protocol "${PACKAGE_SOURCE_DIR}/autogen")

# Add current binary directory to -I path, so that the generated C++ header
# files can be found.
include_directories(${CMAKE_CURRENT_BINARY_DIR})

lofar_add_executable(tEventPort tEventPort.cc Echo_Protocol.cc)
lofar_add_executable(tRTmetadata tRTmetadata.cc)
#lofar_add_test(tKVTLogger tKVTLogger.cc)
lofar_add_test(tMarshalling tMarshalling.cc)
lofar_add_test(tProtocol tProtocol.cc Echo_Protocol.cc testprotocol.cc)
lofar_add_test(tClone tClone.cc Clone_Protocol.cc)

if(BUILD_TESTING)
  add_dependencies(tEventPort MACIO-Echo_Protocol)
  add_dependencies(tRTmetadata MACIO-KVT_Protocol)
  add_dependencies(tProtocol MACIO-Echo_Protocol MACIO-testprotocol)
  add_dependencies(tClone MACIO-Clone_Protocol)
endif(BUILD_TESTING)  
