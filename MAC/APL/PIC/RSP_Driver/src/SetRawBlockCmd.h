//#  -*- mode: c++ -*-
//#
//#  SetRawBlockCmd.h: Get system status command.
//#
//#  Copyright (C) 2008
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
//#  $Id: SetRawBlockCmd.h 13440 2009-06-22 13:26:54Z overeem $

#ifndef SET_RAWBLOCK_CMD_H
#define SET_RAWBLOCK_CMD_H

#include "Command.h"
#include <APL/RSP_Protocol/RSP_Protocol.ph>

#include <Common/LofarTypes.h>
#include <GCF/TM/GCF_Control.h>

namespace LOFAR {
  namespace RSP {

class SetRawBlockCmd : public Command
{
public:
	// Constructors for a SetRawBlockCmd object.
	SetRawBlockCmd(GCFEvent& event, GCFPortInterface& port, Operation oper);

	// Destructor for SetRawBlockCmd. */
	virtual ~SetRawBlockCmd();

	// Acknowledge the command by sending the appropriate
	// response on m_port.
	virtual void ack(CacheBuffer& cache);

	// Make necessary changes to the cache for the next synchronization.
	// Any changes will be sent to the RSP boards.
	virtual void apply(CacheBuffer& cache, bool setModFlag = true);

	// Complete the command by sending the appropriate response on
	// the m_answerport;
	virtual void complete(CacheBuffer& cache);

	//@{
	// get timestamp of the event
	virtual const RTC::Timestamp& getTimestamp() const;
	virtual void setTimestamp(const RTC::Timestamp& timestamp);
	//@}

	// Range check the parameters of the event.
	virtual bool validate() const;

	// Send failure ack.
	void ack_fail();

private:
	SetRawBlockCmd();				// Default construction is not allowed.
	RSPSetblockEvent* 	itsEvent;
};

  } // namespace RSP
} // namespace LOFAR
     
#endif /* SET_RAWBLOCK_CMD_H */
