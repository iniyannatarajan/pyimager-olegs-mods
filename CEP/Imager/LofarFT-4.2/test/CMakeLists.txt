# $Id: CMakeLists.txt 30082 2014-09-19 14:55:25Z vdtol $

include(LofarCTest)

# lofar_add_test(tfftw tfftw.cc)
lofar_add_test(tFFTCMatrix tFFTCMatrix.cc)
# lofar_add_test(tLofarVisResampler tLofarVisResampler.cc)
#lofar_add_test(tLofarConvolutionFunction tLofarConvolutionFunction.cc)

# Suppress compiler warnings from casarest by disabling them for some sources
set_source_files_properties(
  tLofarVisResampler.cc
  PROPERTIES COMPILE_FLAGS "-Wno-unused-parameter"
)

