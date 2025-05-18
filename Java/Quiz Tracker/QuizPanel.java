/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package com.mycompany.quiztracker;

import java.awt.CardLayout;
import java.awt.Color;
import java.awt.GridLayout;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.io.File;
import java.io.FileNotFoundException;
import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;


import javax.swing.BoxLayout;
import javax.swing.ButtonGroup;
import javax.swing.JButton;
import javax.swing.JLabel;
import javax.swing.JPanel;
import javax.swing.JRadioButton;
import javax.swing.SwingConstants;

public class QuizPanel extends JPanel implements ActionListener 
{
    //Array list
    private List<String> questions;
    private List<List<String>> answerOptions;
    private List<String> correctAnswers;
    private List<String> userAnswers;
    
    private String quizCode;
    
    private JRadioButton rba, rbb, rbc, rbd;
    private JLabel lbNum, lbQuestion, lbSave;
    private JButton btnNext, btnSave, btnSubmit, btnQuiz, btnOut;
    
    private boolean scoreIncremented = false,con=false;

    private int current=0,score=0;
    

   public QuizPanel() 
{
    setBackground(Color.WHITE);
    setLayout(new BoxLayout(this, BoxLayout.Y_AXIS));

    // Creating the GUI objects
    lbNum = new JLabel();
    lbNum.setHorizontalAlignment(SwingConstants.LEFT);
    lbQuestion = new JLabel();

    rba = new JRadioButton();
    rbb = new JRadioButton();
    rbc = new JRadioButton();
    rbd = new JRadioButton();

    // Make the radio buttons to be selected only one at a time
    ButtonGroup group = new ButtonGroup();
    group.add(rba);
    group.add(rbb);
    group.add(rbc);
    group.add(rbd);

    lbSave = new JLabel();

    // Decorate buttons
    btnNext = new JButton("Next");
    btnNext.setBackground(Color.YELLOW);
    btnSave = new JButton("Save");
    btnSave.setBackground(Color.YELLOW);
    btnSubmit = new JButton("Submit");
    btnSubmit.setBackground(Color.GREEN);
    btnQuiz = new JButton("Join new quiz / Play again");
    btnQuiz.setBackground(Color.YELLOW);
    btnOut = new JButton("Logout");
    btnOut.setBackground(Color.GRAY);
    btnOut.setForeground(Color.WHITE); 

    // Panel 1 to hold label of question number and label of question
    JPanel p1 = new JPanel();
    p1.setLayout(new GridLayout(1, 2));
    p1.add(lbNum);
    p1.add(lbQuestion);

    // Panel 2 to hold radio buttons
    JPanel p2 = new JPanel();
    p2.setLayout(new GridLayout(4, 1));
    p2.add(rba);
    p2.add(rbb);
    p2.add(rbc);
    p2.add(rbd);

    // Panel 3 to hold label for displaying "saved" text
    JPanel p3 = new JPanel();
    p3.add(lbSave);

    // Panel 4 to hold all buttons
    JPanel p4 = new JPanel();
    p4.add(btnSave);
    p4.add(btnNext);
    p4.add(btnSubmit);
    p4.add(btnQuiz);
    p4.add(btnOut);

    // Set background color of all panels to white
    p1.setBackground(Color.WHITE);
    p3.setBackground(Color.WHITE);
    p4.setBackground(Color.WHITE);

    // Add the panels to the container
    add(p1);
    add(p2);
    add(p3);
    add(p4);

    // Register the buttons to the listener
    btnNext.addActionListener(this);
    btnSave.addActionListener(this);
    btnSubmit.addActionListener(this);
    btnQuiz.addActionListener(this);
    btnOut.addActionListener(this);

    // Initializes ArrayLists
    questions = new ArrayList<>();
    answerOptions = new ArrayList<>();
    correctAnswers = new ArrayList<>();
    userAnswers = new ArrayList<>();

    // If quiz code already entered by user, then only load data from file. 
    // This prevents the QuizTracker from directly calling the file and causing a FileNotFoundException exception
    if (quizCode != null && !quizCode.isEmpty()) 
    {
        current = 0;
        loadQuizData();
    }
}


    public void setQuizCode(String quizCode) 
    {
        //get quizCode from joinQuiz page
        this.quizCode = quizCode;
        questions.clear();
        answerOptions.clear();
        correctAnswers.clear();
        userAnswers.clear();

        // Load the new quiz data
        loadQuizData();
       
    }

    private void loadQuizData() 
    {
        //define the filepath according to quizCode
     String filePath = "src/" + quizCode + ".txt";

    try {
        File file = new File(filePath);
        Scanner scanner = new Scanner(file);

        questions.clear();// clear the question list
        answerOptions.clear();// clear the answer options list
        correctAnswers.clear();// clear the correct answer list
        userAnswers.clear(); // clear the userAnswers list

        while (scanner.hasNextLine()) 
        {
            String line = scanner.nextLine().trim();
            if (!line.isEmpty()) 
            {
                questions.add(line); //get question
                List<String> options = new ArrayList<>(); //declare a string array list 
                options.add(scanner.nextLine()); //read the answer option and add to array list
                options.add(scanner.nextLine());
                options.add(scanner.nextLine());
                options.add(scanner.nextLine());
                answerOptions.add(options); //add the array list to answer options array list
                correctAnswers.add(scanner.nextLine()); //add correct answer to correct answer array list
                userAnswers.add(""); // add an empty answer for each question
            }
        }

        scanner.close(); //close file
        displayQuestion(current);//call display question and pass the index of question 
    } 
    catch (FileNotFoundException ex) //catch exception when file not found
    {
         lbNum.setText("Quiz file not found.");
         lbNum.setForeground(Color.RED);
    }

}

   private void displayQuestion(int index)  // display question 
   {
    clearSelection(); //clear user selection
    if(!con)
    {
        lbNum.setText("Question " + (index + 1) + ":"); //display question number if user havent click submit yet
    }
    else
    {
        lbNum.setText("Congratulations! ");//set the question number label
    }
    
    lbQuestion.setText(questions.get(index));//set the question to lbQuestion to be displayed

    List<String> options = answerOptions.get(index);//get the answer options value from array list and set to each radio button accordingly
    rba.setText(options.get(0));
    rbb.setText(options.get(1));
    rbc.setText(options.get(2));
    rbd.setText(options.get(3));

    enableOptions();
    lbSave.setText("");
    
    if (index == questions.size() - 1) //for last question
    {
        btnSave.setVisible(true); // Show the save button for the last question
        btnNext.setVisible(false);//Hide the next button for the last question
        btnQuiz.setVisible(false);// Hide the replay button for last question
        btnOut.setVisible(false);// Hide the logout button for last question
        btnSubmit.setVisible(true);// Show the submit button only for last question
    } else 
    {
        btnSave.setVisible(true); //Show save button for every other question
        btnSubmit.setVisible(false);// Hide the submit button for every other questions
        btnQuiz.setVisible(false);// Hide the replay button for every other questions
        btnOut.setVisible(false);// Hide the logout button for every other questions
    }
    
    btnSave.setEnabled(true); // Enable the save button for the current question
}


    private void clearSelection() //clear user selected radio buttons
    {
        rba.setSelected(false);
        rbb.setSelected(false);
        rbc.setSelected(false);
        rbd.setSelected(false);
    }

    private String getSelectedAnswer() //get answer data selected by user
    {
        if (rba.isSelected()) //if radio button A is selected, get radio button A data
        {
            return rba.getText();
        } 
        else if (rbb.isSelected()) //if radio button B is selected, get radio button B data
        {
            return rbb.getText();
        }
        else if (rbc.isSelected())//if radio button C is selected, get radio button C data
        {
            return rbc.getText();
        } 
        else if (rbd.isSelected()) //if radio button D is selected, get radio button D data
        {
            return rbd.getText();
        } 
        else //if no radio button is selected, get nothing
        {
            return "";
        }
    }

    private void disableOptions() //disable the radio buttons 
    {
        rba.setEnabled(false);
        rbb.setEnabled(false);
        rbc.setEnabled(false);
        rbd.setEnabled(false);
    }

    private void enableOptions() // enable the radio buttons
    {
        rba.setEnabled(true);
        rbb.setEnabled(true);
        rbc.setEnabled(true);
        rbd.setEnabled(true);
    }

    public void actionPerformed(ActionEvent e) 
    {
        
        if (e.getSource() == btnSubmit) //if submit button is clicked
        {
            current++; //increase the index of question to stop displaying question
            revalidate();//ensure the layout manager recalculates the size and position of the components based on any changes that have occurred
            repaint();//components to be redrawn on the screen
            clearSelection();//clear user selection
            
            // Quiz finished
            lbNum.setText("Congratulations! ");//set the question number label
            lbQuestion.setText("Quiz submitted successfully");//set the question label 
            disableOptions();
            con=true;//mark flag to let lbNum become "Congratulations" and not showing number of question

            btnSave.setVisible(false); // Hide the save button after submit
            btnNext.setVisible(false); // Hide the next button after submit
            btnSubmit.setVisible(false); // Hide the submit button after submit
            btnOut.setVisible(true); // Show the logout button after submit
            btnQuiz.setVisible(true); //Show the button to join quiz page after submit
            int num = getNumQuestion(); // get number of question in this quiz to be sent to the resut page to calculate result

            // Create and configure the result dialog
            ResultPanel resultDialog = new ResultPanel();
            resultDialog.setData(score, num); //pass score and number of question value to ResultPanel
            resultDialog.setVisible(true);
        }

        
    if (e.getSource() == btnSave) // When user click save button
    {
    
    String selectedAnswer = getSelectedAnswer();//get user selected answer data

    btnSave.setEnabled(false);//disable the save button for a while
    userAnswers.set(current, selectedAnswer); // Update the user's answer

    String correctAnswer = correctAnswers.get(current);//get correct answer data for current question

    if (selectedAnswer.equals(correctAnswer) && !scoreIncremented) //if user selected answer data match with correct answer
    {
        score++; //increase score
        scoreIncremented = true; // Set the flag to indicate that the score has been incremented 
        //so that if user click second time save button, score will not increment anymore
    }

    lbSave.setText("Answer Saved");//show user answer saved

    disableOptions();//disable the radio buttons for a while
    clearSelection(); // Clear the radio button selection
}
else if (e.getSource() == btnNext) //if user click Next button
{
    btnSave.setEnabled(true);//enable save button

    if (current < questions.size()) //if current question is not last question
    {
        current++; //increase question index
        displayQuestion(current);//call display question and pass question index
    }

    clearSelection(); // Clear the radio button selection

    userAnswers.set(current, ""); // Clear the user's answer for the current question


    scoreIncremented = false; // Reset the flag for the next question
}

    
    if(e.getSource() == btnQuiz)//if user click replay quiz button, direct user to join quiz page
    {
        CardLayout cardLayout = (CardLayout) getParent().getLayout();
        JoinQuiz joinPanel = (JoinQuiz) getParent().getComponent(5);
        cardLayout.show(getParent(), "joinPage");
    }
    else if(e.getSource() == btnOut)//if user click logout button, direct user to logout page
    {
        CardLayout cardLayout = (CardLayout) getParent().getLayout();
        MainPagePanel mainPagePanel = (MainPagePanel) getParent().getComponent(0);
        cardLayout.show(getParent(), "mainPage");
    }
   

}
    
    private int getNumQuestion()//get number of question in this quiz
    {
        return questions.size();
    }
}