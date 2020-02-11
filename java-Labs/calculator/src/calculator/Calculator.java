/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package calculator;

/**
 *
 * @author shimaa CompuTech
 */
public class Calculator {

    /**
     *
     * @param args
     */
    public static void main(String[] args) 
    {
         int res=0;
        for(int i= 0; i< args.length ; i++)
        {
            
            int x=Integer.parseInt(args[0]);
            int y=Integer.parseInt(args[2]);

            switch(args[1])
                {
                    case "+":
                        res = x+y;
                        break;
                    case "-":
                        res = x-y;
                        break; 
                    case "*":
                        res = x*y;
                        break; 
                    case "/":
                        res = x/y;
                        break; 
                }


       }
        System.out.println("result = " + res);
    }
}
    

