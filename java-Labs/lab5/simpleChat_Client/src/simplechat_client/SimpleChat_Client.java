/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package simplechat_client;

import com.sun.security.ntlm.Client;
import java.io.DataInputStream;
import java.io.IOException;
import java.io.PrintStream;
import java.net.Socket;
import java.util.logging.Level;
import java.util.logging.Logger;

/**
 *
 * @author Taha CompuTech
 */
public class SimpleChat_Client {
   
    Socket mySocket;
    DataInputStream dis;
    PrintStream ps;
    
    public static void main(String[] args) {
        
        new SimpleChat_Client();
    }
    
   public SimpleChat_Client()
    {
        try{
            
            mySocket = new Socket("127.0.0.1" , 5005);
            dis = new DataInputStream(mySocket.getInputStream());//Returns an input stream for this socket.
            ps = new PrintStream(mySocket.getOutputStream());
            
            ps.println("Hi");
            String repMsg = dis.readLine();
            System.out.println(repMsg);
            
        } catch (IOException ex) {
            Logger.getLogger(SimpleChat_Client.class.getName()).log(Level.SEVERE, null, ex);
        }
        
        try {
            ps.close();
            dis.close();
            mySocket.close();
        } catch (Exception ex) {
            
            ex.printStackTrace();
        }
    }
    
}
