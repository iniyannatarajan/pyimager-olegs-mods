//#  -*- mode: c++ -*-
//#
//#  RawEvent.h: dispatch raw EPA events as GCF events.
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
//#  $Id: RawEvent.h 17606 2011-03-22 12:49:57Z schoenmakers $

#ifndef RAWEVENT_H_
#define RAWEVENT_H_

#include <GCF/TM/GCF_Control.h>

#include "DriverSettings.h"

namespace LOFAR {
	using GCF::TM::GCFTask;
	using GCF::TM::GCFPortInterface;
	namespace TBB {

class RawEvent
{

public:
	static GCFEvent::TResult dispatch(GCFTask& task, GCFPortInterface& port);
private:
    
};

	} // end TBB namespace
} // end LOFAR namespace
#endif /* RAWEVENT_H_ */
