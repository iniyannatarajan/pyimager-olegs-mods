#!/usr/bin/env python

import argparse
import lofar.pyimager.algorithms as algorithms

def main():
    parser = argparse.ArgumentParser(description = "Python imager")
    subparsers = parser.add_subparsers(help = "operation to perform")

    subparser = subparsers.add_parser("degrid", help = "Write predicted visibilities to MS")
    subparser.add_argument("-z", "--threads", help = "no. of threads",
        type = int, default = 1)
    subparser.add_argument("-p", "--data-processor", dest = "processor",
        metavar = "PROCESSOR", default = "casa", help = "data processor to use")
    subparser.add_argument("-b", "--max-baseline", type = float, default = 0.0,
        metavar = "LENGTH", help = "maximum baseline length (m)")
    subparser.add_argument("--weight-type", dest = "weighttype",
        default = "natural", metavar = "WEIGHTTYPE", help = "uniform, natural,"
        " robust")
    subparser.add_argument("--rmode", dest = "rmode",
        default = "normal", metavar = "RMODE", help = "abs, normal")
    subparser.add_argument("--noise", dest = "noise", type = float,
        default = 0.0, metavar = "NOISE", help = "")
    subparser.add_argument("--robustness", dest = "robustness", type = float,
        default = 0.0, metavar = "ROBUSTNESS", help = "")
    subparser.add_argument("--profile", dest = "profile",
        default = "", metavar = "PROFILE", help = "ipcluster profile name")
    subparser.add_argument("--chunksize", dest = "chunksize", type = int,
	default = 0, metavar = "CHUNKSIZE", help = "Number of rows to read from MS (0 for auto)")
    subparser.add_argument("--outcol", dest = "outcol",
        metavar = "OUTCOL", default = "DATA", help = "Column where predicted visibilities will be written")
    subparser.add_argument("--beamname", dest = "beamname", metavar = "BEAMNAME", 
        default = "", help = "Prefix for the names of the beamfiles; will be suffixed with <xx>_<real> etc.,")
    subparser.add_argument("ms", help = "input measurement set")
    subparser.add_argument("image", help = "input model image")
    subparser.set_defaults(func = algorithms.degridder)

    subparser = subparsers.add_parser("empty", help = "create an empty image")
    subparser.add_argument("-z", "--threads", help = "no. of threads",
        type = int, default = 1)
    subparser.add_argument("-p", "--data-processor", dest = "processor",
        metavar = "PROCESSOR", default = "casa", help = "data processor to use")
    subparser.add_argument("-b", "--max-baseline", type = float, default = 0.0,
        metavar = "LENGTH", help = "maximum baseline length (m)")
    subparser.add_argument("--weight-type", dest = "weighttype",
        default = "natural", metavar = "WEIGHTTYPE", help = "uniform, natural,"
        " robust")
    subparser.add_argument("--rmode", dest = "rmode",
        default = "normal", metavar = "RMODE", help = "abs, normal")
    subparser.add_argument("--noise", dest = "noise", type = float,
        default = 0.0, metavar = "NOISE", help = "")
    subparser.add_argument("--robustness", dest = "robustness", type = float,
        default = 0.0, metavar = "ROBUSTNESS", help = "")
    subparser.add_argument("--profile", dest = "profile",
        default = "", metavar = "PROFILE", help = "ipcluster profile name")
    subparser.add_argument("--beamname", dest = "beamname", metavar = "BEAMNAME", 
        default = "", help = "Prefix for the names of the beamfiles; will be suffixed with <xx>_<real> etc.,")
    subparser.add_argument("ms", help = "input measurement set")
    subparser.add_argument("image", help = "output image")
    subparser.set_defaults(func = algorithms.empty)

    subparser = subparsers.add_parser("dirty", help = "create a dirty image")
    subparser.add_argument("-z", "--threads", help = "no. of threads",
        type = int, default = 1)
    subparser.add_argument("-p", "--data-processor", dest = "processor",
        metavar = "PROCESSOR", default = "casa", help = "data processor to use")
    subparser.add_argument("-b", "--max-baseline", type = float, default = 0.0,
        metavar = "LENGTH", help = "maximum baseline length (m)")
    subparser.add_argument("--weight-type", dest = "weighttype",
        default = "natural", metavar = "WEIGHTTYPE", help = "uniform, natural,"
        " robust")
    subparser.add_argument("--rmode", dest = "rmode",
        default = "normal", metavar = "RMODE", help = "abs, normal")
    subparser.add_argument("--noise", dest = "noise", type = float,
        default = 0.0, metavar = "NOISE", help = "")
    subparser.add_argument("--robustness", dest = "robustness", type = float,
        default = 0.0, metavar = "ROBUSTNESS", help = "")
    subparser.add_argument("--profile", dest = "profile",
        default = "", metavar = "PROFILE", help = "ipcluster profile name")
    subparser.add_argument("--chunksize", dest = "chunksize", type = int,
	default = 0, metavar = "CHUNKSIZE", help = "Number of rows to read from MS (0 for auto)")
    subparser.add_argument("--outcol", dest = "outcol",
        metavar = "OUTCOL", default = "DATA", help = "Column where predicted visibilities will be written")
    subparser.add_argument("--beamname", dest = "beamname", metavar = "BEAMNAME", 
        default = "", help = "Prefix for the names of the beamfiles; will be suffixed with <xx>_<real> etc.,")
    subparser.add_argument("ms", help = "input measurement set")
    subparser.add_argument("image", help = "output image")
    subparser.set_defaults(func = algorithms.dirty)

    subparser = subparsers.add_parser("mfclean", help = "multi-field Clark "
        "clean")
    subparser.add_argument("-z", "--threads", help = "no. of threads",
        type = int, default = 1)
    subparser.add_argument("-p", "--data-processor", dest = "processor",
        metavar = "PROCESSOR", default = "casa", help = "data processor to use")
    subparser.add_argument("-b", "--max-baseline", type = float, default = 0.0,
        metavar = "LENGTH", help = "maximum baseline length (m)")
    subparser.add_argument("-P", "--padding", type = float, default = 1.0,
        help = "image plane padding factor (>= 1.0)")
    subparser.add_argument("-g", "--gain", type = float, default = 0.1,
        help = "loop gain for the minor cycle")
    subparser.add_argument("-i", "--iterations", type = int, default = 10000,
        help = "maximum number of minor cycle iterations")
    subparser.add_argument("-t", "--threshold", type = float, default = 0.0,
        help = "threshold at which to stop cleaning (Jy)")
    subparser.add_argument("-f", "--cycle-factor", type = float, default = 1.5,
        metavar = "FACTOR", help = "")
    subparser.add_argument("-s", "--cycle-speedup", type = float,
        default = -1.0, metavar = "SPEEDUP", help = "")
    subparser.add_argument("-m", "--cycle-max-psf-fraction", type = float,
        default = 0.8, metavar = "FRACTION", help = "")
    subparser.add_argument("--weight-type", dest = "weighttype",
        default = "natural", metavar = "WEIGHTTYPE", help = "uniform, natural,"
        " robust")
    subparser.add_argument("--rmode", dest = "rmode",
        default = "normal", metavar = "RMODE", help = "abs, normal")
    subparser.add_argument("--noise", dest = "noise", type = float,
        default = 0.0, metavar = "NOISE", help = "")
    subparser.add_argument("--robustness", dest = "robustness", type = float,
        default = 0.0, metavar = "ROBUSTNESS", help = "")
    subparser.add_argument("--profile", dest = "profile",
        default = "", metavar = "PROFILE", help = "ipcluster profile name")
    subparser.add_argument("--beamname", dest = "beamname", metavar = "BEAMNAME", 
        default = "", help = "Prefix for the names of the beamfiles; will be suffixed with <xx>_<real> etc.,")
#    subparser.add_argument("-g", choices = ["awz", "aw", "w"],
#        help = "gridder to use")
#    subparser.add_argument("-G", dest = "gridder_options", action = "append",
#        metavar = "OPTION", help = "gridder specific option")
    subparser.add_argument("ms", help = "input measurement set")
    subparser.add_argument("image", help = "output image")
    subparser.set_defaults(func = algorithms.mfclean)

    args = parser.parse_args()
    args.func(args)

if __name__ == "__main__":
    main()
