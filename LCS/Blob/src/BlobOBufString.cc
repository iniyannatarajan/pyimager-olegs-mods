//# BlobOBufString.cc: Input buffer for a blob using a string
//#
//# Copyright (C) 2003
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
//# $Id: BlobOBufString.cc 14057 2009-09-18 12:26:29Z diepen $

//# Always #include <lofar_config.h> first!
#include <lofar_config.h>

#include <Blob/BlobOBufString.h>

namespace LOFAR {

BlobOBufString::BlobOBufString (BlobString& buffer,
				uint64 expandSize, uint64 start)
  : BlobOBufChar (buffer.data(), buffer.capacity(),
		  buffer.canExpand() ? expandSize:0,
		  start, false),
    itsString    (&buffer)
{
  ASSERT(start <= buffer.size());
}

BlobOBufString::~BlobOBufString()
{}

void BlobOBufString::doExpand (uint64 newReservedSize, uint64 newSize)
{
  if (newReservedSize > itsString->capacity()) {
    itsString->reserve (newReservedSize);
  }
  itsString->resize (newSize);
  // Note that the std::string class might uses reference counting.
  // Therefore a resize may need to make a copy, so it can change the
  // buffer pointer. 
  setBuffer (itsString->data());
}

} // end namespace
