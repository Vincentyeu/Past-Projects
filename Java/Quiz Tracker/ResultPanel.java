/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package com.mycompany.quiztracker;

import java.awt.BorderLayout;
import java.awt.Color;
import java.awt.Font;
import java.awt.GridLayout;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.text.DecimalFormat;
import javax.swing.ImageIcon;
import javax.swing.JButton;
import javax.swing.JComboBox;
import javax.swing.JDialog;
import javax.swing.JLabel;
import javax.swing.JPanel;


public class ResultPanel extends JDialog implements ActionListener 
{
    //declaring GUI objects
    private String [] option ={"Score","Total Mark","Grade"};
    private JComboBox jcb=new JComboBox(option);
    private JLabel lbTitle, lbIcon, lb1,lb2;
    private JButton btnClose;
    private ImageIcon icon1,icon2;
    private int score,Qnum;
    
     public ResultPanel() 
     {
         // Set up font style
         Font font1=new Font("Font Calibri,", Font.ITALIC , 20);
         
          // Creating the GUI objects
         lbTitle=new JLabel("View your result");
         
         icon1=new ImageIcon(getClass().getResource("image/result.png"));
         lbIcon=new JLabel(icon1);
         
        btnClose = new JButton("Close");
        btnClose.setBackground(Color.GRAY);
        btnClose.setForeground(Color.WHITE); 
         
         lb1=new JLabel("Select :");
         
         lb2 = new JLabel();

         // Panel p1 to hold title label and icon label for result page
         JPanel p1 = new JPanel();
         p1.add(lbTitle);
         p1.add(lbIcon);
         
         // Panel p2sub to hold label Select and JComboBox
         JPanel p2sub = new JPanel();
         p2sub.setLayout(new GridLayout(1,2));
         p2sub.add(lb1);
         p2sub.add(jcb);
         
         // Panel p2 to hold Panel p2sub and an result label
         JPanel p2 = new JPanel();
         p2.add(p2sub);
         p2.add(lb2);
         
         // Panel p3 to hold close button
         JPanel p3 = new JPanel();
         p3.add(btnClose);
       
         
        setLayout(new BorderLayout());
        setBackground(Color.WHITE);
        add(p1, BorderLayout.NORTH);
        add(p2, BorderLayout.CENTER);
        add(p3, BorderLayout.SOUTH);
        
        //register the JComboBox and Close button to the listener
        jcb.addActionListener(this);
        btnClose.addActionListener(this);
         
        // Set dialog properties
        setTitle("Quiz Results");
        setSize(400, 300);
        setLocationRelativeTo(null); // Center the dialog on the screen
        setModal(true); // Set the dialog as modal
     }
     
     public void setData(int score, int Qnum) //get user score and number of question from QuizPanel
    {
        this.score=score;
        this.Qnum=Qnum;
    }
     
     public void actionPerformed(ActionEvent e) 
     {
        if (e.getSource() == jcb) //if user select the drop down button
        {
            DecimalFormat decimal = new DecimalFormat("0.00");//use DecimalFormat to display marks in 2 decimal points
            double fmark = 0;
            char fgrade;

            String text = (String) jcb.getSelectedItem();//get the value of the drop down button selected

            // Calculate mark based on score and question number
            fmark = (double) (score * 100) / Qnum;

            
            if (text.equals("Score")) //if user choose "Score" from drop down button
            {
                lb2.setText("Your Score: " + score + " / " + Qnum);
            } 
            else if (text.equals("Total Mark")) //if user choose "Total Mark" from drop down button
            {
                lb2.setText("Your total mark: " + decimal.format(fmark) + "%");
            } 
            else if (text.equals("Grade")) //if user choose "Grade" from drop down button
            {
                if (fmark >= 85.0) //set grade according to mark
                {
                    fgrade = 'A';
                    lb2.setForeground(Color.GREEN);

                } else if (fmark >= 70.0 && fmark < 85.0) 
                {
                    fgrade = 'B';
                    lb2.setForeground(Color.GREEN);
                } else if (fmark >= 50.0 && fmark < 70.0) 
                {
                    fgrade = 'C';
                    lb2.setForeground(Color.GREEN);
                } else if (fmark >= 20.0 && fmark < 50.0) 
                {
                    fgrade = 'D';
                    lb2.setForeground(Color.RED);
                } else 
                {
                    fgrade = 'F';
                    lb2.setForeground(Color.RED);
                }
                lb2.setText("Your grade is " + fgrade);

            }
        }
        
        if(e.getSource() == btnClose)//if user click Close button
        {
             dispose(); // Close the dialog
        }
}

    
}
