import lofar.parameterset
import pyrap.tables as pt
from pyrap.measures import measures
import pyrap.quanta as dq
import numpy as np
import pyfits # Using pyfits because pyrap.images couldn't read the supplied beam FITS files.
import numpy
import scipy.ndimage

# The beams are expected to be in the format X x Y x FREQ X POL (1 cell) for each polarization, real/imag component (and station - later).

class MyATerm :
  def __init__(self, parameters) :
    print "\033[94mPython MyATerm constructor\033[0m"
    print parameters.keys()
    #self.img = pyrap.images.image('beam.img').getdata()[0,0,:,:]

    # Read the necessary parameters from the parameterset.
    ms = str(parameters["ms"])
    beamname = str(parameters['beamname'])
    support = int(str(parameters['SpheSupport']))

    print "Reading beam patterns with prefix: ", beamname

    # 8 FITS files (4 pol each for real & imag parts) per station per frequency
    # HDUs are ordered as xx_re, xx_im, xy_re, xy_im, yx_re, yx_im, yy_re, yy_im
    hdulist = [] # Holds all the images for one station
    for pol in ['_xx','_xy','_yx','_yy']:
	for comp in ['_re','_im']:
	    temphdu = pyfits.open(beamname+pol+comp+'.fits')[0]; # Extract the first HDU
	    hdulist.append(temphdu)

    # Get the frequency range from the FITS header.
    hdu0 = hdulist[0]
    nfreq = hdu0.header['NAXIS3']
    dim = float(hdu0.header['NAXIS1']) # Assume this is a square image.
    self.Im_per_station = 8
    self.pa_step = 5 # Expose this as a parameter to the user.
    self.freqlist = [] # in Hertz
    if 'GFREQ1' in hdu0.header:
	for keyindex in range(1,nfreq+1):
	    self.freqlist.append(hdu0.header['GFREQ%i'%keyindex])
    else:
	#for keyindex in range(1,nfreq+1):
	    #self.freqlist.append(
	pass

    # Compute a set of angles by which the beams need to be rotated every timestamp. 
    dm = measures()

    field = 0 # this is used as the FIELD_ID - assume this to be zero for now; this is the field whose observed times we need from the MS.
    zenith = dm.direction('AZEL','0deg','90deg')

    tab = pt.table('TEST.MS')
    antpos = pt.table(tab.getkeyword("ANTENNA")).getcol("POSITION");
    ra,dec = pt.table(tab.getkeyword("FIELD")).getcol("PHASE_DIR",field,1)[0][0]
    # make position measure from antenna 0
    pos0 = dm.position('itrf',*[ dq.quantity(x,'m') for x in antpos[0]])
    dm.do_frame(pos0);
    # make direction measure from field centre
    fld = dm.direction('J2000',dq.quantity(ra,"rad"),dq.quantity(dec,"rad"))
    tab = tab.query("FIELD_ID==%d"%field);
    # get unique times
    times = numpy.array(sorted(set(tab.getcol("TIME")[~tab.getcol("FLAG_ROW")])));
    pa_times = [ (dm.do_frame(dm.epoch("UTC",dq.quantity(t,"s"))) and (dm.posangle(fld,zenith).get_value("deg"),t)) for t in times ]
    pa_times = sorted(pa_times)

    start_pa = pa_times[0][0];
    pa_filtered = [pa_times[0]];
    for tup in pa_times:
	if tup[0] - start_pa < self.pa_step:
	    continue;
	pa_filtered.append(tup)
	start_pa = tup[0]

    print pa_filtered

    # Downsample / Interpolate (upsample?) the beam patterns to the support function size.
    import time
    t1 = time.time()
    print 'Start time: ', t1
    self.beams = []

    zoomfactor1 = numpy.sqrt(2)*support;
    hduzoomed = np.zeros((self.Im_per_station,nfreq,zoomfactor1,zoomfactor1))
    for polcomp in range(0,self.Im_per_station):
        for freq in range(0,nfreq):
            tempbeam = hdulist[polcomp].data[freq,:,:]
            hduzoomed[polcomp,freq,:,:]= scipy.ndimage.zoom(tempbeam,zoomfactor1/float(tempbeam.shape[0]))

    self.times_filtered = []
    for pa_t in pa_filtered:
	print "pa_t: ", pa_t
	print "printed"
	aterms = numpy.zeros((self.Im_per_station,nfreq,support,support))
	for polcomp in range(0,self.Im_per_station):
	    for freq in range(0,nfreq):
		tempbeam = hduzoomed[polcomp,freq,:,:]
		temprotbeam = scipy.ndimage.rotate(tempbeam,pa_t[0])
		tempzoomedbeam = scipy.ndimage.zoom(temprotbeam,support/float(temprotbeam.shape[0]))
		tzb_dim = tempzoomedbeam.shape[0]
		aterms[polcomp,freq,:,:] = tempzoomedbeam[(tzb_dim/2.0)-(support/2.0):(tzb_dim/2.0)+(support/2.0),\
		(tzb_dim/2.0)-(support/2.0):(tzb_dim/2.0)+(support/2.0)];
	self.beams.append((pa_t[1],aterms))
	self.times_filtered.append(pa_t[1])
    t2 = time.time()
    print 'Stop time: ', t2
    print "Time to pre-compute a-terms: ", (t2-t1)/60.0, " minutes."

  def evaluate(self, idStation, freq, reference, normalize):
    print "\033[94m", idStation, freq, reference, normalize, "\033[0m"

    # Extract the beam corresponding to the current time from the dict
    beamidx = np.searchsorted(self.times_filtered, self.time)
    if beamidx >= len(self.beams):
	beamidx -= 1
    pre_aterm = self.beams[beamidx][1]

    #aterm_interp = numpy.zeros((self.Im_per_station,self.ny,self.nx))
    f_highidx = np.searchsorted(self.freqlist,freq)
    f_lowidx = f_highidx - 1

    if (f_lowidx < 0):
      f_lowidx = 0
      f_highidx = 1
      
    if (f_highidx >= len(self.freqlist)):
      f_lowidx = f_highidx-2
      f_highidx = f_highidx-1

    f0, f, f1 = self.freqlist[f_lowidx], freq[0], self.freqlist[f_highidx]

    #interp(pre_aterm[:,f_lowidx,:,:],pre_aterm[:,f_highidx,:,:])
    factor = (f-f0)/(f1-f0)
    aterm_interp = factor*pre_aterm[:,f_lowidx,:,:] + (1.0-factor)*pre_aterm[:,f_highidx,:,:]

    #for polcomp in self.Im_per_station:
    #	aterm_interp[polcomp] = #interpolate(pre_aterm[polcomp,freqlow,:,:],pre_aterm[polcomp,freqhi,:,:])
    
    result = numpy.zeros((len(freq), 4, self.nx, self.ny), dtype = complex)
    #result[:,0,:,:] = 1.0#imgR + 1j*imgI
    result[:,0,:,:] = aterm_interp[0] + 1j * aterm_interp[1]#imgR + 1j*imgI
    result[:,1,:,:] = aterm_interp[2] + 1j * aterm_interp[3]#imgR + 1j*imgI
    result[:,2,:,:] = aterm_interp[4] + 1j * aterm_interp[5]#imgR + 1j*imgI
    result[:,3,:,:] = aterm_interp[6] + 1j * aterm_interp[7]#imgR + 1j*imgI

    return result
   
  def setDirection(self, coordinates, shape):
    print "\033[94m", coordinates, shape, "\033[0m"
    self.nx = shape[0]
    self.ny = shape[1]
    

  def setEpoch(self, time):
    print "\033[94m", time, "\033[0m"
    self.time = time
