//#  ClassifConv.h: Structure containing classification type conversions
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
//#  $Id: ClassifConv.h 7558 2006-02-02 10:18:42Z overeem $

#ifndef LOFAR_OTDB_CLASSIFCONV_H
#define LOFAR_OTDB_CLASSIFCONV_H

// \file
// Structure for conversion of parameter types.

//# Never #include <config.h> or #include <lofar_config.h> in a header file!
//# Includes
#include <OTDB/Converter.h>
#include <OTDB/OTDBtypes.h>

namespace LOFAR {
  namespace OTDB {

// \addtogroup OTDB
// @{

//# --- Forward Declarations ---
//# classes mentioned as parameter or returntype without virtual functions.
//#class OTDBconnection;

// Converts classification names into integers and vice versa.
class ClassifConv : public Converter {
public:
	//# We only have to make the constructor and destructor public
	// Converts classification names into integers and vice versa.
	explicit ClassifConv(OTDBconnection* aConn) :
		Converter(aConn, "Classification") {};
	~ClassifConv() {};

	// string to value
	inline classifType	get(const string&	aType)   const 
	{ return (convert(aType));	}

	// value to string
	inline string		get(classifType		aTypeID) const
	{ return (convert(aTypeID));	}

	// get pair at internal iterator
	inline bool		get(classifType&	theID, string&	theName) const 
	{ return (Converter::get(theID, theName));	}

};

// @}
  } // namespace OTDB
} // namespace LOFAR

#endif
