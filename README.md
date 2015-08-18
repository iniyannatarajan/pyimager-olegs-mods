Installation Instructions:
**************************

Prerequisites:
==============

It is recommended that the user install the following Ubuntu PPA repository
for radio astronomy software:

    $ sudo apt-get install software-properties-common
    $ sudo add-apt-repository ppa:radio-astro/main
    $ sudo apt-get update
    
It helps to have the program 'quilt' installed, since we will be applying some patches to casa-code later on using quilt.

Basic Installation:
===================

To install prepackaged pyimager:

    $ sudo apt-get install pyimager

Building pyimager from source (for building casa components too, see the next section):
=======================================================================================

For developers, some dependency packages need to be installed before pyimager could be successfully compiled.

    $ sudo apt-get install cmake lwimager bison libcasa-casacore-dev libboost-dev libreadline-dev \
    libblitz0-dev flex wcslib-dev libcfitsio3-dev gfortran libboost-thread-dev libfftw3-dev \
    libhdf5-dev python-casa-pyrap libboost-python-dev python-all python-numpy libgsl0-dev libxml2-dev \
    libpng12-dev libboost-system-dev libboost-filesystem-dev libgtkmm-2.4-dev python-pywcs \
    libboost-regex-dev libboost-program-options-dev libboost-date-time-dev liblog4cplus-dev casa-code

Once the above packages have been installed, pyimager can be built and installed in a custom path, as follows:
(In the following, it is assumed that the user downloads the software packages to '/home/user/software/src' 
and installs them to '/home/user/software')

    $ SRCROOT=/home/user/software/src
    $ INSTALLROOT=/home/user/software
    $ cd $SRCROOT
    $ git clone https://github.com/ratt-ru/pyimager.git
    $ cd pyimager
    $ mkdir build/gnu_opt && cd build/gnu_opt
    $ cmake ../.. -DCMAKE_INSTALL_PREFIX=$INSTALLROOT/pyimager \
    -DBUILD_PACKAGES="pyimager BBSKernel pyparameterset" \
        -DBUILD_SHARED_LIBS=ON \
        -DUSE_CASA42=ON \
        -DLofarFT_SOURCE_DIR=LofarFT-4.2 \
        -DUSE_OPENMP=ON \
        -DPythonLibs_FIND_VERSION=2
    $ make -j8
    $ make install

Building from source for developers that intend to dabble with casacore & casacode:
===================================================================================

This subsection deals with the special case where the developer needs to modify 
casacore and casacode. All dependencies mentioned in the previous section are mandatory 
except "casa-code" and "libcasa-casacore-dev", since the user will build her own version.

For pyimager to work, version 4.2.0 of casacode and casacore must be installed.
These can be obtained from https://svn.cv.nrao.edu/svn/casa/branches/release-4_2_0.

Assuming that the user wants to download the software packages to '/home/user/software/src' 
and installs them to '/home/user/software'; also assuming that casacore 'measures_data' is present in
'/usr/share/casacore/data':

    $ SRCROOT=/home/user/software/src
    $ INSTALLROOT=/home/user/software

To install casacore,

    $ cd $SRCROOT
    $ svn co https://svn.cv.nrao.edu/svn/casa/branches/release-4_2_0/casacore/
    $ cd casacore
    $ mkdir build && cd build
    $ cmake .. -DCMAKE_INSTALL_PREFIX=$INSTALLROOT/casacore -DUSE_FFTW3=ON -DBUILD_TESTING=OFF
    -DDATA_DIR=/usr/share/casacore/data -DUSE_OPENMP=ON
    $ make -j8
    $ make install

To install casacode,

    $ cd $SRCROOT
    $ svn co https://svn.cv.nrao.edu/svn/casa/branches/release-4_2_0/code casa-code-4.2.0
    $ cd casa-code-4.2.0
    $ git clone https://github.com/radio-astro/casa-code-debian debian
    $ quilt push -a # Make sure quilt is installed.
    
    If quilt is not installed, use dpkg-buildpackage to apply the patches. Please note that the command 
    might fail with an 'unmet-dependencies' warning, but the patches themselves would be applied.

    $ dpkg-buildpackage
    
    At this point the necessary patches should have been applied.
    
    $ mkdir -p build/gnu_opt && cd build/gnu_opt
    $ cmake ../../ -DCMAKE_INSTALL_PREFIX=$INSTALLROOT/casacode -DSKIP_PGPLOT=OFF
    -DCASACORE_ROOT_DIR=$INSTALLROOT/casacore
    $ make -j8
    $ make install

Pyimager can now be built against the custom casa installation.

    $ cd $SRCROOT
    $ git clone https://github.com/ratt-ru/pyimager.git
    $ cd pyimager
    $ mkdir -p build/gnu_opt && cd build/gnu_opt
    $ cmake ../.. -DCMAKE_INSTALL_PREFIX=$INSTALLROOT/pyimager \
    -DCASACORE_ROOT_DIR=$INSTALLROOT/casacore \
    -DCASA_ROOT_DIR=$INSTALLROOT/casacode
    -DBUILD_PACKAGES="pyimager BBSKernel pyparameterset" \
        -DBUILD_SHARED_LIBS=ON \
        -DUSE_CASA42=ON \
        -DLofarFT_SOURCE_DIR=LofarFT-4.2 \
        -DUSE_OPENMP=ON \
        -DPythonLibs_FIND_VERSION=2
    $ make -j8
    $ make install

The following environment variables must be set to run pyimager.

    export PATH=$INSTALLROOT/pyimager/bin:$PATH
    export PYTHONPATH=$INSTALLROOT/pyimager/lib/python2.7/dist-packages:$PYTHONPATH
