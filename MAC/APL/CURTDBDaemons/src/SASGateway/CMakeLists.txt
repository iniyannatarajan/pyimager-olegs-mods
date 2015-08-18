# $Id: CMakeLists.txt 20677 2012-04-05 12:11:57Z schoenmakers $

lofar_add_bin_program(SASGateway SASGatewayMain.cc SASGateway.cc)

install(FILES SASGateway_prod.conf SASGateway_test.conf DESTINATION etc)
