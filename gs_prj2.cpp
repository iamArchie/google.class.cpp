// gs_prj2.cpp: Santiago Arias
// Description:
// Write a program that will compute your final grade 
// for a programming course you are taking. 

// Here is the grading scheme:

// Final grades will be based on the following:
// 40% Assignments   
// 15% Midterm Examination
// 35% Final Examination
// 10% Class Participation Grade 

// Your program should ask the user for the four assignment 
// scores, the midterm, final and section grades. 
// Then, the final score is calculated and printed. 
// To do the calculations, you average the four assignment 
// scores together and then multiply it by 0.4 (40%). 
// You then multiply the midterm score by 0.15, the final 
// by 0.35 and the participation grade by 0.1. 

// Then you add all the results of these multiplications together.

// Use functions wherever you can in this program. 

// You can create a function to get the input by passing 
// in as a parameter the string to be displayed in 
// an explanatory cout. Here is an example run:

// Enter the score for the first assignment. 75
// Enter the score for the second assignment. 85
// Enter the score for the third assignment. 82
// Enter the score for the fourth assignment. 94
// Enter the score for the midterm. 81
// Enter the score for the final. 89
// Enter the score for the section grade. 100
// The final grade is: 86.9
#include <iostream>

using namespace std;

#define kAssignementPercent 0.4
#define kMidtermPercent 0.15
#define kFinalPercent 0.35
#define kParticipartionPercent 0.1

int main(void){
  
  int first_assignment;
  int second_assignment;
  int third_assignment;
  int fourth_assignment;
  int midterm;
  int final;
  int section_grade;


  cout << "Enter the score for the first assignment. "; cin >> first_assignment;
  cout << "Enter the score for the second assignment. "; cin >> second_assignment;  
  cout << "Enter the score for the third assignment. "; cin >> third_assignment;
  cout << "Enter the score for the fourth assignment. "; cin >> fourth_assignment;
  cout << "Enter the score for the midterm. "; cin >> midterm;
  cout << "Enter the score for the final. "; cin >> final;
  cout << "Enter the score for the section grade. "; cin >> section_grade;

  double average_assignment = (first_assignment + second_assignment + third_assignment + fourth_assignment) / 4.0;

  double final_grade = average_assignment * kAssignementPercent + midterm * kMidtermPercent + final * kFinalPercent + section_grade * kParticipartionPercent;

  cout << "The final grade is: "<< final_grade << endl;
  return 0;
}
