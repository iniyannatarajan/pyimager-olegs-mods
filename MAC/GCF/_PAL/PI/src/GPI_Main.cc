//#  GPI_Main.cc: 
//#
//#  Copyright (C) 2002-2003
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
//#  $Id: GPI_Main.cc 5749 2005-07-19 10:05:15Z mueller $

#include <lofar_config.h>

#include  <GPI_Controller.h>

using namespace LOFAR::GCF;

int main(int argc, char *argv[])
{
	TM::GCFTask::init(argc, argv);

  LOG_INFO("MACProcessScope: GCF.PI");

	PAL::GPIController propertyInterace;

  propertyInterace.start();
  
  TM::GCFTask::run();

  // Just make the compilers happy...
	return 0;
}
