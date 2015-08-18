/*
 * $Id: DataKey.java 8825 2006-06-28 14:44:59Z pompert $
 *
 * This software is provided by NOAA for full, free and open release.  It is
 * understood by the recipient/user that NOAA assumes no liability for any
 * errors contained in the code.  Although this software is released without
 * conditions or restrictions in its use, it is expected that appropriate
 * credit be given to its author and to the National Oceanic and Atmospheric
 * Administration should the software be included by the recipient as an
 * element in other product development.
 */

package gov.noaa.pmel.sgt;

import gov.noaa.pmel.util.Point2D;
import gov.noaa.pmel.util.Rectangle2D;

/**
 * Inticates the class is a key or legend.
 *
 * @author Donald Denbo
 * @version $Revision: 8825 $, $Date: 2006-06-28 14:44:59 +0000 (Wed, 28 Jun 2006) $
 * @since 3.0
 * @stereotype container
 **/
public interface DataKey extends LayerChild {
  public void setLocationP(Point2D.Double locP);
  public void addGraph(CartesianRenderer rend, SGLabel label)
      throws IllegalArgumentException;
  public void setAlign(int vert, int horz);
  public void setHAlign(int horz);
  public void setVAlign(int vert);
  public void setBorderStyle(int style);
  public void setBoundsP(Rectangle2D.Double r);
  public void setColumns(int col);
  public void setLineLengthP(double len);
}