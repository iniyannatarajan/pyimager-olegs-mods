# $Id: CMakeLists.txt 21149 2012-06-07 13:04:41Z loose $

include(LofarCTest)

# Add the directory where the generated C++ headers are stored to the -I path.
include_directories(${PACKAGE_BINARY_DIR}/src)

lofar_add_test(tPropertySet tPropertySet.cc)
lofar_add_test(tRTDBPerformance tRTDBPerformance.cc RTDBPerfResp.cc)
lofar_add_test(tDPservice tDPservice.cc DPresponse.cc)
lofar_add_test(testQuery testQuery.cc)
lofar_add_test(tPerformanceReport tPerformanceReport.cc RTDBPerfResp.cc)
lofar_add_test(tRTDBPort tRTDBPort.cc)
