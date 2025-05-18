/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package com.mycompany.quiztracker;

import javax.swing.JButton;
import javax.swing.JLabel;
import javax.swing.JPanel;
import javax.swing.ImageIcon;

import java.awt.event.ActionListener;
import java.awt.BorderLayout;
import java.awt.CardLayout;
import java.awt.Color;
import java.awt.Font;
import java.awt.GridLayout;
import java.awt.event.ActionEvent;

import java.util.Scanner;
import java.io.File;
import java.io.FileNotFoundException;
import java.util.NoSuchElementException;

public class ViewQuiz extends JPanel implements ActionListener {
    JLabel logo, title, lbquizname, lbquizcode, lbcreator, lbstudnum, no, lbnum;
    JButton btnback;
    JLabel[] Q_name;
    JLabel[] Q_code;
    JLabel[] Q_creator;

    public ViewQuiz() {
        int i = 0, j = 0;
        String empty;

        Q_name = new JLabel[100];
        Q_code = new JLabel[100];
        Q_creator = new JLabel[100];

        File file1 = new File("src/quizlist.txt"); // open file to read

        try {
            Scanner sc = new Scanner(file1);

            while (sc.hasNextLine()) 
            {
                Q_name[j] = new JLabel(sc.nextLine());
                Q_code[j] = new JLabel(sc.nextLine());
                Q_creator[j] = new JLabel(sc.nextLine());
                empty = sc.nextLine();
                j++;
            }
        } catch (FileNotFoundException ex) {
            System.out.println("No quiz file is found. Error occurred.");
        } catch (NoSuchElementException e) {
            e.printStackTrace();
        }

        Font font1 = new Font(Font.SANS_SERIF ,Font.BOLD, 18);  //declare the font for font 1 and font 2
        Font font2 = new Font(Font.SANS_SERIF, Font.PLAIN, 15);

        ImageIcon image1 = new ImageIcon(getClass().getResource("image/logo.png"));
        logo = new JLabel(image1);

        lbquizname = new JLabel(" Quiz Name");
        lbquizname.setFont(font1);

        lbquizcode = new JLabel("Quiz Code");
        lbquizcode.setFont(font1);

        lbcreator = new JLabel("Creator Name: ");
        lbcreator.setFont(font1);

        lbnum = new JLabel("No");

        btnback = new JButton("Back to main page");

        JPanel p2 = new JPanel();
        p2.setLayout(new GridLayout(j+1, 3));
        p2.setFont(font2);
        p2.add(lbquizname);
        p2.add(lbquizcode);
        p2.add(lbcreator);
        for (i = 0; i < j; i++) 
        {
            p2.add(Q_name[i]);
            Q_name[i].setFont(font2);
            p2.add(Q_code[i]);
            Q_code[i].setFont(font2);
            p2.add(Q_creator[i]);
            Q_creator[i].setFont(font2);
        }

        JPanel logoPanel = new JPanel(new BorderLayout()); // Panel for logo
        logoPanel.add(logo, BorderLayout.CENTER);

        JPanel fp = new JPanel(new BorderLayout()); // Main panel
        fp.setBackground(Color.WHITE); // Set background color of main panel to white
        logoPanel.setBackground(Color.WHITE); // Set background color of logoPanel to white
        p2.setBackground(Color.WHITE); // Set background color of p2 panel to white

        fp.add(logoPanel, BorderLayout.NORTH);
        fp.add(p2, BorderLayout.CENTER);

        setLayout(new BorderLayout());
        setBackground(Color.WHITE); // Set background color of ViewQuiz panel to white
        add(fp, BorderLayout.CENTER);
        add(btnback, BorderLayout.SOUTH);

        btnback.addActionListener(this);
    }

    public void actionPerformed(ActionEvent e) 
    {
        if (e.getSource() == btnback) 
        {
            CardLayout cardLayout = (CardLayout) getParent().getLayout();
            LecturerPanel lecturerPanel = (LecturerPanel) getParent().getComponent(2);
            cardLayout.show(getParent(), "lecturerPage");
        }
    }
}
