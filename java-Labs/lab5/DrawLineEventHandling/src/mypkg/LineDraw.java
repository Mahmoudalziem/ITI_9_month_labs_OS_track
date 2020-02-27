/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package mypkg;

import java.awt.Color;
import java.awt.Dimension;
import java.awt.Graphics;
import java.awt.Point;
import java.awt.event.MouseAdapter;
import java.awt.event.MouseEvent;
import java.awt.event.MouseListener;
import java.awt.event.MouseMotionListener;
import javax.swing.JApplet;

/**
 *
 * @author Taha CompuTech
 */
public class LineDraw extends JApplet {
    
    int x1, y1, x2, y2;
    
    public void init() {
        
        MouseAdapter adapter = new MouseAdapter() {
            
            public void mousePressed(MouseEvent e) {
                x1 = e.getX();
                y1 = e.getY();
            }

            public void mouseReleased(MouseEvent e) {
                
            }
            
            @Override
            public void mouseDragged(MouseEvent me) {
                //throw new UnsupportedOperationException("Not supported yet."); //To change body of generated methods, choose Tools | Templates.
                
                x2 = me.getX();
                y2 = me.getY();
                clear();
                repaint();
            }
            
            @Override
            public void mouseMoved(MouseEvent me) {
                //throw new UnsupportedOperationException("Not supported yet."); //To change body of generated methods, choose Tools | Templates.
                
            }
            
        };
        
        this.addMouseListener(adapter);
        this.addMouseMotionListener(adapter);
        
    }

    public void clear() {
        
        Graphics g = getGraphics();
        
        Dimension d = getSize();
        
        Color c = getBackground();
        
        g.setColor(c);
        
        g.fillRect(0, 0, d.width, d.height);

        //repaint();
    }

    public void paint(Graphics g) {
        
        g.drawLine(x1, y1, x2, y2);
        
    }
    
}
