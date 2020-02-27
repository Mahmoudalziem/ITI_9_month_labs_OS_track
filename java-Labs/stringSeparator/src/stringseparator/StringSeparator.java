/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package stringseparator;

import java.util.StringTokenizer;


public class StringSeparator {


    public static void main(String[] args) {
      
     String ip = "163.132.12.3";
     String[] arr =ip.split("\\.");
     
     for(String value : arr)
     {
         System.out.println(value + "\n");
     }
     
     
        StringTokenizer st = new StringTokenizer(ip , ".");
        while(st.hasMoreElements())
        {
            System.out.println(st.nextElement());
        }
        
     }
     
    }
    

