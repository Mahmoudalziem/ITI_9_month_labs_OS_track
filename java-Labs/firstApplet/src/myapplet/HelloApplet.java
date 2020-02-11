/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package myapplet;

import java.applet.Applet;
import java.awt.Color;
import java.awt.Font;
import java.awt.Graphics;
import java.awt.Toolkit;

/**
 *
 * @author Taha CompuTech
 */
public class HelloApplet extends Applet {
    
   private String fontKit[];
   

    @Override
    public void init() {
        
        super.init(); 
        fontKit = Toolkit.getDefaultToolkit().getFontList();
        
    }

    @Override
    public void paint(Graphics g) {
        for(int i=0; i<fontKit.length ;i++)
        {
            Font imFont = new Font(fontKit[i], Font.BOLD, 9);
            g.setFont(imFont);
            g.setColor(Color.red);
            g.drawString("Hello java", 50, 100+ i* 10);
        }
    }
   
   
   
    
}
