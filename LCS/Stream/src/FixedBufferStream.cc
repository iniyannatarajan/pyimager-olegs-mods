//# FixedBufferStream.cc: 
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
//# $Id: FixedBufferStream.cc 27153 2013-10-30 18:07:49Z amesfoort $

#include <lofar_config.h>

#include <Stream/FixedBufferStream.h>
#include <Common/Thread/Cancellation.h>

#include <cstring>


namespace LOFAR {


FixedBufferStream::FixedBufferStream(char *buffer, size_t size)
:
  itsEnd(buffer + size),
  itsHead(buffer)
{
}


FixedBufferStream::~FixedBufferStream()
{
}


size_t FixedBufferStream::tryRead(void *ptr, size_t size)
{
  Cancellation::point(); // keep behaviour consistent with real I/O streams

  size_t numBytes = std::min<size_t>(size, itsEnd - itsHead);

  if (numBytes == 0)
    THROW(EndOfStreamException, "No space left in buffer");

  memcpy(ptr, itsHead, numBytes);
  itsHead += numBytes;

  return numBytes;
}


size_t FixedBufferStream::tryWrite(const void *ptr, size_t size)
{
  Cancellation::point(); // keep behaviour consistent with real I/O streams

  size_t numBytes = std::min<size_t>(size, itsEnd - itsHead);

  if (numBytes == 0)
    THROW(EndOfStreamException, "No space left in buffer");

  memcpy(itsHead, ptr, numBytes);
  itsHead += numBytes;

  return numBytes;
}

} // namespace LOFAR
