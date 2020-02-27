/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package javaapplication15;

/**
 *
 * @author Taha CompuTech
 */
public class JavaApplication15 implements Runnable{

  public void run()
  {
      System.out.println("the thread is running..");
  }
    public static void main(String[] args) {
       JavaApplication15 t1=new JavaApplication15();
        Thread th = new Thread(t1);
        th.start();
                }
    
}
