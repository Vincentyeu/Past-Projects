/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 */
package com.mycompany.quiztracker;
import java.awt.CardLayout;
import javax.swing.JFrame;
import javax.swing.JPanel;

public class QuizTracker extends JFrame 
{
    //private members
    private CardLayout cardLayout;
    private JPanel cardPanel;

    public QuizTracker() {
        
        cardLayout = new CardLayout();
        cardPanel = new JPanel(cardLayout);

        // Create instances of the panels
        MainPagePanel mainPagePanel = new MainPagePanel();
        LoginPanel loginPanel = new LoginPanel(cardLayout);
        LecturerPanel lecturerPanel = new LecturerPanel();
        SetQuizFirst createPanel = new SetQuizFirst();
        ViewQuiz viewPanel = new ViewQuiz();
        JoinQuiz joinPanel = new JoinQuiz();
        QuizPanel quizPanel = new QuizPanel();

        // Add panels to the cardPanel
        cardPanel.add(mainPagePanel, "mainPage");
        cardPanel.add(loginPanel, "loginPage");
        cardPanel.add(lecturerPanel, "lecturerPage");
        cardPanel.add(createPanel, "createPage");
        cardPanel.add(viewPanel, "viewPage");
        cardPanel.add(joinPanel, "joinPage");
        cardPanel.add(quizPanel, "quizPage");

        // Set the default starting page
        cardLayout.show(cardPanel, "mainPage");

        // Set up the frame
        getContentPane().add(cardPanel);
        setTitle("Easy Quiz Tracker"); //set frame title
        setSize(900, 700); //set frame size
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        setVisible(true);
    }

    public static void main(String[] args) 
    {
        QuizTracker frame = new QuizTracker();
    }
    
   

}