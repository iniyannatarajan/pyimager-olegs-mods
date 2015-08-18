/*
 * ETHStatusPanel.java
 *
 * Copyright (C) 2006
 * ASTRON (Netherlands Foundation for Research in Astronomy)
 * P.O.Box 2, 7990 AA Dwingeloo, The Netherlands, seg@astron.nl
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 *
 * $Id: ETHStatusPanel.java 22306 2012-10-11 12:21:21Z boom $
 */

package nl.astron.lofar.java.sas.otb.rsp.status;

import nl.astron.lofar.sas.otb.jrsp.BoardStatus;

/**
 * A panel that displays the ETH status data. This panel is used by the
 * StatusPanel.
 *
 * @author  balken
 */
public class ETHStatusPanel extends javax.swing.JPanel {
    
    /** Messages for last error */
    String[] lastErrorMessages = {"The ethernet frame was received correctly",
                                  "Preamble had other value than 0xAA",
                                  "Frame delimiter had other value than 0xAB",
                                  "Not enough preamble nibbles",
                                  "Frame ended during frame header",
                                  "Calculated CRC does not match received CRC",
                                  "An odd number of nibbles was received from ethernet",
                                  "Length specified in the frame size field does not match the real number of received bytes"};
    
    /** 
     * Creates new form ETHStatusPanel.
     */
    public ETHStatusPanel() 
    {
        initComponents();
    }

    public void setFields(BoardStatus boardStatus)
    {
        if (boardStatus != null) {
            txtNofFrames.setText(Integer.toString(boardStatus.nofFrames));
            txtNofErrors.setText(Integer.toString(boardStatus.nofErrors));
            txtLastError.setText(lastErrorMessages[boardStatus.lastError]);
        } else {
            txtNofFrames.setText("");
            txtNofErrors.setText("");
            txtLastError.setText("");
        }
    }
    
    /** This method is called from within the constructor to
     * initialize the form.
     * WARNING: Do NOT modify this code. The content of this method is
     * always regenerated by the Form Editor.
     */
    // <editor-fold defaultstate="collapsed" desc=" Generated Code ">//GEN-BEGIN:initComponents
    private void initComponents() {
        lblNofFrames = new javax.swing.JLabel();
        lblNofErrors = new javax.swing.JLabel();
        lblLastError = new javax.swing.JLabel();
        txtNofFrames = new javax.swing.JTextField();
        txtNofErrors = new javax.swing.JTextField();
        txtLastError = new javax.swing.JTextField();

        setBorder(javax.swing.BorderFactory.createTitledBorder("ETH"));
        lblNofFrames.setText("Nof Frames");

        lblNofErrors.setText("Nof Errors");

        lblLastError.setText("Last Error");

        txtNofFrames.setEditable(false);
        txtNofFrames.setHorizontalAlignment(javax.swing.JTextField.RIGHT);

        txtNofErrors.setEditable(false);
        txtNofErrors.setHorizontalAlignment(javax.swing.JTextField.RIGHT);

        txtLastError.setEditable(false);

        org.jdesktop.layout.GroupLayout layout = new org.jdesktop.layout.GroupLayout(this);
        this.setLayout(layout);
        layout.setHorizontalGroup(
            layout.createParallelGroup(org.jdesktop.layout.GroupLayout.LEADING)
            .add(org.jdesktop.layout.GroupLayout.TRAILING, layout.createSequentialGroup()
                .add(43, 43, 43)
                .add(layout.createParallelGroup(org.jdesktop.layout.GroupLayout.TRAILING, false)
                    .add(lblLastError)
                    .add(lblNofFrames)
                    .add(org.jdesktop.layout.GroupLayout.LEADING, layout.createSequentialGroup()
                        .add(8, 8, 8)
                        .add(lblNofErrors, org.jdesktop.layout.GroupLayout.DEFAULT_SIZE, org.jdesktop.layout.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE)))
                .addPreferredGap(org.jdesktop.layout.LayoutStyle.RELATED, org.jdesktop.layout.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE)
                .add(layout.createParallelGroup(org.jdesktop.layout.GroupLayout.TRAILING, false)
                    .add(txtNofFrames)
                    .add(txtNofErrors)
                    .add(txtLastError, org.jdesktop.layout.GroupLayout.PREFERRED_SIZE, 282, org.jdesktop.layout.GroupLayout.PREFERRED_SIZE))
                .addContainerGap())
        );
        layout.setVerticalGroup(
            layout.createParallelGroup(org.jdesktop.layout.GroupLayout.LEADING)
            .add(layout.createSequentialGroup()
                .add(layout.createParallelGroup(org.jdesktop.layout.GroupLayout.BASELINE)
                    .add(lblNofFrames)
                    .add(txtNofFrames, org.jdesktop.layout.GroupLayout.PREFERRED_SIZE, org.jdesktop.layout.GroupLayout.DEFAULT_SIZE, org.jdesktop.layout.GroupLayout.PREFERRED_SIZE))
                .addPreferredGap(org.jdesktop.layout.LayoutStyle.RELATED)
                .add(layout.createParallelGroup(org.jdesktop.layout.GroupLayout.BASELINE)
                    .add(txtNofErrors, org.jdesktop.layout.GroupLayout.PREFERRED_SIZE, org.jdesktop.layout.GroupLayout.DEFAULT_SIZE, org.jdesktop.layout.GroupLayout.PREFERRED_SIZE)
                    .add(lblNofErrors))
                .addPreferredGap(org.jdesktop.layout.LayoutStyle.RELATED)
                .add(layout.createParallelGroup(org.jdesktop.layout.GroupLayout.BASELINE)
                    .add(lblLastError)
                    .add(txtLastError, org.jdesktop.layout.GroupLayout.PREFERRED_SIZE, org.jdesktop.layout.GroupLayout.DEFAULT_SIZE, org.jdesktop.layout.GroupLayout.PREFERRED_SIZE))
                .addContainerGap(17, Short.MAX_VALUE))
        );
    }// </editor-fold>//GEN-END:initComponents
    
    
    // Variables declaration - do not modify//GEN-BEGIN:variables
    private javax.swing.JLabel lblLastError;
    private javax.swing.JLabel lblNofErrors;
    private javax.swing.JLabel lblNofFrames;
    private javax.swing.JTextField txtLastError;
    private javax.swing.JTextField txtNofErrors;
    private javax.swing.JTextField txtNofFrames;
    // End of variables declaration//GEN-END:variables
    
}
