/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package chatroom_client;

import java.awt.FlowLayout;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.IOException;
import javax.swing.JButton;
import javax.swing.JFrame;
import javax.swing.JScrollPane;
import javax.swing.JTextArea;
import javax.swing.JTextField;

public class SampleUI extends JFrame {

    private ClientController mClientController;
    JTextArea ta;
    String str;

    public void setClientController(ClientController client){
        mClientController = client;
    }
    
    public void displayIncomingMsg(String str1)
    {
        System.out.println("clientGUI recived: " + str1);
        ta.append(str1+ "\n");
    }
  /*  public void displayIncomingMsg(String str1)
    {
        System.out.println("clientGUI recived: " + str1);
        ta.append(str1+ "\n");
    }
    */
    
    public SampleUI() {
        this.setLayout(new FlowLayout());
        ta = new JTextArea(5, 50);
        ta.setLineWrap(true);
        ta.setWrapStyleWord(true);
        
        JScrollPane scroll = new JScrollPane(ta);
        scroll.setViewportView(ta);
        JTextField tf = new JTextField(50);
        JButton okButton = new JButton("Send");
        okButton.addActionListener(new ActionListener() {
            public void actionPerformed(ActionEvent ae) {
                str = tf.getText();
                ta.append(str + "\n");
                tf.setText("");
                 mClientController.sendToServer(str);
            }
        });
        add(scroll);
        add(tf);
        add(okButton);
        
        setSize(800, 600);
        pack();
        setLocationByPlatform(true);
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        try{
            FileInputStream fis = new FileInputStream("E:\\Local Disk\\ITI - 9 month\\Java\\projects\\lab5\\ChatRoomApp\\ChatRoom_Server\\save.txt");
            int size = fis.available();
            byte[] b = new byte[size];
            fis.read(b);
            ta.setText(new String(b));
            fis.close();
         
        }catch(IOException ex){
            ex.printStackTrace();
        }
    }

  

}
