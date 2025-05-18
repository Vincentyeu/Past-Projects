/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package com.mycompany.quiztracker;


import javax.swing.JButton;
import javax.swing.JLabel;
import javax.swing.JPanel;
import javax.swing.ImageIcon;

import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.awt.BorderLayout;
import java.awt.CardLayout;
import java.awt.Color;
import java.awt.Dimension;
import java.awt.FlowLayout;
import java.awt.Font;
import javax.swing.SwingConstants;

public class LecturerPanel extends JPanel implements ActionListener {
    JLabel logo, lblecturer;
    JButton btncreate, btnviewquizes, btnlogout;

    public LecturerPanel() {
        Font font1 = new Font("Dialog", Font.BOLD | Font.ITALIC, 30);

        ImageIcon image1 = new ImageIcon(getClass().getResource("image/logo.png"));
        logo = new JLabel(image1);

        lblecturer = new JLabel("Welcome, lecturer");
        lblecturer.setHorizontalAlignment(SwingConstants.LEFT);
        lblecturer.setFont(font1);

        btncreate = new JButton("Create New Quiz");
        btncreate.setBackground(Color.BLUE);
        btncreate.setForeground(Color.WHITE);
        btncreate.setPreferredSize(new Dimension(150, 60));

        btnviewquizes = new JButton("Quiz List");
        btnviewquizes.setBackground(Color.BLUE);
        btnviewquizes.setForeground(Color.WHITE);
        btnviewquizes.setPreferredSize(new Dimension(150, 60));

        btnlogout = new JButton("Logout");
        btnlogout.setBackground(Color.GRAY);
        btnlogout.setForeground(Color.WHITE);
        btnlogout.setPreferredSize(new Dimension(150, 30));

        setLayout(new BorderLayout());
        setBackground(Color.WHITE); // Set background color to white

        JPanel p1 = new JPanel(new FlowLayout(FlowLayout.RIGHT));
        p1.setBackground(Color.WHITE);
        p1.add(btnlogout);

        JPanel p2 = new JPanel();
        p2.setBackground(Color.WHITE);
        p2.add(lblecturer);

        JPanel buttonPanel = new JPanel(new FlowLayout());
        buttonPanel.setBackground(Color.WHITE);
        buttonPanel.add(btncreate);
        buttonPanel.add(btnviewquizes);

        add(logo, BorderLayout.NORTH);
        add(p2, BorderLayout.CENTER);
        add(buttonPanel, BorderLayout.SOUTH);
        add(p1, BorderLayout.EAST);

        btncreate.addActionListener(this);
        btnviewquizes.addActionListener(this);
        btnlogout.addActionListener(this);
    }

    public void actionPerformed(ActionEvent e) {
        if (e.getSource() == btncreate) 
        {
            CardLayout cardLayout = (CardLayout) getParent().getLayout();
            SetQuizFirst createPanel = (SetQuizFirst) getParent().getComponent(3);
            cardLayout.show(getParent(), "createPage");
        } 
        else if (e.getSource() == btnviewquizes) 
        {
            CardLayout cardLayout = (CardLayout) getParent().getLayout();
            ViewQuiz viewPanel = (ViewQuiz) getParent().getComponent(4);
            cardLayout.show(getParent(), "viewPage");
        }
        else if (e.getSource() == btnlogout) 
        {
            CardLayout cardLayout = (CardLayout) getParent().getLayout();
            MainPagePanel mainPagePanel = (MainPagePanel) getParent().getComponent(0);
            cardLayout.show(getParent(), "mainPage");
        }
    }
}

   

