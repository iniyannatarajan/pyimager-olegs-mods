# $Id: CMakeLists.txt 23467 2013-01-09 13:41:24Z loose $

include(LofarPackageVersion)
include(PythonInstall)

lofar_add_library(lofarft
  Package__Version.cc
  FFTCMatrix.cc
  LofarATerm.cc
  LofarATermOld.cc
  LofarConvolutionFunction.cc
  LofarConvolutionFunctionOld.cc
  LofarImager.cc
  LofarCFStore.cc
  LofarFTMachine.cc
  LofarFTMachineOld.cc
  LofarWTerm.cc
#  LofarVisibilityResamplerBase.cc
  LofarVisResampler.cc
  LofarVisResamplerOld.cc
  LofarCubeSkyEquation.cc
)

lofar_add_bin_program(versionlofarft versionlofarft.cc)
lofar_add_bin_program(awimager awimager.cc)
lofar_add_bin_program(makefftwisdom2d makefftwisdom2d.cc)
lofar_add_bin_program(fillRootImageGroup fillRootImageGroup.cc)
lofar_add_bin_program(makebeamimage makebeamimage.cc)

install(PROGRAMS
  addImagingInfo
  DESTINATION bin)

# Python modules.
python_install(
  addImagingInfo.py 
  get_rms_noise.py
  DESTINATION lofar)
  
# Suppress compiler warnings from casarest by disabling them for some sources
set_source_files_properties(
  LofarCubeSkyEquation.cc
  LofarFTMachine.cc
  LofarFTMachineOld.cc
  LofarImager.cc
  LofarVisResampler.cc
  LofarVisResamplerOld.cc
  awimager.cc
  PROPERTIES COMPILE_FLAGS
    "-Wno-extra -Wno-ignored-qualifiers -Wno-overloaded-virtual -Wno-unused"
)

