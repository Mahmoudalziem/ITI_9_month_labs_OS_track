/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package myimage;

import java.applet.Applet;
import java.awt.Graphics;
import java.awt.Image;
import java.awt.image.ImageObserver;
import java.awt.image.ImageProducer;

/**
 *
 * @author Taha CompuTech
 */
public class ImageApplet extends Applet{
    
    Image img;

    @Override
    public void init() {
        
       img = getImage(getCodeBase(), "myimage/image11.jpeg");
         
        
        }

    @Override
    public void paint(Graphics g) {
        
        g.drawImage(img,0,0,getWidth(),getHeight(), this);
    }
    
    }
    
     

