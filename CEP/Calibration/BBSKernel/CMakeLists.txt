# $Id: CMakeLists.txt 29120 2014-05-02 11:07:08Z dijkema $

lofar_package(BBSKernel 1.0 DEPENDS Blob Common ParmDB StationResponse)

include(LofarFindPackage)
lofar_find_package(Boost REQUIRED)
lofar_find_package(Casacore REQUIRED COMPONENTS casa measures ms scimath tables)

# Uncomment to check for unsafe conversions (gcc), for example conversion of
# size_t to unsigned int (truncation).
#add_definitions(-Wconversion)

# Uncomment to enable timing of (classes of) expression tree nodes. NB. Only
# enable if necessary, timing incurs an overhead of its own.
#add_definitions(-DLOFAR_BBSKERNEL_EXPR_TIMER)

add_subdirectory(include/BBSKernel)
add_subdirectory(src)
add_subdirectory(test)
