/***************************************************************************
 *   Copyright (C) 2008-2010 by A.R. Offringa   *
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
#ifndef TIMEFREQUENCYSTATISTICS_H
#define TIMEFREQUENCYSTATISTICS_H

#include <string>

#include <AOFlagger/msio/timefrequencydata.h>

class TimeFrequencyStatistics
{
	public:
		TimeFrequencyStatistics(const TimeFrequencyData &data);

		num_t GetFlaggedRatio();

		static std::string FormatRatio(num_t ratio);

	private:
		TimeFrequencyData _data;
};

#endif // TIMEFREQUENCYSTATISTICS_H
