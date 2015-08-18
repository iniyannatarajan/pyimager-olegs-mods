/*
 * PlotController.java
 *
 *  Copyright (C) 2002-2007
 *  ASTRON (Netherlands Foundation for Research in Astronomy)
 *  P.O.Box 2, 7990 AA Dwingeloo, The Netherlands, seg@astron.nl
 
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

package nl.astron.lofar.java.gui.plotter;

import java.awt.Image;
import java.util.HashMap;
import java.util.MissingResourceException;
import java.util.ResourceBundle;
import javax.swing.JComponent;
import nl.astron.lofar.java.gui.plotter.exceptions.NotImplementedException;
import nl.astron.lofar.java.gui.plotter.exceptions.NotSupportedException;
import nl.astron.lofar.java.gui.plotter.exceptions.PlotterException;
import nl.astron.lofar.java.gui.plotter.exceptions.PlotterFrameworkInitializationException;
import nl.astron.lofar.java.gui.plotter.exceptions.PlotterFrameworkNotCompatibleException;
import nl.astron.lofar.java.gui.plotter.exceptions.PlotterFrameworkNotFoundException;

/**
 * The PlotController class functions as the central controller between:<br><br>
 * - The Visual component PlotPanel, which delivers input on what kind of plot the user wants<br>
 * - The Model/Data component PlotDataManager, which delivers the dataset based on the
 * users input and the configured data access layer<br>
 * - The Utility Component IPlot, which makes the plot using the configured framework and the dataset<br>
 * - The plot will then be returned to the PlotPanel.
 *
 * @created 11-04-2006, 15:00
 * @author pompert
 * @version $Id: PlotController.java 8763 2006-06-19 14:45:22Z pompert $
 * @updated 13-apr-2006 11:19:43
 */
public class PlotController{
    
    private PlotDataManager m_PlotDataManager;
    private IPlot m_PlotFrameWork;
    private HashMap<String,Object> m_plotData;
    
    /**
     * Creates a new instance of PlotController
     */
    public PlotController(){
        m_PlotDataManager = PlotDataManager.getInstance();
        //Initialise and load plotter classes and data interfaces
    }
    /**
     * Cleans up the instance variables
     */
    public void finalize() throws Throwable {
        m_PlotDataManager = null;
        m_PlotFrameWork = null;
    }
    
    /**
     * This method will attempt to create a JComponent plot using the
     * framework class and Data Access layer in the plotter_config.properties file.
     *
     * @param type A plot type (as defined in PlotConstants.PLOT_*)
     * @param separateLegend True to generate a separate legend JComponent,
     * false to have a legend embedded in the plot
     * @param constraints A data access object to be passed on to the data access layer
     * @return the JComponent plot that has been generated by the configured
     * framework
     * @throws PlotterException will be thrown when either the Data Access
     * layer or the Plotter Framework have run into an exception that the
     * user needs to be aware of.
     */
    public JComponent createPlot(int type, boolean separateLegend, Object constraints) throws PlotterException{
        JComponent newPlotComponent = null;
        if(m_PlotFrameWork == null){
            initializePlotterFramework();
        }
        if(type == PlotConstants.PLOT_BAR
                || type == PlotConstants.PLOT_GRID
                || type == PlotConstants.PLOT_SCATTER
                || type == PlotConstants.PLOT_XYLINE
                || type == PlotConstants.PLOT_POINTS){
            
            m_plotData = m_PlotDataManager.retrieveData(constraints);
            newPlotComponent = m_PlotFrameWork.createPlot(type,constraints.toString(),m_plotData,separateLegend);
        }else{
            throw new NotSupportedException("The requested plot type ("+type+") is not supported by the plotter at this time.");
        }
        return newPlotComponent;
    }
    /**
     * This method will attempt to retrieve a JComponent legend for the supplied JComponent plot.
     *
     * Important: The JComponent plot you provide must have been generated by the plotter framework
     *            implementation class (for example PlotSGTImpl). An exception can be thrown if you attempt
     *            to retrieve a Legend for say a JPanel or JButton.
     *
     * @param aPlot The JComponent plot that needs to have a separate legend
     * @return the legend JComponent for the plot JComponent specified
     * @throws PlotterException will be thrown if the legend could not be generated for the given JComponent.
     */
    public JComponent getLegendForPlot(JComponent aPlot) throws PlotterException{
        JComponent legendComponent = null;
        if(m_PlotFrameWork == null){
            initializePlotterFramework();
        }
        legendComponent = m_PlotFrameWork.getLegend(aPlot);
        
        return legendComponent;
    }
    
    /**
     * This method will create an Image of a plot. It works identically to
     * getPlot() as this method too accepts an object with constraints.
     * @param constraints The Object with constraints to be passed to the data access layer
     * @return image file of the plot requested
     * @throws PlotterException will be thrown when either the Data Access
     * layer or the Plotter Framework have run into an exception that the
     * user needs to be aware of.
     */
    public Image createPlotImage(Object constraints) throws PlotterException{
        throw new NotImplementedException("Image exportation is not yet implemented in this release.");
    }
    
    /**
     * This method will attempt to export a plot using the
     * Data Export layer specified in the plotter_config.properties file.
     * @param arguments The object containing arguments to be passed to the data export layer
     * @throws PlotterException will be thrown when the Data Export
     * layer has run into an exception that the user needs to be aware of.
     */
    public void exportData(Object arguments) throws PlotterException{
        throw new NotImplementedException("Export of data is not yet implemented in this release.");
    }
    
    /**
     * This method allows a user to modify a plot currently in memory by
     * altering its dataset
     * @param newConstraints An object containing instructions what to do with the dataset prior to rebuilding the plot
     * @throws PlotterException will be thrown when either the Data Access
     * layer or the Plotter Framework have run into an exception that the
     * user needs to be aware of.
     */
    public JComponent modifyPlot(JComponent currentPlot, Object newConstraints) throws PlotterException{
        if(m_PlotFrameWork == null){
            initializePlotterFramework();
        }
        try {
            m_plotData = m_PlotDataManager.updateData(m_plotData,newConstraints);
            currentPlot = m_PlotFrameWork.modifyPlot(currentPlot,m_plotData);
        } catch (PlotterException ex) {
            throw ex;
        }       
        return currentPlot;
    }
    /**
     * This method allows a user to get the dataset for the plot currently in memory.
     * @throws PlotterException will be thrown if the dataset does not exist.
     *
     */
    public HashMap getPlotData() throws PlotterException{
        if(m_plotData == null){
            throw new NotSupportedException("No data was present in the PlotController. Please create a plot first, or set the data manually.");
        }
        return m_plotData;
    }
    
    private void initializePlotterFramework() throws PlotterException{
        String plotFrameworkClass = "";
        Object aPlotter = null;
        IPlot aNewPlot = null;
        ResourceBundle resources = PlotDataManager.getPlotterConfigurationFile();
        try {
            plotFrameworkClass = resources.getString(("FRAMEWORK"));
            Class implementator = PlotController.class.forName(plotFrameworkClass);
            aPlotter = implementator.newInstance();
            aNewPlot = (IPlot)aPlotter;
        } catch (IllegalAccessException ex) {
            //TODO Log!
            PlotterFrameworkInitializationException exx = new PlotterFrameworkInitializationException();
            exx.initCause(ex);
            throw exx;
        } catch (ClassNotFoundException ex) {
            //TODO Log!
            PlotterFrameworkNotFoundException exx = new PlotterFrameworkNotFoundException("(used:"+ plotFrameworkClass + " )");
            exx.initCause(ex);
            throw exx;
        } catch (MissingResourceException ex) {
            //TODO Log!
            PlotterFrameworkNotFoundException exx = new PlotterFrameworkNotFoundException("(The property 'FRAMEWORK' was not found in the plotter_config.properties file)");
            exx.initCause(ex);
            throw exx;
        } catch (InstantiationException ex) {
            //TODO Log!
            PlotterFrameworkInitializationException exx = new PlotterFrameworkInitializationException();
            exx.initCause(ex);
            throw exx;
            
        } catch (ClassCastException ex) {
            //TODO LOG!
            PlotterFrameworkNotCompatibleException exx = new PlotterFrameworkNotCompatibleException();
            exx.initCause(ex);
            throw exx;
        } catch (Exception ex) {
            //TODO Log!
            PlotterFrameworkInitializationException exx = new PlotterFrameworkInitializationException();
            exx.initCause(ex);
            throw exx;
        }
        if(aNewPlot!=null){
            m_PlotFrameWork = aNewPlot;
        }
        
    }
}