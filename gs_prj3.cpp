// gs-prj3.cpp: Santiago Arias
// Description: 
// As electronic stopwatches become cheaper and more accurate, 
// we will no doubt be deluged with impossibly accurate measurements of time. 
// Write a program that takes as input a time period given in seconds, 
// and outputs the number of hours, minutes and seconds it represents. 
// For example,
// Number of seconds: 3662
// Hours: 1
// Minutes: 1
// Seconds: 2     
// In the following, do decomposition prior to writing your program. 
// Use functions wherever possible to create well-structured programs.

#include <iostream>

using namespace std;

int main(){
  int number_seconds;
  int number_minutes;
  int number_hours;

  cout << "Number of seconds: ";
  if(!(cin >> number_seconds)){
    cout << "Should be an integer" << endl;
  } else {
    number_hours = number_seconds / (60*60);
    number_seconds = number_seconds - number_hours*(60*60);
    number_minutes = number_seconds / 60;
    number_seconds = number_seconds - number_minutes*60;

    cout << "Hours: " << number_hours << endl;
    cout << "Minutes: " << number_minutes << endl;
    cout << "Seconds: " << number_seconds << endl;
  }
}
