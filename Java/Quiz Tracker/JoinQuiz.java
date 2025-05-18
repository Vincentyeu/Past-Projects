/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package com.mycompany.quiztracker;

import java.awt.BorderLayout;
import java.awt.CardLayout;
import java.awt.Color;
import java.awt.Dimension;
import java.awt.Font;
import java.awt.GridLayout;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.awt.event.FocusEvent;
import java.awt.event.FocusListener;
import java.io.File;
import java.io.FileNotFoundException;
import java.util.Scanner;
import javax.swing.JButton;
import javax.swing.JLabel;
import javax.swing.JPanel;
import javax.swing.JTextField;
import javax.swing.SwingConstants;
import javax.swing.Timer;

public class JoinQuiz extends JPanel implements ActionListener 
{
    private JLabel lbTitle, lbStart, lbCode, lbName, lbada;
    private JButton btn1;
    private Placeholder tf1, tf2;
    private Timer delayTimer;
    private CardLayout cardLayout;
    private JPanel parentPanel;

    public JoinQuiz() 
    {
            setLayout(new BorderLayout());
            setBackground(Color.WHITE);

            // Set up font styles
            Font font1 = new Font("Dialog", Font.BOLD | Font.ITALIC, 30);
            Font font2 = new Font("SansSerif", Font.BOLD, 15);
            Font font3 = new Font("SansSerif", Font.BOLD, 12);

            // Creating the GUI objects
            lbTitle = new JLabel("Welcome, student");
            lbTitle.setForeground(Color.GRAY);
            lbTitle.setHorizontalAlignment(SwingConstants.LEFT);
            lbTitle.setFont(font1);

            lbStart = new JLabel("Start a quiz");
            lbStart.setHorizontalAlignment(SwingConstants.CENTER);
            lbStart.setFont(new Font("SansSerif", Font.BOLD, 20));

            lbCode = new JLabel("Enter quiz code");
            lbCode.setHorizontalAlignment(SwingConstants.CENTER);
            lbCode.setFont(font2);

            tf1 = new Placeholder("Enter code");
            tf1.setHorizontalAlignment(SwingConstants.CENTER);
            tf1.setFont(font3);

            lbada = new JLabel();
            lbada.setHorizontalAlignment(SwingConstants.CENTER);
            lbada.setFont(font3);

            lbName = new JLabel("Enter your player name");
            lbName.setHorizontalAlignment(SwingConstants.CENTER);
            lbName.setFont(font2);

            tf2 = new Placeholder("Enter name");
            tf2.setHorizontalAlignment(SwingConstants.CENTER);
            tf2.setFont(font3);

            btn1 = new JButton("START");
            btn1.setBackground(Color.YELLOW);
            btn1.setFont(font2);

            // Create a panel for the title
            JPanel titlePanel = new JPanel(new BorderLayout());
            titlePanel.setBackground(Color.YELLOW);
            titlePanel.add(lbTitle, BorderLayout.WEST);

            // Create a panel for the quiz code and name input
            JPanel inputPanel = new JPanel();
            inputPanel.setLayout(new GridLayout(6, 1));
            inputPanel.setBackground(Color.WHITE);
            inputPanel.add(lbStart);
            inputPanel.add(lbCode);
            inputPanel.add(tf1);
            inputPanel.add(lbada);
            inputPanel.add(lbName);
            inputPanel.add(tf2);

            // Create a panel for the start button
            JPanel buttonPanel = new JPanel();
            buttonPanel.setBackground(Color.WHITE);
            buttonPanel.add(btn1);

             // Create a main panel to hold all other panels
            JPanel mainPanel = new JPanel();
            mainPanel.setLayout(new BorderLayout());
            mainPanel.setBackground(Color.WHITE);
            mainPanel.add(titlePanel, BorderLayout.NORTH);
            mainPanel.add(inputPanel, BorderLayout.CENTER);
            mainPanel.add(buttonPanel, BorderLayout.SOUTH);

            // Add the main panel to the container
            add(mainPanel);

        //register the start button to the listener
        btn1.addActionListener(this);

         // Create the delay timer with 3-second delay
        delayTimer = new Timer(3000, new ActionListener() 
        {
            public void actionPerformed(ActionEvent e) {
                try {
                    CardLayout cardLayout = (CardLayout) getParent().getLayout();
                    QuizPanel quizPanel = (QuizPanel) getParent().getComponent(6);
                    String code = tf1.getText();
                    quizPanel.setQuizCode(code);
                    cardLayout.show(getParent(), "quizPage");
                } catch (IndexOutOfBoundsException a) {
                    System.out.println("IndexOutOfBoundsException occurred: " + a.getMessage());
                }
            }
        });
    }

    public String getQuizCode() //method to get quizcode, will use to pass variable to next page
    {
        return tf1.getText();
    }

    public void actionPerformed(ActionEvent e) 
    {
        if (e.getSource() == btn1) { //when start button is clicked
            String code = tf1.getText();
            String name = tf2.getText();
            boolean found = false;

            if (name.isEmpty() || name.equals(tf2.getPlaceholder()) || code.isEmpty() || code.equals(tf1.getPlaceholder())) 
            {
                //if the textfield is empty or not the placeholder
                
                lbada.setText("Please enter all the fields to start the quiz.");
                lbada.setForeground(Color.RED);
            } else 
            {//if the textfields are not empty or placeholder
                
                try { //open file to read and check
                    String filePath = "src/quizcode.txt";
                    File file = new File(filePath);
                    Scanner sc = new Scanner(file);

                    while (sc.hasNextLine()) 
                    {
                        String quiz = sc.nextLine();
                        if (quiz.equals(code)) //if the quiz code enter by user is found
                        {
                            lbada.setText("Quiz found!");
                            lbada.setForeground(Color.GREEN);
                            found = true;
                            break;
                        }
                    }
                    sc.close();

                    if (!found) //if the quiz code enter by user is not found
                    {
                        lbada.setText("Sorry, the quiz is not found.");
                        lbada.setForeground(Color.RED);
                    } else {
                        delayTimer.start();
                    }
                } 
                catch (FileNotFoundException ex) //exception handling if the file is not found
                {
                    lbada.setText("File not found. Please check again.");
                    lbada.setForeground(Color.RED);
                }
            }
        }
    }

    //private class to use placeholder
    private class Placeholder extends JTextField implements FocusListener 
    {
        private String placeholder;

        //constructor that set the placeholder 
        public Placeholder(String placeholder) 
        {
            this.placeholder = placeholder;
            setForeground(Color.GRAY);
            setText(placeholder);
            addFocusListener(this);
        }

        //public method to return placeholder, use when to check the textfield is empty or equal to placeholder
        public String getPlaceholder() 
        {
            return placeholder;
        }

        //when cursor is in textfield
        @Override
        public void focusGained(FocusEvent e) {
            if (getText().equals(placeholder)) {
                setForeground(Color.BLACK);
                setText("");
            }
        }

        //when cursor is not is textfield
        @Override
        public void focusLost(FocusEvent e) {
            if (getText().isEmpty()) {
                setForeground(Color.GRAY);
                setText(placeholder);
            }
        }
    }
}
