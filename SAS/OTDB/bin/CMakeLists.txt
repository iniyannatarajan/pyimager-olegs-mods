# $Id: CMakeLists.txt 26517 2013-09-12 14:03:49Z schoenmakers $

install (PROGRAMS
  copyTree.py
  makeDefaultTemplates.py
  revertDefaultTemplates.py
  create_new_database.sh
  DESTINATION sbin)
