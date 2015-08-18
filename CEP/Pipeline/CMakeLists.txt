# $Id: CMakeLists.txt 20950 2012-05-16 14:29:28Z loose $

lofar_add_package(Pipeline-Framework framework)
lofar_add_package(Pipeline-Recipes recipes)
#lofar_add_package(Pipeline-MAC mac)

add_subdirectory(test)
