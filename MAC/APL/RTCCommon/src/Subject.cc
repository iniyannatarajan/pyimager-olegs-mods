//#  -*- mode: c++ -*-
//#
//#  Subject.cc: Observer/Subject pattern class.
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
//#  $Id: Subject.cc 9718 2006-12-06 16:17:26Z wierenga $

#include <lofar_config.h>
#include <APL/RTCCommon/Subject.h>

#include <algorithm>

using namespace std;
using namespace LOFAR;
using namespace RTC;

Subject::~Subject()
{
  for (set<Observer*>::iterator it = m_observers.begin();
       it != m_observers.end(); ++it)
  {
    if (*it) delete (*it);
  }
}

void Subject::attach(Observer* observer)
{
  m_observers.insert(observer);
}

bool Subject::detach(Observer* observer)
{
  // find observer
  set<Observer*>::iterator it = m_observers.find(observer);

  // if found, delete and remove from set
  if (it != m_observers.end()) {
    if (*it) delete (*it);
    m_observers.erase(it);
    return true;
  }

  return false;
}

void Subject::notify()
{
  for (set<Observer*>::iterator it = m_observers.begin();
       it != m_observers.end(); ++it)
  {
    if (*it) (*it)->update(this);
  }
}

