//# LofarImager.h: Imager for LOFAR data correcting for DD effects
//#
//# Copyright (C) 2011
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
//# $Id: Imager.h 29711 2014-07-09 12:14:25Z vdtol $
//#
//# @author Ger van Diepen <diepen at astron dot nl>

#ifndef LOFAR_LOFARFT_IMAGER_H
#define LOFAR_LOFARFT_IMAGER_H

#include <LofarFT/FTMachine.h>
#include <LofarFT/VisibilityIterator.h>
#include <LofarFT/VisImagingWeight.h>
#include <synthesis/MeasurementEquations/Imager.h>
#include <Common/ParameterSet.h>
#include <casa/Containers/Record.h>


namespace LOFAR {
namespace LofarFT {
  
  // @brief Imager for LOFAR data correcting for DD effects

  class Imager : public casa::Imager
  // TODO
  // override Imager::operator= to copy LofarImager data members
  // override Imager::defaults to set lofar_imwgt_p
  // override Imager::filter
  
  {
  public:

    // Construct from the Imager object.
    explicit Imager (casa::MeasurementSet&,
                     LOFAR::ParameterSet& parset);

    virtual ~Imager();

    // Create the LofarFTMachine and fill ft_p in the parent.
    virtual casa::Bool createFTMachine();

    virtual void setSkyEquation();

    virtual void makeVisSet(
      casa::MeasurementSet& ms, 
      casa::Bool compress, 
      casa::Bool mosaicOrder);
    
    // Get the average primary beam.
    const casa::Matrix<casa::Float>& getAveragePB() const
    { 
      return itsFTMachine->getAveragePB();
    }

    // Get the spheroidal cut.
    const casa::Matrix<casa::Float>& getSpheroidal() const
    { 
      return itsFTMachine->getSpheroidal();
    }
    
    casa::Bool makeimage(const casa::String& type, const casa::String& image);


    // Show the relative timings of the various steps.
    void showTimings (std::ostream&, double duration) const;
    
    casa::Bool restoreImages(const casa::Vector<casa::String>& restored, casa::Bool modresiduals=casa::True);

  virtual casa::Bool checkCoord(const casa::CoordinateSystem& coordsys, 
                          const casa::String& imageName); 
    
    
  casa::Record initClean(
    const casa::String& algorithm,
    const casa::Int niter,
    const casa::Float gain,
    const casa::Quantity& threshold,
    const casa::Vector<casa::String>& model, 
    const casa::Vector<casa::Bool>& fixed,
    const casa::String& complist,
    const casa::Vector<casa::String>& mask,
    const casa::Vector<casa::String>& restored,
    const casa::Vector<casa::String>& residual,
    const casa::Vector<casa::String>& psf = casa::Vector<casa::String>(0),
    const casa::Bool firstrun=true);

  casa::Record doClean(const casa::Bool firstrun=true);
    
  void initPredict(const casa::Vector<casa::String>& modelNames);
  void predict();
  
  casa::Bool set_imaging_weight(const ParameterSet& parset);
  
  private:
    //# Data members.
    ParameterSet    &itsParset;
    FTMachine*       itsFTMachine;
    vector<casa::Array<casa::Complex> >  itsGridsParallel;
    vector<casa::Array<casa::DComplex> > itsGridsParallel2;
    VisibilityIterator*    lofar_rvi_p;
    casa::CountedPtr<VisImagingWeight> lofar_imwgt_p;
    casa::Vector<casa::String> itsPSFNames;

    
};

} //# end namespace LofarFT
} //# end namespace LOFAR

#endif
