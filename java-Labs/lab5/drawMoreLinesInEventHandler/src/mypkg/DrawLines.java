/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package mypkg;

import java.awt.Color;
import java.awt.Dimension;
import java.awt.Graphics;
import java.awt.event.MouseAdapter;
import java.awt.event.MouseEvent;
import java.util.Vector;
import javax.swing.JApplet;

/**
 *
 * @author Taha CompuTech
 */
public class DrawLines extends JApplet {
    
        boolean isDragged = false;
        int x1, y1, x2, y2;
        Vector<Line>  v = new Vector<Line>();
        int flag = 0;
    public void init() {
        
        MouseAdapter adapter = new MouseAdapter() {
            
            public void mousePressed(MouseEvent e) {
                x1 = e.getX();
                y1 = e.getY();
            }

            public void mouseReleased(MouseEvent e) {
                
                   
                x2 = e.getX();
                y2 = e.getY();
               if(isDragged)
               {
                    v.add(new Line(x1 , y1 , x2 ,y2));
                  
                    repaint();
                    isDragged = false;
               }
            }
            
            @Override
            public void mouseDragged(MouseEvent me) {
                //throw new UnsupportedOperationException("Not supported yet."); //To change body of generated methods, choose Tools | Templates.
                
                x2 = me.getX();
                y2 = me.getY();
                flag = 1;
                isDragged = true;
                
              //  repaint();
              //  clear();
               
                       
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
        if(flag == 0)
        {
            for( Line l: v )
            {
                 g.drawLine(l.x1 , l.y1 , l.x2 , l.y2);
            }
        }
        else
        {
            g.drawLine(x1 , y1 , x2 , y2);
            flag = 0;
        }
        
    }
    
    public class Line {
        
        int x1 , y1 , x2 , y2;

        public Line(int x1, int y1, int x2, int y2) {
            this.x1 = x1;
            this.y1 = y1;
            this.x2 = x2;
            this.y2 = y2;
        }
        
        
    }
}
