# $Id: CMakeLists.txt 26238 2013-08-26 17:37:25Z amesfoort $

include(LofarPackageVersion)

## ---------------------------------------------------------------------------
## Add MAC protocols (generates a .ph and .cc file from a .prot file)
## ---------------------------------------------------------------------------
include(MACAddProtocol)
mac_add_protocol(LOG_Protocol "${PACKAGE_SOURCE_DIR}/autogen")
mac_add_protocol(KVT_Protocol "${PACKAGE_SOURCE_DIR}/autogen")
mac_add_protocol(SB_Protocol  "${PACKAGE_SOURCE_DIR}/autogen")

## ---------------------------------------------------------------------------
## Add libraries to be generated
## ---------------------------------------------------------------------------
lofar_add_library(log_protocol LOG_Protocol.cc)
lofar_add_library(kvt_protocol KVT_Protocol.cc)
lofar_add_library(macio 
  Package__Version.cc
  GCF_Event.cc
  EventPort.cc
  #KVTLogger.cc
  KVT_Protocol.cc
  RTmetadata.cc
  ProtocolDefs.cc
  SB_Protocol.cc)

add_dependencies(log_protocol MACIO-LOG_Protocol)
add_dependencies(kvt_protocol MACIO-KVT_Protocol)
add_dependencies(macio MACIO-KVT_Protocol MACIO-SB_Protocol)

## ---------------------------------------------------------------------------
## Add executables to be generated
## ---------------------------------------------------------------------------
lofar_add_bin_program(versionmacio versionmacio.cc)
