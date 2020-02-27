/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package mypkg;

import java.applet.Applet;
import java.awt.Button;
import java.awt.Graphics;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

/**
 *
 * @author Taha CompuTech
 */
public class myButtonApplet extends Applet{
    
    int x = 0;
    Button b1;
    Button b2;

    @Override
    public void init(){
       b1 = new Button("increment");    
       b2 = new Button("decrement");
       
       b1.addActionListener(new ActionListener(){
           
                    @Override
                    public void actionPerformed(ActionEvent ev) {
                       if(x < 10)
                            {                        
                                x++;
                                repaint();
                                   
                            }
                    }
       });
       add(b1);
       b2.addActionListener(new  ActionListener(){
           
                        @Override
                        public void actionPerformed(ActionEvent ev) {
                            if(x > 0)
                               {
                                    x--;
                                    repaint();
                               }
        }
    });
       add(b2);
    }                     
    
    @Override
    public void paint(Graphics g){
        g.drawString("Click count is : " + x , 50 , 100);
        
    }
    
   
}
