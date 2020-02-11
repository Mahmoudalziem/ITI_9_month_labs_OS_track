/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package chatroom_server;

import com.sun.xml.internal.ws.util.FastInfosetReflection;
import java.io.DataInputStream;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintStream;
import java.io.PrintWriter;
import java.net.ServerSocket;
import java.net.Socket;
import java.util.Vector;
import jdk.jfr.events.FileWriteEvent;


public class ChatRoom_Server {

    ServerSocket serverSocket;

    public ChatRoom_Server() {
        try {
            serverSocket = new ServerSocket(5005);
            while (true) {
                Socket s = serverSocket.accept();
                System.out.println(s.toString());
                new ChatHandler(s);
            }
        } catch (IOException e) {
            e.printStackTrace();
        }
    }

    public static void main(String[] args) {

        new ChatRoom_Server();
    }

}

class ChatHandler extends Thread {

    DataInputStream dis;
    PrintStream ps;
    final static Vector<ChatHandler> clientsVector = new Vector<ChatHandler>();

    public ChatHandler(Socket cs) {
        try {
            dis = new DataInputStream(cs.getInputStream());
            ps = new PrintStream(cs.getOutputStream());
            clientsVector.add(this);
            start();
        } catch (Exception e) {
            e.printStackTrace();
        }
    }

    @Override
    public void run() {
        try {
            while (true) {
                String str = dis.readLine();
                if(str == null)
                    continue;
                
                System.out.println("client recived: " + str);
                FileWriter fileWriter = new FileWriter("save.txt" ,true);
                PrintWriter ps = new PrintWriter(fileWriter);
                ps.println(str);
                fileWriter.close();
                ps.close();
                sendMessageToAll(str);
                
               
            }
        } catch (Exception e) {
            e.printStackTrace();
            
        }
    }

    public void sendMessageToAll(String msg) {
        for (ChatHandler ch : clientsVector) {
            if(ch != this)
            ch.ps.println(msg);
        }
    }
}
