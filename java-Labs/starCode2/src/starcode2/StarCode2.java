/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package starcode2;


public class StarCode2 {

    public static void main(String[] args) {
        
        int num = 6;
        
        for(int i = 1 ; i < num ; i++)
            {
                for(int x=0 ; x <= num-i ; x++)
                {
                    System.out.print(" ");
                }
                for(int j = 0 ; j  < i ; j++)
                {
                    System.out.print("* ");
                }
                System.out.println("\n");
            }
           
       }
     
    }
    

