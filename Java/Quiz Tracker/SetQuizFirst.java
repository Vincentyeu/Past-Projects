/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package com.mycompany.quiztracker;

import java.awt.BorderLayout;
import java.awt.CardLayout;
import java.awt.Color;
import java.awt.Font;
import java.awt.GridLayout;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import javax.swing.ImageIcon;
import javax.swing.JButton;
import javax.swing.JCheckBox;
import javax.swing.JLabel;
import javax.swing.JPanel;
import javax.swing.JTextField;
import javax.swing.Timer;

public class SetQuizFirst extends JPanel implements ActionListener {
    private JLabel logo, lbquizname, lbquizcode, lbcreator, status;
    private JTextField tfquizname, tfquizcode, tfquizcreator;
    private JCheckBox cb1;
    private JButton btnsave,btnback;
    private Timer delayTimer;
    private String code;

    private String lecturerName;

    public SetQuizFirst() {
        //Font font1 = new Font("Verdana", Font.ITALIC + Font.BOLD, 60);

        ImageIcon image1 = new ImageIcon(getClass().getResource("image/logo.png"));
        logo = new JLabel(image1);

        lbquizname = new JLabel("Quiz Name:");    //define for each JLabel elements
        tfquizname = new JTextField(20);
        lbquizcode = new JLabel("Quiz Code:");
        tfquizcode = new JTextField(20);
        lbcreator = new JLabel("Creator:"); 
        tfquizcreator = new JTextField(20);
        tfquizcreator.setEditable(false);  //The creator field is not allowed to enter 
        //tfquizcreator.setText(lecturerName);
        
        //subpanel of Panel 1
        JPanel p1_2 = new JPanel();   
        p1_2.setLayout(new GridLayout(3, 2));   
        p1_2.setBackground(Color.WHITE);
        p1_2.add(lbquizname);    //Panel to let lecturer to key-in quizname,quizcode
        p1_2.add(tfquizname);
        p1_2.add(lbquizcode);
        p1_2.add(tfquizcode);
        p1_2.add(lbcreator);
        p1_2.add(tfquizcreator);
        
        //Panel 1
        JPanel p1 = new JPanel();
        p1.setLayout(new GridLayout(2, 1));  
        p1.setBackground(Color.WHITE);
        p1.add(logo);  //add the logo and subpanel into panel 1
        p1.add(p1_2);

        status = new JLabel();

        cb1 = new JCheckBox("Confirm create quiz");

        btnsave = new JButton("Save");
        btnsave.setBackground(Color.YELLOW);
        btnsave.setFont(btnsave.getFont().deriveFont(Font.BOLD, 20));  //set the font style
        
        btnback = new JButton("Back");
        btnback.setBackground(Color.YELLOW);
        btnback.setFont(btnback.getFont().deriveFont(Font.BOLD, 20));  //set the font style
        
        //button panel to carry the button
        //JPanel buttonPanel = new JPanel();
        //buttonPanel.setLayout(new GridLayout(1, 1)); // Use GridLayout with 1 row and 1 column for the button panel
        //buttonPanel.add(btnsave); // Add the button to the button panel
        
        //Panel 2 to carry the checkbox and the button
        JPanel p2 = new JPanel();
        p2.setLayout(new GridLayout(3, 1));
        p2.setBackground(Color.WHITE);
        p2.add(cb1);
        p2.add(btnsave); // Add the button panel to the main panel
        p2.add(btnback);

        // the main layout
        setLayout(new BorderLayout());  
        setBackground(Color.WHITE); // Set background color to white
        add(p1, BorderLayout.NORTH);
        add(status, BorderLayout.CENTER);
        add(p2, BorderLayout.SOUTH);

        btnsave.addActionListener(this);  //add action listener to the btnsave
        btnback.addActionListener(this);  //add action listener to the btnback

       
    }

    public void actionPerformed(ActionEvent e) {
        String Q_name, Q_code, Q_creator, text = "Quiz Created Successfully";
        int input;
        boolean proceed = false;

        if (e.getSource() == btnsave) {
            Q_name = tfquizname.getText();
            Q_code = tfquizcode.getText();

            code = Q_code; //save the quiz code to later pass to set quiz question page

            if (Q_name.isEmpty() || Q_code.isEmpty() ) {
                status.setText("Please enter all the fields.");
                status.setForeground(Color.RED);
            } else {
                // check whether user checked the checkbox
                if (!cb1.isSelected()) {
                    status.setText("Please check the checkbox to confirm creating your quiz.");
                    status.setForeground(Color.RED);
                } else {
                    try {
                        input = Integer.parseInt(Q_code);
                        
                        if (input <= 0) 
                        {
                            throw new IllegalArgumentException();//if number of question is smaller than 0 or equal 0, throw exception
                        }
                        
                        FileWriter file1 = new FileWriter("src/quizlist.txt", true);
                        PrintWriter pw = new PrintWriter(file1);
                        pw.write(Q_name);
                        pw.write("\n");
                        pw.write(Q_code);
                        pw.write("\n");
                        pw.write(lecturerName);
                        pw.write("\n");
                        pw.write("\n");
                        pw.close();

                        FileWriter file2 = new FileWriter("src/quizcode.txt", true);
                        PrintWriter pw2 = new PrintWriter(file2);
                        pw2.write(Q_code);
                        pw2.write("\n");
                        pw2.close();

                        FileWriter file3 = new FileWriter("src/" + Q_code + ".txt", true);
                        PrintWriter pw3 = new PrintWriter(file3);
                        pw3.close();

                        proceed = true;
                    } catch (IOException event) {
                        status.setText("Quiz creation unsuccessful.");
                        status.setForeground(Color.RED);
                        event.printStackTrace();
                    } catch (IllegalArgumentException ex) {//catch exception where user enter number smaller than 0 or equal to 0 for number of questions
                        status.setText("Quiz code must be integers.");
                        status.setForeground(Color.RED);
            }
                        
                }

                if (proceed) 
                {
                    // Create and configure the set question dialog
                    SetQuiz questionDialog = new SetQuiz();
                    questionDialog.setCode(code);//pass quiz code to set quiz questions page
                    questionDialog.setVisible(true);
                }
            }
        }
         if (e.getSource() == btnback) 
         {
             CardLayout cardLayout = (CardLayout) getParent().getLayout();
             LecturerPanel lecturerPanel = (LecturerPanel) getParent().getComponent(2);
            cardLayout.show(getParent(), "lecturerPage");
         }
    }

    public void setLecturerName(String lecturerName) {
        this.lecturerName = lecturerName;
        //lbcreator.setText("Hii " + lecturerName); // Update the lbcreator label with the lecturerName
        tfquizcreator.setText(lecturerName);
    }
}
