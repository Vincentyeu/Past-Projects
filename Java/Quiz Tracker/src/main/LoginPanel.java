/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package com.mycompany.quiztracker;

import java.awt.CardLayout;
import java.awt.Color;
import java.awt.Font;
import java.awt.GridBagConstraints;
import java.awt.GridBagLayout;
import java.awt.Insets;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import javax.swing.ImageIcon;
import javax.swing.JButton;
import javax.swing.JLabel;
import javax.swing.JPanel;
import javax.swing.JPasswordField;
import javax.swing.JTextField;
import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import javax.swing.Timer;

public class LoginPanel extends JPanel implements ActionListener {
    private static JLabel userLabel;
    private static JTextField userText;
    private static JLabel passwordLabel;
    private static JPasswordField passwordText;
    private static JButton button;
    private static JLabel success;
    private static JLabel unsuccess;
    private String userType;
    private CardLayout cardLayout;
    public String user;

    public LoginPanel(CardLayout cardLayout) 
    {
        this.cardLayout = cardLayout;
        initComponents();
    }

    private void initComponents() 
    {
        setBackground(Color.WHITE);

        setLayout(new GridBagLayout());

        Font headerFont = new Font("FontName", Font.BOLD, 24);

        JPanel logoPanel = new JPanel(new GridBagLayout());
        logoPanel.setBackground(Color.WHITE); //sets the background color
        GridBagConstraints logoConstraints = new GridBagConstraints();
        logoConstraints.gridx = 0; //set the components to horizantally
        logoConstraints.gridy = 0; //set the components to vertically
        logoConstraints.gridwidth = 2;
        logoConstraints.anchor = GridBagConstraints.CENTER; //component is center within its display area
        logoConstraints.insets = new Insets(10, 0, 20, 0); // represent the space (padding) top, left, bottom, and right
        add(logoPanel, logoConstraints);

        // Add image label
        ImageIcon imageIcon = new ImageIcon(getClass().getResource("image/quiz.png"));
        JLabel imageLabel = new JLabel(imageIcon);
        logoPanel.add(imageLabel);

        JPanel headerPanel = new JPanel(new GridBagLayout());
        headerPanel.setBackground(Color.WHITE); //sets the background color
        GridBagConstraints headerConstraints = new GridBagConstraints();
        headerConstraints.gridx = 0; //set the components to horizantally 
        headerConstraints.gridy = 1; //set the components to vertically
        headerConstraints.gridwidth = 2; 
        headerConstraints.anchor = GridBagConstraints.CENTER; //component is align to the center
        headerConstraints.insets = new Insets(0, 0, 20, 0); // represent the space (padding) top, left, bottom, and right
        add(headerPanel, headerConstraints);

        JLabel headerLabel = new JLabel("Login");
        headerLabel.setFont(headerFont); //set the font of a label
        headerPanel.add(headerLabel);

        JPanel inputPanel = new JPanel(new GridBagLayout());
        inputPanel.setBackground(Color.WHITE); 
        GridBagConstraints inputConstraints = new GridBagConstraints();
        inputConstraints.gridx = 0; 
        inputConstraints.gridy = 2; 
        inputConstraints.anchor = GridBagConstraints.WEST; //component is align to the left side
        inputConstraints.insets = new Insets(0, 10, 0, 0); 
        add(inputPanel, inputConstraints);

        userLabel = new JLabel("Username");
        inputPanel.add(userLabel);

        userText = new JTextField(20);
        inputPanel.add(userText);

        passwordLabel = new JLabel("Password");
        GridBagConstraints passwordLabelConstraints = new GridBagConstraints();
        passwordLabelConstraints.gridx = 0;
        passwordLabelConstraints.gridy = 1;
        passwordLabelConstraints.anchor = GridBagConstraints.WEST; //component is align to the left side
        passwordLabelConstraints.insets = new Insets(10, 10, 0, 0);
        inputPanel.add(passwordLabel, passwordLabelConstraints);

        passwordText = new JPasswordField(20);
        GridBagConstraints passwordTextConstraints = new GridBagConstraints();
        passwordTextConstraints.gridx = 1;
        passwordTextConstraints.gridy = 1;
        passwordTextConstraints.fill = GridBagConstraints.HORIZONTAL; //component expand horizontally
        passwordTextConstraints.insets = new Insets(10, 10, 0, 10);
        inputPanel.add(passwordText, passwordTextConstraints);

        JPanel buttonPanel = new JPanel(new GridBagLayout());
        buttonPanel.setBackground(Color.WHITE);
        GridBagConstraints buttonConstraints = new GridBagConstraints();
        buttonConstraints.gridx = 0;
        buttonConstraints.gridy = 3;
        buttonConstraints.gridwidth = 2;
        buttonConstraints.anchor = GridBagConstraints.CENTER;
        buttonConstraints.insets = new Insets(20, 0, 0, 0);
        add(buttonPanel, buttonConstraints);

        button = new JButton("Login");
        button.addActionListener(this);
        buttonPanel.add(button);

        JPanel messagePanel = new JPanel(new GridBagLayout());
        messagePanel.setBackground(Color.WHITE);
        GridBagConstraints messagePanelConstraints = new GridBagConstraints();
        messagePanelConstraints.gridx = 0;
        messagePanelConstraints.gridy = 4;
        messagePanelConstraints.gridwidth = 2;
        messagePanelConstraints.anchor = GridBagConstraints.CENTER;
        messagePanelConstraints.insets = new Insets(30, 0, 0, 0); // Update the top inset value
        add(messagePanel, messagePanelConstraints);

        success = new JLabel(""); //label is assigned to the success variable
        messagePanel.add(success); //adds the success label to the messagePanel

        unsuccess = new JLabel(""); //label is assigned to the unsuccess variable
        messagePanel.add(unsuccess); //adds the unsuccess label to the messagePanel
    }

    @Override
    public void actionPerformed(ActionEvent ae) {
    user = userText.getText();
    String user2 = user;
    String password = passwordText.getText();

    if (loginSuccessful(user, password, "student.txt", "src") && userType.equals("Student")) //add user type to make sure user choose student in main page
    {
        success.setText("Login Successful");
        success.setForeground(Color.GREEN); // Set success message font color to green
        unsuccess.setText("");

        Timer timer = new Timer(2000, new ActionListener() { // Delay of 2000 milliseconds (2 seconds)
            @Override
            public void actionPerformed(ActionEvent e) {
                success.setText("Welcome Student!");
                cardLayout.show(getParent(), "joinPage");
            }
        });
        timer.setRepeats(false); // Set the timer to run only once
        timer.start();
    } 
    else if (loginSuccessful(user, password, "lecturer.txt", "src")&& userType.equals("Lecturer")) {//add user type to make sure user choose lecturer in main page
        success.setText("Login Successful");
        success.setForeground(Color.GREEN); // Set success message font color to green
        unsuccess.setText("");

        Timer timer = new Timer(2000, new ActionListener() { // Delay of 2000 milliseconds (2 seconds)
            @Override
            public void actionPerformed(ActionEvent e) {
                success.setText("Welcome Lecturer!");
                CardLayout cardLayout = (CardLayout) getParent().getLayout();
                SetQuizFirst createPanel = (SetQuizFirst) getParent().getComponent(3); 
                ViewQuiz viewPanel = (ViewQuiz) getParent().getComponent(4); 
                createPanel.setLecturerName(user2);
               // viewPanel.setLecturerName(user2);
                cardLayout.show(getParent(), "lecturerPage");
            }
        });
        timer.setRepeats(false); // Set the timer to run only once
        timer.start();
    } else {
        unsuccess.setText("Invalid username or password!");
        unsuccess.setForeground(Color.RED); // Set unsuccess message font color to red
        success.setText("");
    }
}


    private boolean loginSuccessful(String username, String password, String filename, String filePath) {
        try (BufferedReader br = new BufferedReader(new FileReader(filePath + "\\" + filename))) //read the contents of a file
        {
            String line;
            while ((line = br.readLine()) != null) 
            {
                String[] parts = line.split(" ");
                String storedUsername = parts[0];
                String storedPassword = parts[1];
                if (username.trim().equals(storedUsername.trim()) && password.trim().equals(storedPassword.trim())) {
                    return true;
                }
            }
        } 
        catch (IOException e) //Handle any potential errors that may occur while reading the file
        {
            e.printStackTrace(); //providing information about the error that occurred
        }
        return false;
    }

    public void setUserType(String userType) 
    {
        this.userType = userType;
    }

    public String getUserType() 
    {
        return userType;
    }
}
