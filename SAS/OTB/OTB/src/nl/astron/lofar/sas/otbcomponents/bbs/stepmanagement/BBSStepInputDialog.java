/*
 * BBSStepInputDialog.java
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

package nl.astron.lofar.sas.otbcomponents.bbs.stepmanagement;

import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import nl.astron.lofar.sas.otb.MainFrame;


/**
 * Dialog that contains a panel for the BBS Step Explorer
 *
 * @created 31-07-2006, 13:37
 * @author  pompert
 * @version $Id: BBSStepInputDialog.java 11163 2008-04-17 20:06:10Z coolen $
 */
public class BBSStepInputDialog extends javax.swing.JDialog {

    /** 
     * Creates new form BBSStepInputDialog 
     */
    public BBSStepInputDialog(MainFrame parent, boolean modal, BBSStep tobeDisplayedBBSStep,BBSStep parentBBSStep) {
        super(parent, modal);
        initComponents();
        this.sePanel.setMainFrame(parent);
        this.sePanel.addActionListener(new ActionListener(){
            public void actionPerformed(ActionEvent evt){
                if(evt.getActionCommand().equalsIgnoreCase("ReadyToClose")){
                    closeDialog();
                }
            }
        });
        if (tobeDisplayedBBSStep != null && parentBBSStep == null) {
            this.sePanel.setBBSStepContent(tobeDisplayedBBSStep,null);
        } else if(tobeDisplayedBBSStep == null && parentBBSStep != null){
            this.sePanel.setBBSStepContent(null,parentBBSStep);
        }else if(tobeDisplayedBBSStep == null && parentBBSStep == null){
            this.sePanel.setBBSStepContent(null,null);
        }
    }
    
    /** This method is called from within the constructor to
     * initialize the form.
     * WARNING: Do NOT modify this code. The content of this method is
     * always regenerated by the Form Editor.
     */
    // <editor-fold defaultstate="collapsed" desc="Generated Code">//GEN-BEGIN:initComponents
    private void initComponents() {

        warningLabel = new javax.swing.JLabel();
        sePanel = new nl.astron.lofar.sas.otbcomponents.bbs.stepmanagement.BBSStepExplorerPanel();

        setDefaultCloseOperation(javax.swing.WindowConstants.DISPOSE_ON_CLOSE);

        warningLabel.setFont(new java.awt.Font("Dialog", 1, 10));
        warningLabel.setForeground(java.awt.Color.gray);
        warningLabel.setHorizontalAlignment(javax.swing.SwingConstants.CENTER);
        warningLabel.setText("Note : To permanently store this step in its strategy, press 'Apply Settings' in the BBS Strategy panel.");

        org.jdesktop.layout.GroupLayout layout = new org.jdesktop.layout.GroupLayout(getContentPane());
        getContentPane().setLayout(layout);
        layout.setHorizontalGroup(
            layout.createParallelGroup(org.jdesktop.layout.GroupLayout.LEADING)
            .add(layout.createSequentialGroup()
                .add(layout.createParallelGroup(org.jdesktop.layout.GroupLayout.LEADING)
                    .add(layout.createSequentialGroup()
                        .add(108, 108, 108)
                        .add(warningLabel))
                    .add(layout.createSequentialGroup()
                        .addContainerGap()
                        .add(sePanel, org.jdesktop.layout.GroupLayout.PREFERRED_SIZE, org.jdesktop.layout.GroupLayout.DEFAULT_SIZE, org.jdesktop.layout.GroupLayout.PREFERRED_SIZE)))
                .addContainerGap(12, Short.MAX_VALUE))
        );
        layout.setVerticalGroup(
            layout.createParallelGroup(org.jdesktop.layout.GroupLayout.LEADING)
            .add(org.jdesktop.layout.GroupLayout.TRAILING, layout.createSequentialGroup()
                .addContainerGap(12, Short.MAX_VALUE)
                .add(sePanel, org.jdesktop.layout.GroupLayout.PREFERRED_SIZE, org.jdesktop.layout.GroupLayout.DEFAULT_SIZE, org.jdesktop.layout.GroupLayout.PREFERRED_SIZE)
                .addPreferredGap(org.jdesktop.layout.LayoutStyle.RELATED)
                .add(warningLabel))
        );

        pack();
    }// </editor-fold>//GEN-END:initComponents
    
    /**
     * @param args the command line arguments
     */
    public static void main(String args[]) {
        java.awt.EventQueue.invokeLater(new Runnable() {
            public void run() {
                new BBSStepInputDialog(null, true,null,null).setVisible(true);
            }
        });
    }
    /**
     * Closes the dialog
     */
    public void closeDialog(){
        this.setVisible(false);
    }
    
    // Variables declaration - do not modify//GEN-BEGIN:variables
    private nl.astron.lofar.sas.otbcomponents.bbs.stepmanagement.BBSStepExplorerPanel sePanel;
    private javax.swing.JLabel warningLabel;
    // End of variables declaration//GEN-END:variables
    
}
