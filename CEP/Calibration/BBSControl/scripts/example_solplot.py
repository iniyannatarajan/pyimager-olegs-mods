# example_solplot.py: 
#
# Copyright (C) 2007
# ASTRON (Netherlands Institute for Radio Astronomy)
# P.O.Box 2, 7990 AA Dwingeloo, The Netherlands
#
# This file is part of the LOFAR software suite.
# The LOFAR software suite is free software: you can redistribute it and/or
# modify it under the terms of the GNU General Public License as published
# by the Free Software Foundation, either version 3 of the License, or
# (at your option) any later version.
#
# The LOFAR software suite is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU General Public License for more details.
#
# You should have received a copy of the GNU General Public License along
# with the LOFAR software suite. If not, see <http://www.gnu.org/licenses/>.
#
# $Id: example_solplot.py 14741 2009-12-30 15:07:42Z zwieten $

import lofar.parmdb
import lofar.solutions

db = lofar.parmdb.parmdb("instrument.db")

stations = ["CS00%d_HBA%d" % (x,y) for x in [1,8] for y in range(0,4)]
(ampl, phase) = lofar.solutions.fetch(db, stations)

lofar.solutions.plot(ampl)