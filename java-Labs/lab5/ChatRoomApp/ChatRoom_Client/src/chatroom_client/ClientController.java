/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package chatroom_client;

import java.awt.event.ActionEvent;
import java.io.DataInputStream;
import java.io.FileInputStream;
import java.io.IOException;
import java.io.PrintStream;
import java.net.Socket;
import java.util.Vector;
import javax.imageio.stream.FileImageInputStream;

public class ClientController {

    DataInputStream dis;
    PrintStream ps;

    String str;
    Socket mySocket;
    SampleUI mSampleUI;

    public ClientController() {

        try {

            mySocket = new Socket("127.0.0.1", 5005);
            dis = new DataInputStream(mySocket.getInputStream());
            ps = new PrintStream(mySocket.getOutputStream());

        } catch (Exception e) {
            e.printStackTrace();
        }
        /*
        okButton.addActionListener(new ActionListener() {
            public void actionPerformed(ActionEvent e) {

                str = tf.getText();
                ps.println(str);
                tf.setText(" ");

            }

        }
         */

        new Thread(new Runnable() {

            public void run() {

                while (true) {
                    try {
                       // FileInputStream fis = new FileInputStream("save.txt");
                        
                        str = dis.readLine();
                        System.out.println("client recived: " + str);
                        mSampleUI.displayIncomingMsg(str);
                    } catch (IOException e) {
                        e.printStackTrace();
                    }

                }
            }

        }).start();
    }

    void sendToServer(String str) {

        if (ps != null) {
            ps.println(str);
            System.out.println("client sent: " + str);
        }
    }

    public void setUiRef(SampleUI ui) {
        mSampleUI = ui;
    }
}
