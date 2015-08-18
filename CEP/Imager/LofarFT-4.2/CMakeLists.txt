# $Id: CMakeLists.txt 30082 2014-09-19 14:55:25Z vdtol $

lofar_package(LofarFT 0.1 DEPENDS Common ParmDB StationResponse)

include(LofarFindPackage)

lofar_find_package(Casa REQUIRED COMPONENTS synthesis)
lofar_find_package(Casacore REQUIRED COMPONENTS images msfits)
lofar_find_package(Boost REQUIRED COMPONENTS thread python system)
lofar_find_package(FFTW3 REQUIRED COMPONENTS single double threads)
lofar_find_package(Python REQUIRED)
lofar_find_package(Pyrap REQUIRED)
lofar_find_package(IDG)


# Needed for casarest
add_definitions(-DCASA_STANDALONE)

add_subdirectory(include/LofarFT)
add_subdirectory(src)
add_subdirectory(test)
