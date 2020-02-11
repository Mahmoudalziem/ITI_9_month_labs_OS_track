/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package chatroom_client;

/**
 *
 * @author shimaa 
 */
public class MainMethod {

    public static void main(String[] args) {

        ClientController client1 = new ClientController();

        SampleUI ui = new SampleUI();
        ui.setSize(400, 500);
        ui.setVisible(true);

        ui.setClientController(client1);
        client1.setUiRef(ui);
    }
}
