//#  -*- mode: c++ -*-
//#
//#  TDStatus.h: System status information
//#
//#  Copyright (C) 2002-2004
//#  ASTRON (Netherlands Foundation for Research in Astronomy)
//#  P.O.Box 2, 7990 AA Dwingeloo, The Netherlands, seg@astron.nl
//#
//#  This program is free software; you can redistribute it and/or modify
//#  it under the terms of the GNU General Public License as published by
//#  the Free Software Foundation; either version 2 of the License, or
//#  (at your option) any later version.
//#
//#  This program is distributed in the hope that it will be useful,
//#  but WITHOUT ANY WARRANTY; without even the implied warranty of
//#  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
//#  GNU General Public License for more details.
//#
//#  You should have received a copy of the GNU General Public License
//#  along with this program; if not, write to the Free Software
//#  Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
//#
//#  $Id: TDStatus.h 22248 2012-10-08 12:34:59Z overeem $

#ifndef TDSTATUS_H_
#define TDSTATUS_H_

#include <iostream>
#include <complex>
#include <blitz/array.h>
#include <Common/LofarTypes.h>

#include <APL/RSP_Protocol/EPA_Protocol.ph>

namespace LOFAR {
  namespace RSP_Protocol {

    class TDStatus
    {
    public:
      /**
       * Constructors for a TDStatus object.
       */
      TDStatus() { }
	  
      /* Destructor for TDStatus. */
      virtual ~TDStatus() {}

      /*@{*/
      /**
       * Member accessor functions.
       */
      blitz::Array<EPA_Protocol::TDBoardStatus, 1>& board();
      /*@}*/

    public:
      /*@{*/
      /**
       * marshalling methods
       */
	size_t getSize() const;
	size_t pack  (char* buffer) const;
	size_t unpack(const char *buffer);
      /*@}*/

    private:
      /*@{*/
      /**
       * System status fields.
       *
       * Dimensions of the arrays are:
       *  - m_board_status  [N_RSPBOARDS]
       */
      blitz::Array<EPA_Protocol::TDBoardStatus, 1> m_board_status;
      /*@}*/
    };

    inline blitz::Array<EPA_Protocol::TDBoardStatus, 1>& TDStatus::board() 
    {
      return m_board_status;
    }

  };
}; // namespace LOFAR

#endif /* TDSTATUS_H_ */
