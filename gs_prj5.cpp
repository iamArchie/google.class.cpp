// gs_prj5.cpp: Santiago Arias
// Description:
// Here is a "magic number" problem: 
// Ask a user to enter a three-digit number whose first digit is greater 
// than its last. Your program will reverse the number, and subtract the 
// reversal from the original number. Finally, reverse the resulting number, 
// and add it to its unreversed form. Output the final result. 
// The original number that the user enters must be of integer type (not three chars). 
// Think about how to write a function that takes an integer as input and returns 
// the reverse of that number. 
// Example:
// input number: 901
// reverse it: 109
// subtract: 901 - 109 = 792
// reverse it: 297
// add: 297 + 792 = 1089   
#include <iostream>

using namespace std;

int reverse(const int number);

int main(){
  
  int three_digit_number;
  cout << "Enter a 3 digit number whose first digit is greater that its last." << endl;
  cout << "input number: ";
  if( !(cin >> three_digit_number)){
    cout << "Error reading intput" << endl;
  } else {
    int reverse_number = reverse(three_digit_number);
    cout << "reverse it: " << reverse_number << endl;
    int substract_number = three_digit_number - reverse_number;
    cout << "substract: " << three_digit_number << " - " << reverse_number << " = " << substract_number << endl;
    reverse_number = reverse(substract_number);
    cout << "reverse it: " << reverse_number << endl;
    int add_number = reverse_number + substract_number;
    cout << "add: " <<  reverse_number << " + " << substract_number << " =  " << add_number << endl; 
    
  }
  
}

// number should be a 3 digit number
int reverse(const int number){
    int rest;
    int d_1;
    int d_2;
    int d_3;
    d_1 = number/ 100;
    rest = number - (d_1 * 100);
    d_2 = rest / 10;
    rest = rest - (d_2 * 10);
    d_3 = rest / 1;
    return d_3 * 100 + d_2 * 10 + d_1 * 1;
}
