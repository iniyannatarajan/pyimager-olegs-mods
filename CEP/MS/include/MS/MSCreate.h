//#  MSCreate.h: Class to create a MeasurementSet
//#
//#  Copyright (C) 2005
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
//#  $Id: MSCreate.h 18326 2011-06-23 14:02:15Z diepen $

#ifndef BB_MS_MSCREATE_H
#define BB_MS_MSCREATE_H

// @file
// Class to create a MeasurementSet
// @author Ger van Diepen (diepen AT astron nl)

//# Includes
#include <Common/LofarTypes.h>
#include <casa/aips.h>
#include <Common/lofar_vector.h>

//# Forward Declarations
namespace casa
{
  class String;
  class MPosition;
  class MBaseline;
  class MDirection;
  class MeasFrame;
  class MeasurementSet;
  class MSMainColumns;
  template<class T> class Block;
  template<class T> class Vector;
  template<class T> class Matrix;
  template<class T> class Cube;
}

namespace LOFAR
{

// @ingroup MS
// @brief Class to create a MeasurementSet
// @{

// Class for creating a MeasurementSet (part).
// It creates an MS with all required meta info (like UVW) and the correct
// shapes of the DATA and FLAG columns. The data in these columns is set to 0.
// Simulator software (like BBS or MeqTrees) should fill in the data.

class MSCreate
{
public:
  // Construct the MS with a given name.
  // The timeStep (in sec) is used by the write function
  // to calculate the time from the starting time and the timeCounter.
  // If the antenna table name is not empty, the ANTENNA table will be
  // copied instead of putting default values in that table.
  // The antenna positions have to be given in ITRF coordinates as XYZ.
  // So antPos must have shape [3,nantennas].
  // If flagColumn is given and nFlagBits>0, an integer flag column is
  // created and column FLAG is mapped to it.
  MSCreate (const std::string& msName,
	    double startTime, double timeStep, int nfreq, int ncorr,
            const casa::Matrix<double>& antPos,
	    const std::string& antennaTableName,
	    bool writeAutoCorr,
	    int tileSizeFreq, int tileSize,
            const std::string& flagColumn=std::string(), int nflagBits=0,
            bool mapFlagBits=false);

  // Destructor
  ~MSCreate();

  // Add the extra columns needed for lwimager for every column not existing.
  // These are CORRECTED_DATA, MODEL_DATA, and IMAGING_WEIGHT.
  // Furthermore it sets the CHANNEL_SELECTION keyword for casa::VisSet.
  void addImagerColumns()
    { addImagerColumns (*itsMS); }
  static void addImagerColumns (casa::MeasurementSet&);

  // Add the definition of the next frequency band.
  // 1, 2 or 4 polarizations can be given.
  // 1 is always XX; 2 is XX,YY; 4 is XX,XY,YX,YY.
  // The frequencies have to be given in Hz.
  // The first version assumes that all channels are adjacent and that the
  // the reference frequency is the center of the entire band. From that
  // it calculates the center frequency for each channel.
  // The second version can be used to specify the center frequency and width
  // for each channel. So both arrays must have nchannels entries.
  // Note that the total bandwidth is calculated from the minimum and
  // maximum channel frequency. Thus it is not the sum of all widths.
  // <br>It returns the id (0-relative seqnr) of the band.
  // <group>
  int addBand (int npolarizations, int nchannels,
	       double refFreq, double chanWidth);
  int addBand (int npolarizations, int nchannels,
	       double refFreq, const double* chanFreqs,
	       const double* chanWidths);
  // </group>

  // Add the definition of the next field (i.e. beam).
  // The angles have to be given in radians.
  // <br>It returns the id (0-relative seqnr) of the field.
  int addField (double azimuth, double elevation);

  // Write the rows for a single time step.
  // It sets the shape of the data array.
  // All flags are set to False.
  void writeTimeStep();

  // Do the same, but write channel by channel.
  // This is only meant as a test to simulate the correlator behaviour.
  void writeTimeStep2();

  // Get the number of antennas.
  int nrAntennas() const
    { return itsNrAnt; }

  // Get the number of different polarization setups.
  int nrPolarizations() const;

  // Get the number of exposures.
  int nrTimes() const
    { return itsNrTimes; }

private:
  // Forbid copy constructor and assignment by making them private.
  // <group>
  MSCreate (const MSCreate&);
  MSCreate& operator= (const MSCreate&);
  // </group>

  // Create the MS and fill its subtables as much as possible.
  void createMS (const casa::String& msName,
                 const casa::String& antennaTableName, 
		 const casa::Block<casa::MPosition>& antPos,
		 int tileSizeFreq, int tileSize,
                 const casa::String& flagColumn, int nflagBits,
                 bool mapFlagBits);

  // Set the band.
  int addBand (int npolarizations, int nchannels,
	       double refFreq, const casa::Vector<double>& chanFreqs,
	       const casa::Vector<double>& chanWidths);

  // Add a polarization to the subtable.
  // Return the row number where it is added.
  int addPolarization (int npolarizations);

  // Fill the various subtables (at the end).
  // <group>
  void fillAntenna (const casa::Block<casa::MPosition>& antPos,
                    const casa::String& antennaTableName);
  void fillFeed();
  void fillObservation();
  void fillProcessor();
  void fillState();
  // </group>

  // Fill the vector of baselines itsAntBL.
  void fillBaseLines();

  // Update the times in various subtables at the end of the observation.
  void updateTimes();

  //# Define the data.
  bool itsWriteAutoCorr;             //# write autocorrelations?
  int itsNrBand;                     //# nr of bands
  int itsNrField;                    //# nr of fields (beams)
  int itsNrAnt;                      //# nr of antennas (stations)
  int itsNrFreq;                     //# Fixed nr of frequencies (channels)
  int itsNrCorr;                     //# Fixed nr of correlations (polar.)
  int itsNrTimes;                    //# nr of exposures
  double itsTimeStep;                //# duration of each exposure (sec)
  double itsStartTime;               //# start time of observation (sec)
  casa::Block<casa::Int>* itsNrPol;  //# nr of polarizations for each band
  casa::Block<casa::Int>* itsNrChan; //# nr of channels for each band
  casa::Block<casa::Int>* itsPolnr;  //# rownr in POL subtable for each band
  casa::Block<casa::MBaseline>* itsAntBL; //# Baseline vector for each antenna
  casa::MPosition*      itsArrayPos; //# Position of array center
  casa::MeasFrame*      itsFrame;    //# Frame to convert to apparent coordinates
  casa::Block<casa::MDirection>* itsPhaseDir;   //# Phase directions of fields
  casa::MeasurementSet* itsMS;
  casa::MSMainColumns*  itsMSCol;
};

// @}

} // end namespace

#endif
