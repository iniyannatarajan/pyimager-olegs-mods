/***************************************************************************
 *   Copyright (C) 2008 by A.R. Offringa   *
 *   offringa@astro.rug.nl   *
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   (at your option) any later version.                                   *
 *                                                                         *
 *   This program is distributed in the hope that it will be useful,       *
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of        *
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the         *
 *   GNU General Public License for more details.                          *
 *                                                                         *
 *   You should have received a copy of the GNU General Public License     *
 *   along with this program; if not, write to the                         *
 *   Free Software Foundation, Inc.,                                       *
 *   59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.             *
 ***************************************************************************/
#include <AOFlagger/msio/samplerow.h>

SampleRowPtr SampleRow::CreateWithoutMissings() const
{
	size_t newSize = 0;
	for(size_t i=0;i<_size;++i)
		if(std::isfinite(_values[i])) ++newSize;
	SampleRow *newRow = new SampleRow(newSize);
	size_t indexToNew = 0;
	for(size_t i=0;i<_size;++i)
	{
		if(std::isfinite(_values[i]))
		{
			newRow->_values[indexToNew] = _values[i];
			++indexToNew;
		}
	}
	return SampleRowPtr(newRow);
}
