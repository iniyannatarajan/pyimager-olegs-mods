//#  GetLatencyCmd.cc: implementation of the GetLatencyCmd class
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
//#  $Id: GetLatencyCmd.cc 16532 2010-10-14 12:40:08Z donker $

#include <lofar_config.h>
#include <Common/LofarLogger.h>

#include <APL/RSP_Protocol/RSP_Protocol.ph>
#include <APL/RTCCommon/PSAccess.h>
#include <blitz/array.h>

#include "GetLatencyCmd.h"

using namespace blitz;
using namespace LOFAR;
using namespace RSP;
using namespace RSP_Protocol;
using namespace RTC;

GetLatencyCmd::GetLatencyCmd(GCFEvent& event, GCFPortInterface& port, Operation oper) :
	Command("GetLatency", port, oper)
{
  m_event = new RSPGetlatencyEvent(event);
}

GetLatencyCmd::~GetLatencyCmd()
{
  delete m_event;
}

void GetLatencyCmd::ack(CacheBuffer& cache)
{
  RSPGetlatencyackEvent ack;

  ack.timestamp = getTimestamp();
  ack.status = RSP_SUCCESS;

  ack.latencys().resize(cache.getLatencys()().extent(firstDim));
  ack.latencys() = cache.getLatencys()();
  
  getPort()->send(ack);
}

void GetLatencyCmd::apply(CacheBuffer& /*cache*/, bool /*setModFlag*/)
{
  /* intentionally left empty */
}

void GetLatencyCmd::complete(CacheBuffer& cache)
{
  ack(cache);
}

const Timestamp& GetLatencyCmd::getTimestamp() const
{
  return m_event->timestamp;
}

void GetLatencyCmd::setTimestamp(const Timestamp& timestamp)
{
  m_event->timestamp = timestamp;
}

bool GetLatencyCmd::validate() const
{
  return true;
}

bool GetLatencyCmd::readFromCache() const
{
  return m_event->cache;
}
