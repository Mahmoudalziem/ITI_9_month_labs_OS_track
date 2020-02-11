/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package mypkg;


import static java.util.Collections.list;
import javafx.application.Application;
import javafx.scene.Scene;
import javafx.scene.effect.Reflection;
import javafx.scene.layout.StackPane;
import javafx.scene.paint.Color;
import javafx.scene.paint.CycleMethod;
import javafx.scene.paint.LinearGradient;
import javafx.scene.paint.Stop;
import javafx.scene.shape.Rectangle;
import javafx.scene.text.Font;
import javafx.scene.text.FontWeight;
import javafx.scene.text.Text;
import javafx.stage.Stage;

/**
 *
 * @author Taha CompuTech
 */
public class HelloWorld extends Application{

    @Override
    public void init() throws Exception {
        super.init(); //To change body of generated methods, choose Tools | Templates.
    }

     

    @Override
    public void start(Stage stage) throws Exception {
       // throw new UnsupportedOperationException("Not supported yet."); //To change body of generated methods, choose Tools | Templates.
       
       Text helloWorld = new Text("Hello World");
       
       helloWorld.setX(80);  
       helloWorld.setY(20);  
       helloWorld.setFont(Font.font("Abyssinica SIL",FontWeight.BOLD,25));  
    
       helloWorld.setFill(Color.BLACK);
  
        StackPane rootStack = new StackPane();
        Rectangle rectangle = new Rectangle(900 , 900);
        rootStack.getChildren().addAll(rectangle , helloWorld);
        
        Scene scene = new Scene(rootStack ,900 , 900);
        
       
        scene.getStylesheets().add(getClass().getResource("style.css").toString());
        //rectangle.setId("reclangle");
       
        Reflection ref = new Reflection();  
        ref.setBottomOpacity(0.2);  
        ref.setFraction(12);  
        ref.setTopOffset(8);  
        ref.setTopOpacity(0.2);  
        helloWorld.setEffect(ref);
        rectangle.setId("rectangle");
        
      
       
        stage.setScene(scene);
        stage.show();
        
    }
    
   public static void main(String[] args) {
        
       Application.launch(args);
    }
    
}
