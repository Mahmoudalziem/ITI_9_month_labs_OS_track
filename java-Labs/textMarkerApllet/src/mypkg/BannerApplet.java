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
public class BannerApplet extends Applet implements Runnable{
        Thread th;
        int x, y;
        String str = "java world";
    @Override
    public void init() {
        x = 50;
        y = 100;
        th = new Thread(this);
        th.start();
    }

    @Override
    public void paint(Graphics g) {
        
        for(int i = 0;i< str.length() ;i++ )
        {
        g.drawString(String.valueOf(str.charAt(i)),(x+i*10)%getWidth(),y);
        }
        
    }
    public void run(){
        while(true){
            x +=10;
            repaint();
            try{
            Thread.sleep(300);
            }catch(InterruptedException e)
            {
                e.printStackTrace();
            }
           
          
        }
    }
    
}
