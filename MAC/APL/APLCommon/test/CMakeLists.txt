# $Id: CMakeLists.txt 17849 2011-04-26 09:40:07Z overeem $

include(LofarCTest)

# Add the directory where the generated C++ headers are stored to the -I path.
include_directories(${PACKAGE_BINARY_DIR}/src)

lofar_add_test(tControllerDefines tControllerDefines.cc)
lofar_add_test(tAntennaField tAntennaField.cc)
lofar_add_test(tAPLUtilities tAPLUtilities.cc)
lofar_add_test(tbitsetUtil tbitsetUtil.cc)
lofar_add_test(tOutOfBand tOutOfBand.cc)
lofar_add_test(tAntennaMapper tAntennaMapper.cc)
lofar_add_test(tParentControl tParentControl.cc)
lofar_add_executable(ControllerProtMenu ControllerProtMenu.cc)

