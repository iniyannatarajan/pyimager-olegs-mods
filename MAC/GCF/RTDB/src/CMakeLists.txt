# $Id: CMakeLists.txt 21149 2012-06-07 13:04:41Z loose $

include(LofarPackageVersion)

# Extra preprocessor definitions
add_definitions(-DUSES_NEW_IOSTREAMS)

# Add MAC protocols (generates a .ph and .cc file from a .prot file)
include(MACAddProtocol)
mac_add_protocol(DP_Protocol "${MACIO_SOURCE_DIR}/autogen")

lofar_add_library(gcfrtdb
  Package__Version.cc
  DP_Protocol.cc
  RTDB_PropertySet.cc
  DPservice.cc
  DPanswer.cc
  GCF_RTDBPort.cc)
add_dependencies(gcfrtdb GCFRTDB-DP_Protocol)

lofar_add_bin_program(versiongcfrtdb versiongcfrtdb.cc)
