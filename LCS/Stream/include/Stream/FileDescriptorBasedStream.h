//# FileDescriptorBasedStream.h: 
//#
//# Copyright (C) 2008
//# ASTRON (Netherlands Institute for Radio Astronomy)
//# P.O.Box 2, 7990 AA Dwingeloo, The Netherlands
//#
//# This file is part of the LOFAR software suite.
//# The LOFAR software suite is free software: you can redistribute it and/or
//# modify it under the terms of the GNU General Public License as published
//# by the Free Software Foundation, either version 3 of the License, or
//# (at your option) any later version.
//#
//# The LOFAR software suite is distributed in the hope that it will be useful,
//# but WITHOUT ANY WARRANTY; without even the implied warranty of
//# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
//# GNU General Public License for more details.
//#
//# You should have received a copy of the GNU General Public License along
//# with the LOFAR software suite. If not, see <http://www.gnu.org/licenses/>.
//#
//# $Id: FileDescriptorBasedStream.h 20635 2012-04-03 07:58:40Z mol $

#ifndef LOFAR_LCS_STREAM_FILE_DESRIPTOR_BASED_STREAM_H
#define LOFAR_LCS_STREAM_FILE_DESRIPTOR_BASED_STREAM_H

#include <Stream/Stream.h>


namespace LOFAR {

class FileDescriptorBasedStream : public Stream
{
  public:
		   FileDescriptorBasedStream(int fd = -1) : fd(fd) {}
    virtual	   ~FileDescriptorBasedStream();

    virtual size_t tryRead(void *ptr, size_t size);
    virtual size_t tryWrite(const void *ptr, size_t size);

    virtual void   sync();

    int		   fd;
};

} // namespace LOFAR

#endif
