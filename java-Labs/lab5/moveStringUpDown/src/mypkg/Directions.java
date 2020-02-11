/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package mypkg;

import java.awt.Color;
import java.awt.Dimension;
import java.awt.Graphics;
import java.awt.event.KeyEvent;
import java.awt.event.KeyListener;
import javax.swing.JApplet;

/**
 *
 * @author Taha CompuTech
 */
public class Directions extends JApplet{
    
    int x , y;

    @Override
    public void init() {
        setFocusable(true);
        requestFocusInWindow();
      
       x = 50;
       y = 100;
       
       
       this.addKeyListener(new KeyListener(){
           
                            @Override
                            public void keyTyped(KeyEvent ke) {
                             //   throw new UnsupportedOperationException("Not supported yet."); //To change body of generated methods, choose Tools | Templates.

                            }

                            @Override
                            public void keyPressed(KeyEvent ke) {
                                //throw new UnsupportedOperationException("Not supported yet."); //To change body of generated methods, choose Tools | Templates.
                                switch(ke.getKeyCode())
                                {
                                    case KeyEvent.VK_DOWN :    //down

                                             if(y == getHeight())
                                                 y = 0;
                                             y++;
                                             clear();
                                             repaint();
                                             break;
                                      
                                     case KeyEvent.VK_UP :    //up

                                             if(y == 0)
                                                 y = getHeight();
                                    
                                              y--;
                                              clear();
                                             repaint();
                                             break;
                                            
                                          case KeyEvent.VK_LEFT :    //left

                                             if(x == 0)
                                                 x = getWidth();
                                             
                                             x--;
                                             clear();
                                             repaint();
                                             break;
                                             
                                                                                         
                                          case KeyEvent.VK_RIGHT :    //right

                                             if(x == getWidth())
                                                 x = 0;
                                             
                                             x++;
                                             clear();
                                             repaint();
                                             break;

                                }
                            }

                            @Override
                            public void keyReleased(KeyEvent ke) {
                              //  throw new UnsupportedOperationException("Not supported yet."); //To change body of generated methods, choose Tools | Templates.
                            }
       });
     
       
    }
    public void clear() {

        Graphics g = getGraphics();

        Dimension d = getSize();

        Color c = getBackground();

        g.setColor(c);

        g.fillRect(0, 0, d.width, d.height);

        //repaint();
    }

    @Override
    public void paint(Graphics g) {
        
        g.drawString("java", x, y);
       
    }
    
    
    
    
}
