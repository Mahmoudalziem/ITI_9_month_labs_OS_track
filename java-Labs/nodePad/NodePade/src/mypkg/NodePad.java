/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package mypkg;

import java.io.BufferedWriter;
import java.io.DataInputStream;
import java.io.DataOutputStream;
import java.io.File;
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.FileOutputStream;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.logging.Level;
import java.util.logging.Logger;
import javafx.application.Application;
import javafx.application.Platform;
import javafx.event.ActionEvent;
import javafx.event.EventHandler;
import javafx.geometry.Orientation;
import javafx.geometry.Pos;
import javafx.scene.Scene;
import javafx.scene.control.Button;
import javafx.scene.control.Label;
import javafx.scene.control.Menu;
import javafx.scene.control.MenuBar;
import javafx.scene.control.MenuItem;
import javafx.scene.control.Separator;
import javafx.scene.control.SeparatorMenuItem;
import javafx.scene.control.TextArea;
import javafx.scene.control.TitledPane;
import javafx.scene.input.KeyCombination;
import javafx.scene.layout.Border;
import javafx.scene.layout.BorderPane;
import javafx.scene.layout.FlowPane;
import javafx.stage.FileChooser;
import javafx.stage.Stage;
import javax.tools.JavaCompiler;
import javax.tools.ToolProvider;

/**
 *
 * @author Taha CompuTech
 */
public class NodePad extends Application {

    BorderPane pane;
    Scene scene;

    TextArea textArea;
    MenuBar menuBar;
    Menu file;
    Menu edit;
    Menu help;

    SeparatorMenuItem separator1;
    SeparatorMenuItem separator2;
    SeparatorMenuItem separator3;

    MenuItem fileNew;
    MenuItem fileOpen;
    MenuItem fileSave;
    MenuItem fileExit;

    MenuItem editUndo;
    MenuItem editCut;
    MenuItem editCopy;
    MenuItem editPast;
    MenuItem editDelete;
    MenuItem editSelectAll;

    MenuItem helpAboutNotePad;
     MenuItem helpCompile;

    FileChooser chooser;
    File newFile;

    Button okButton;

    @Override
    public void init() throws Exception {
        super.init();

        // TitledPane pane = new TitledPane("Fx NodePad", node);
        textArea = new TextArea();
        pane = new BorderPane();
        scene = new Scene(pane, 400, 500);

        menuBar = new MenuBar();

        file = new Menu("File");
        edit = new Menu("Edit");
        help = new Menu("Help");

        fileNew = new MenuItem("New");
        fileOpen = new MenuItem("Open");
        fileSave = new MenuItem("Save");
        fileExit = new MenuItem("Exit");

        editUndo = new MenuItem("Undo");
        editCut = new MenuItem("Cut");
        editCopy = new MenuItem("Copy");
        editPast = new MenuItem("Past");
        editDelete = new MenuItem("Delete");
        editSelectAll = new MenuItem("Select All");

        separator1 = new SeparatorMenuItem();
        separator2 = new SeparatorMenuItem();
        separator3 = new SeparatorMenuItem();

        helpAboutNotePad = new MenuItem("About NotePad");
        helpCompile = new MenuItem("Compile");

        chooser = new FileChooser();
        newFile = new File("newFile.java");

    }

    @Override
    public void start(Stage primarystage) {
        try {

            textArea.setPromptText("Enter The text");
            fileNew.setAccelerator(KeyCombination.keyCombination("Ctrl+n"));

            file.getItems().addAll(fileNew, fileOpen, fileSave,separator1, fileExit);
            edit.getItems().addAll(editUndo,separator2, editCopy, editCut, editPast, editDelete,separator3, editSelectAll);
            help.getItems().addAll(helpCompile,helpAboutNotePad );
            menuBar.getMenus().addAll(file, edit, help);

            pane.setTop(menuBar);
            pane.setCenter(textArea);

            fileNew.setOnAction(new EventHandler<ActionEvent>() {
                @Override
                public void handle(ActionEvent event) {
                    textArea.clear();
                }
            });
            fileOpen.setOnAction(new EventHandler<ActionEvent>() {
                @Override
                public void handle(ActionEvent event) {
                    chooser.setTitle("Select File");
                    FileChooser.ExtensionFilter extFilter = new FileChooser.ExtensionFilter("*", "*");
                    chooser.getExtensionFilters().add(extFilter);

                    File file = chooser.showOpenDialog(null);
                    if (file != null) {
                        textArea.setText(readFile(file));
                    }

                }
            });
            fileSave.setOnAction(new EventHandler<ActionEvent>() {
                @Override
                public void handle(ActionEvent event) {
                        chooser.setTitle("Save File");
                    FileChooser.ExtensionFilter extFilter = new FileChooser.ExtensionFilter("*", "*");
                    chooser.getExtensionFilters().add(extFilter);

                    File file = chooser.showSaveDialog(primarystage);
                    if (file != null) {
                        saveText(file , textArea.getText());
                    }

                }
            });

            fileExit.setOnAction(new EventHandler<ActionEvent>() {
                @Override
                public void handle(ActionEvent event) {
                    Platform.exit();

                }
            });


                   //undo
        editUndo.setOnAction(new EventHandler<ActionEvent>(){

           @Override
           public void handle(ActionEvent event) {
               //throw new UnsupportedOperationException("Not supported yet."); //To change body of generated methods, choose Tools | Templates.
               textArea.undo();
           }
        });
        //cut
        editCut.setOnAction(new EventHandler<ActionEvent>(){

           @Override
           public void handle(ActionEvent event) {
              // throw new UnsupportedOperationException("Not supported yet."); //To change body of generated methods, choose Tools | Templates.
              textArea.cut();
           }
        });
        //copy
        editCopy.setOnAction(new EventHandler<ActionEvent>(){

           @Override
           public void handle(ActionEvent event) {
               textArea.copy();
           }
        });
        //paste
        editPast.setOnAction(new EventHandler<ActionEvent>(){

           @Override
           public void handle(ActionEvent event) {
               textArea.paste();
           }
        });
        //delete
       editDelete.setOnAction(new EventHandler<ActionEvent>(){

           @Override
           public void handle(ActionEvent event) {
               //throw new UnsupportedOperationException("Not supported yet."); //To change body of generated methods, choose Tools | Templates.

               textArea.setText(textArea.getText().replace(textArea.getSelectedText(), " "));
           }
       });
       //selectAll
       editSelectAll.setOnAction(new EventHandler<ActionEvent>(){

           @Override
           public void handle(ActionEvent event) {
               //throw new UnsupportedOperationException("Not supported yet."); //To change body of generated methods, choose Tools | Templates.
               textArea.selectAll();
           }
       });

       //Compilation
       helpCompile.addEventHandler(ActionEvent.ACTION, new EventHandler<ActionEvent>() {

            @Override
            public void handle(ActionEvent event) {
                JavaCompiler compiler = ToolProvider.getSystemJavaCompiler();
                compiler.run(null,null,null,newFile.getAbsolutePath());

            }
        });

       //help
       helpAboutNotePad.setOnAction( new EventHandler<ActionEvent>() {
                @Override
                public void handle(ActionEvent t) {
                    //throw new UnsupportedOperationException("Not supported yet."); //To change body of generated methods, choose Tools | Templates.
                    new NewStage();

                }
            });

            primarystage.setTitle("FX NodePad");
            primarystage.setScene(scene);
            primarystage.show();

        } catch (Exception e) {
            e.printStackTrace();
        }
    }

class NewStage
     {

              NewStage()
               {
                    Stage subStage = new Stage();
                    okButton = new Button("Ok");
                    Label msg = new Label("the owner of this file is Shimaa\nDate of file creation 12/31/2019");

                    okButton.setOnAction(new EventHandler<ActionEvent>() {
                        @Override
                        public void handle(ActionEvent t) {
                           // throw new UnsupportedOperationException("Not supported yet."); //To change body of generated methods, choose Tools | Templates.
                              subStage.close();
                        }
                    });
                    subStage.setTitle("Help");

                    FlowPane root = new FlowPane(Orientation.VERTICAL, 4.0, 6.0);
                    root.getChildren().add(msg);
                    root.getChildren().add(okButton);

                    root.setAlignment(Pos.CENTER);
                    Scene scene = new Scene(root, 300, 200);



                    subStage.setScene(scene);
                    subStage.show();
                }
      }


    public static void main(String[] args) {

        Application.launch(args);
    }


    public String readFile(File file) {
        String str = "";
        try {
            FileInputStream fis = new FileInputStream(file.getPath());
            DataInputStream dis = new DataInputStream(fis);
            String str1;
            while ((str1 = dis.readLine()) != null) {
                str = str.concat(str1);
                str = str.concat("\n");
            }

        } catch (IOException e) {
            e.printStackTrace();
        }

        return str;

    }
    public void saveText(File file ,String str)
    {
        try{
         FileWriter fileWriter = new FileWriter(file);
			// create file if not exists
			if (!file.exists()) {
				file.createNewFile();
			}
			// initialize BufferedWriter
			 BufferedWriter writer = new BufferedWriter(fileWriter);

                         writer.write(str);
                         writer.write("\n");
                         writer.flush();
                         writer.close();
        }
        catch(IOException e){
            e.printStackTrace();
        }

    }

}
