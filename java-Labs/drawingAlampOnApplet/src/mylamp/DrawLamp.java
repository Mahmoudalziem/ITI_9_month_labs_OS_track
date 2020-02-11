/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
 
package mylamp;
import java.applet.Applet;  
import java.awt.*; 
import sun.reflect.generics.tree.Tree;
/**
 *
 * @author Taha CompuTech
 */
public class DrawLamp extends Applet implements Runnable
{
    Thread th;
 
    int i=0;
    
    Color[] c = {Color.CYAN , Color.GRAY ,Color.GREEN};
    Color getcolorr;
    @Override
    public void init() {
       
        th = new Thread(this);
        th.start();
    }
    
    private Color getlightColor()
    { 
        if(i > 2)
             i = 0;
        return c[i];
    }
    
     public void paint(Graphics g)
        {  
     
            g.drawOval(500, 50, 220, 34);
            g.drawLine(500, 70 , 465, 204);
            g.drawLine(720, 70 , 759, 204);
            g.drawArc(465, 170, 294, 60, 0, -180);
            g.drawLine(590, 230, 570, 320);
            g.drawLine(630, 230, 650, 320);
            g.drawRect(505, 318, 210, 20);
            
            getcolorr = getlightColor();
            g.setColor(getcolorr);
            g.fillOval(520, 100, 30, 100);
            g.fillOval(580, 100, 65, 100);
            g.fillOval(675, 100, 30, 100); 

        }
     
     public void run(){
         while(true){
             
                 repaint();
                try{
                 Thread.sleep(1000);
                }catch(InterruptedException e)
                {
                    e.printStackTrace();
                }
                 i++;
         }
     }
     
     
}

