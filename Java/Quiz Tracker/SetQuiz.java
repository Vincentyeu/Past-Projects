/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package com.mycompany.quiztracker;

import javax.swing.JButton;
import javax.swing.JLabel;
import javax.swing.JPanel;
import javax.swing.JTextField;
import java.awt.BorderLayout;
import java.awt.Color;
import java.awt.Font;
import java.awt.GridLayout;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.io.File;
import java.io.IOException;
import java.io.PrintWriter;
import javax.swing.JDialog;
import javax.swing.JFrame;

public class SetQuiz extends JDialog implements ActionListener {
    private JPanel parentPanel;
    private JLabel lb1, lb2;
    private JTextField tf1;
    private JPanel questionPanel;
    private JButton saveButton;
    private String code;
    private boolean done = false; // Flag to track if number of questions has been entered
    private boolean close =false;

    public SetQuiz() {
     

        Font font = new Font("Arial", Font.BOLD, 15);

        lb1 = new JLabel("How many questions for the quiz?");
        lb1.setFont(font);

        lb2 = new JLabel();

        tf1 = new JTextField(12);

        saveButton = new JButton("Save");
        saveButton.setBackground(Color.YELLOW);

        JPanel p1 = new JPanel();
        p1.add(lb1);
        p1.add(tf1);

        questionPanel = new JPanel();
        questionPanel.setLayout(new GridLayout(0, 1));

        JPanel p3 = new JPanel();
        p3.add(saveButton);
        p3.add(lb2);

        setLayout(new BorderLayout());
        add(p1, BorderLayout.NORTH);
        add(questionPanel, BorderLayout.CENTER);
        add(p3, BorderLayout.SOUTH);

        tf1.addActionListener(this);
        saveButton.addActionListener(this);
        
        // Set dialog properties
        setTitle("Set Questions");
        setSize(400, 300);
        setLocationRelativeTo(null); // Center the dialog on the screen
        setModal(true); // Set the dialog as modal
    }

    public void actionPerformed(ActionEvent e) {
        if (e.getSource() == tf1) 
        {
            String inputText = tf1.getText();
            if (!inputText.isEmpty()) {
                done = true; // Set the flag to indicate number of questions has been entered
            }
            try {
                int input = Integer.parseInt(inputText);
                if (input <= 0) {
                    throw new IllegalArgumentException();
                }
                questionPanel.removeAll();
                if (input >= 1) {
                    questionPanel.removeAll();

                    for (int i = 1; i <= input; i++) 
                    {
                        JPanel questionSection = new JPanel();
                        questionSection.setLayout(new BorderLayout());

                        JLabel questionLabel = new JLabel("Question " + i + ":");
                        questionLabel.setFont(new Font("Arial", Font.BOLD, 15));
                        questionSection.add(questionLabel, BorderLayout.NORTH);

                        JTextField questionTextField = new JTextField("Please set a question here.", 8);
                        questionSection.add(questionTextField, BorderLayout.CENTER);

                        JPanel answerSection = new JPanel();
                        answerSection.setLayout(new GridLayout(0, 2));

                        JLabel optionALabel = new JLabel("Option A:");
                        JTextField optionATextField = new JTextField(8);
                        answerSection.add(optionALabel);
                        answerSection.add(optionATextField);

                        JLabel optionBLabel = new JLabel("Option B:");
                        JTextField optionBTextField = new JTextField(8);
                        answerSection.add(optionBLabel);
                        answerSection.add(optionBTextField);

                        JLabel optionCLabel = new JLabel("Option C:");
                        JTextField optionCTextField = new JTextField(8);
                        answerSection.add(optionCLabel);
                        answerSection.add(optionCTextField);

                        JLabel optionDLabel = new JLabel("Option D:");
                        JTextField optionDTextField = new JTextField(8);
                        answerSection.add(optionDLabel);
                        answerSection.add(optionDTextField);

                        JLabel correctAnsLabel = new JLabel("Correct Answer:");
                        JTextField tfcorrectAns = new JTextField(8);
                        answerSection.add(correctAnsLabel);
                        answerSection.add(tfcorrectAns);

                        JPanel questionAndAnswerPanel = new JPanel();
                        questionAndAnswerPanel.setLayout(new BorderLayout());
                        questionAndAnswerPanel.add(questionSection, BorderLayout.NORTH);
                        questionAndAnswerPanel.add(answerSection, BorderLayout.CENTER);

                        questionPanel.add(questionAndAnswerPanel);
                    }

                    questionPanel.revalidate();
                    questionPanel.repaint();
                } else {
                    questionPanel.removeAll();
                    questionPanel.revalidate();
                    questionPanel.repaint();
                }

            } catch (NumberFormatException ex) {
                questionPanel.removeAll();
                questionPanel.revalidate();
                questionPanel.repaint();
                lb2.setText("Invalid input. Please enter a valid number.");
                lb2.setForeground(Color.RED);
            } catch (IllegalArgumentException ex) {
                questionPanel.removeAll();
                questionPanel.revalidate();
                questionPanel.repaint();
                lb2.setText("Number of questions must be greater than 0.");
                lb2.setForeground(Color.RED);
            }
        }

        if (e.getSource() == saveButton && done) 
        { // Check if done flag is true
            File quizFile = new File("src/" + code + ".txt");
            try {
                PrintWriter pw = new PrintWriter(quizFile);

                for (int i = 0; i < questionPanel.getComponentCount(); i++) {
                    JPanel questionAndAnswerPanel = (JPanel) questionPanel.getComponent(i);
                    JPanel questionSection = (JPanel) questionAndAnswerPanel.getComponent(0);
                    JPanel answerSection = (JPanel) questionAndAnswerPanel.getComponent(1);

                    JTextField questionTextField = (JTextField) questionSection.getComponent(1);
                    JTextField optionATextField = (JTextField) answerSection.getComponent(1);
                    JTextField optionBTextField = (JTextField) answerSection.getComponent(3);
                    JTextField optionCTextField = (JTextField) answerSection.getComponent(5);
                    JTextField optionDTextField = (JTextField) answerSection.getComponent(7);
                    JTextField tfcorrectAns = (JTextField) answerSection.getComponent(9);

                    pw.write(questionTextField.getText());
                    pw.println();
                    pw.write(optionATextField.getText());
                    pw.println();
                    pw.write(optionBTextField.getText());
                    pw.println();
                    pw.write(optionCTextField.getText());
                    pw.println();
                    pw.write(optionDTextField.getText());
                    pw.println();
                    pw.write(tfcorrectAns.getText());
                    pw.println();
                    pw.println();
                }
                pw.close();
                lb2.setText("Quiz saved!");
                lb2.setForeground(Color.GREEN);
                close = true;
                
                 if(close)
                {
                    dispose();
                 }
               
            } 
            catch (IOException ex) 
            {
                lb2.setText("Error occurred when writing to file.");
                lb2.setForeground(Color.RED);
            }
        }

        
    }

    public void setCode(String code) 
    {
        this.code = code;
    }

}
