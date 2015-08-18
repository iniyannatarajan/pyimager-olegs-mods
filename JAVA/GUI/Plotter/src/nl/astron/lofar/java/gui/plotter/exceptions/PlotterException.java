/*
 * PlotterException.java
 *
 *  Copyright (C) 2002-2007
 *  ASTRON (Netherlands Foundation for Research in Astronomy)
 *  P.O.Box 2, 7990 AA Dwingeloo, The Netherlands, seg@astron.nl
 *
 *  This program is free software; you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation; either version 2 of the License, or
 *  (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program; if not, write to the Free Software
 *  Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 *
 */

package nl.astron.lofar.java.gui.plotter.exceptions;

import nl.astron.lofar.java.gui.plotter.PlotConstants;

/**
 * This abstract exception forms the base class for every specific exception in the plotter
 * application.
 * @version $Id: PlotterException.java 8336 2006-05-05 13:35:26Z pompert $
 * @created April 18, 2006, 11:03 AM
 * @author pompert
 */
public abstract class PlotterException extends Exception{
    
    /** 
     * Creates a new instance of PlotterException 
     */
    public PlotterException() {
        super();
    }
    /** 
     * Returns the exception message defined in PlotConstants.EXCEPTION_GENERIC
     * @return the Exception message
     * @see PlotConstants
     */
    public String getMessage(){
        return PlotConstants.EXCEPTION_GENERIC;
    }
    
}