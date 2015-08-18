//# StopWatch.h:
//#
//# Copyright (C) 2006
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
//# $Id: StopWatch.h 14057 2009-09-18 12:26:29Z diepen $

#ifndef __STOPWATCH_H__
#define __STOPWATCH_H__

#include <sys/time.h>
#include <unistd.h>

/// StopWatch class

class StopWatch
{
 public:
  StopWatch();
  virtual ~StopWatch();

  void start();
  void stop();
  double elapsed();

 private:
  struct timeval startTime;
  struct timeval stopTime;
};

#endif /* __STOPWATCH_H__ */
