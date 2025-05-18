/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package com.mycompany.quiztracker;

import java.awt.BorderLayout;
import java.awt.CardLayout;
import java.awt.Color;
import java.awt.FlowLayout;
import java.awt.Font;
import java.awt.GridLayout;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

import javax.swing.ImageIcon;
import javax.swing.JButton;
import javax.swing.JLabel;
import javax.swing.JPanel;
import javax.swing.SwingConstants;

public class MainPagePanel extends JPanel implements ActionListener {
    private JLabel lbHome, lbQ, lbicon1, lblecturer, lbstudent;
    private JButton btn1, btn2;
    private ImageIcon icon1, iconlecturer, iconstudent;

    public MainPagePanel() {
        setLayout(new BorderLayout());
        setOpaque(true);
        setBackground(Color.WHITE); // Set background color to white

        icon1 = new ImageIcon(getClass().getResource("image/logo.png"));
        lbicon1 = new JLabel(icon1);

        lbHome = new JLabel("Welcome to Easy Quiz Tracker");
        lbHome.setFont(new Font("Arial", Font.BOLD, 24));
        lbHome.setForeground(Color.BLUE);
        lbHome.setHorizontalAlignment(SwingConstants.CENTER);

        lbQ = new JLabel("You are a ...");
        lbQ.setFont(new Font("Arial", Font.BOLD, 24));

        btn1 = new JButton("Lecturer");
        btn1.setBackground(Color.BLUE);
        btn1.setFont(btn1.getFont().deriveFont(Font.BOLD, 20));

        iconlecturer = new ImageIcon(getClass().getResource("image/lecturer.png"));
        lblecturer = new JLabel(iconlecturer);

        btn2 = new JButton("Student");
        btn2.setBackground(Color.GREEN);
        btn2.setFont(btn2.getFont().deriveFont(Font.BOLD, 20));

        iconstudent = new ImageIcon(getClass().getResource("image/student.png"));
        lbstudent = new JLabel(iconstudent);

        JPanel btn1Panel = new JPanel(new BorderLayout());
        btn1Panel.add(btn1, BorderLayout.CENTER);

        JPanel btn2Panel = new JPanel(new BorderLayout());
        btn2Panel.add(btn2, BorderLayout.CENTER);

        JPanel p1 = new JPanel();
        p1.setBackground(Color.WHITE);
        p1.setLayout(new GridLayout(2, 1));
        p1.add(lbicon1);
        p1.add(lbHome);

        JPanel p2 = new JPanel();
        p2.setBackground(Color.WHITE);
        p2.add(lbQ);

        JPanel p3 = new JPanel(new FlowLayout());
        p3.setBackground(Color.WHITE); // Set background color to white
        p3.add(lblecturer);
        p3.add(btn1);
        p3.add(lbstudent);
        p3.add(btn2);

        setLayout(new BorderLayout());
        add(p1, BorderLayout.NORTH);
        add(p2, BorderLayout.CENTER);
        add(p3, BorderLayout.SOUTH);

        btn1.addActionListener(this);
        btn2.addActionListener(this);
    }

    public void actionPerformed(ActionEvent e) 
    {
        String userType = null;
        if (e.getSource() == btn1) 
        {
            userType = "Lecturer";
        } 
        else if (e.getSource() == btn2) 
        {
            userType = "Student";
        }

        CardLayout cardLayout = (CardLayout) getParent().getLayout();
        LoginPanel loginPanel = (LoginPanel) getParent().getComponent(1);

        loginPanel.setUserType(userType);
        cardLayout.show(getParent(), "loginPage");
    }
}
