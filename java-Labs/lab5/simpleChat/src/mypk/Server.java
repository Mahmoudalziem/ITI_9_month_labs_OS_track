/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package mypk;

import java.io.DataInputStream;
import java.io.IOException;
import java.io.PrintStream;
import java.net.ServerSocket;
import java.net.Socket;
import java.util.logging.Level;
import java.util.logging.Logger;

/**
 *
 * @author Taha CompuTech
 */
public class Server {
    
    ServerSocket myServerSocket;
    Socket s;
    DataInputStream dis;
    PrintStream ps;
    
    public static void main(String[] args)
    {
        new Server();
    }
    
    public Server()
    {
        try{
            myServerSocket = new ServerSocket(5005);
            s = myServerSocket.accept();
            dis = new DataInputStream(s.getInputStream());//Returns an input stream for this socket.
            ps = new PrintStream(s.getOutputStream());
            String msg = dis.readLine();
            System.out.println(msg);
            ps.println("by");
                    
        } catch (IOException ex) {
               ex.printStackTrace();
        }
        
        try {
            ps.close();
            dis.close();
            s.close();
            myServerSocket.close();
        } catch (Exception ex) {
            ex.printStackTrace();
        }
    }
    
}
