// gs_prj1.cpp: Santiago Arias
// Description:
// The common field cricket chirps in direct proportion to the 
// current temperature. Adding 40 to the number of time a cricket 
// chirps in a minute, then dividing that value by 4 gives us the 
// temperature. Write a program that takes as input the number of 
// chirps in a minute and prints the current temperature. 
// For example,
// Number of chirps: 120
// The temperature is: 40.0 degrees. 
#include <iostream>

using namespace std;

#define kAddTime 40
#define kDivisor 4

int main(void){
  int number_chirps;
  double temperature;
  
  cout << "Number of chirps:";
  if( ! (cin >> number_chirps)){
    cout << "Enter an integer number." << endl;
  } else {
    temperature = (number_chirps + kAddTime)/ kDivisor;
    cout << endl << "The temperature is: " << temperature << " degrees." << endl; 
  }
  return 0;
}
