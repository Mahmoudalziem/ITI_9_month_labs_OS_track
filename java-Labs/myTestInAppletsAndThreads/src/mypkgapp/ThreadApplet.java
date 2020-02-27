/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package mypkgapp;

import java.applet.Applet;
import java.awt.Color;
import java.awt.Graphics;

/**
 *
 * @author Taha CompuTech
 */
public class ThreadApplet extends Applet implements Runnable{
    
    String msg = "this is first eample of my applet with thread class";
    Thread th = null;
    int status;
    Boolean flag;

    @Override
    public void init() {
        
        setBackground(Color.green);
        setBackground(Color.red);
        
    }
    public void start()
        {
                th=new Thread(this);
                flag=false;
                th.start();
        }
    
    public void run()
    {
        char c;
        while(true)
        {
            try{
                repaint();
                Thread.sleep(500);
                c = msg.charAt(0);
                msg = msg.substring(1,msg.length());
                msg += c;
                if(flag)
                    break;
            }catch(Exception e)
            {
                System.out.println(e);
                
            }
        }
 
    }
    
    
        public void stop()
        {
                flag=true;
                th=null;
        }
        public void paint(Graphics g)
        {
                g.drawString(msg,50,50);
        }  
}
