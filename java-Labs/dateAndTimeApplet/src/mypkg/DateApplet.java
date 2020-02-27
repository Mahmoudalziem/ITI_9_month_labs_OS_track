/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package mypkg;

import java.applet.Applet;
import java.awt.Graphics;
import java.util.Date;

/**
 *
 * @author Taha CompuTech
 */
public class DateApplet extends Applet implements Runnable{
  
    Thread th;

    /**
     *
     */
    @Override
    public void init() {
        
        th = new Thread(this);
        th.start();
    }

    /**
     *
     * @param g
     */
    @Override
    public void paint(Graphics g) {
        
        Date d = new Date();
        g.drawString(d.toString(),50, 100);
        
    }

    /**
     *
     */
    public void run(){
        while(true){
            repaint();
            try{
            Thread.sleep(1000);
            }catch(InterruptedException e)
            {
                e.printStackTrace();
            }
        }
    }
 
}
