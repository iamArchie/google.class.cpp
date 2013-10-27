// gs_prj6.cpp: Santiago Arias
// Description: 
// The law requires that food product manufacturers place expiration dates 
// on their products, but there is a loophole in the law: 
// it does not require the expiration date to be in any particular form. 
// So, it can be written in Swahili and still be legal.
// Ralph Nader's third cousin, Nadine is a self-appointed Food Quality Spy. 
// She has learned that many food product manufacturers have started encoding 
// the product expiration dates to keep customers from knowing how old the stuff is.

// But the encoding does allow grocers to figure out the expiration dates if 
// for some reason, they want to.

// One popular encoding method:

// encode the months from Jan to Dec as 'A' through 'L'
// encode each digit of the date as 'Q' through 'Z'
// encode the year as 'A' through 'Z' meaning 1 through 26 which is then added to 1995.
// Nadine found a particularly questionable loaf of bread with this date: ARZM. 
// Write a program to determine the date.

#include <iostream>

using namespace std;

string decode_month(const char month);
int decode_digit(const char day);
int decode_year(const char year);

int main(){

  string in;
  cout << "Enter a coded date." << endl;
  if( !(cin >> in)){
    cout<< "Error reading the date." << endl;
  } else {
    cout << "DD/MM/YYYY: " << decode_digit(in.substr(1,1)[0]) << decode_digit(in.substr(2,1)[0]) << "/" << decode_month(in.substr(0,1)[0]) << "/" <<  decode_year(in.substr(3,1)[0]) << endl;      
  }
}

int decode_year(const char year){

  return 64 - year + 1995;
}

int decode_digit(const char day){
  return day - 81;
}

string decode_month(char month){
  string decode;
  int base = month - 64;
  switch(base){
  case 1: 
    decode = "Jan";
    break;
  case 2: 
    decode = "Feb";
    break;
  case 3: 
    decode = "Mar";
    break;
  case 4: 
    decode = "Apr";
    break;
  case 5: 
    decode = "May";
    break;
  case 6: 
    decode = "Jun";
    break;
  case 7: 
    decode = "Jul";
    break;
  case 8: 
    decode = "Aug";
    break;
  case 9: 
    decode = "Sept";
    break;
  case 10: 
    decode = "Oct";
    break;
  case 11: 
    decode = "Nov";
    break;
  case 12: 
    decode = "Dec";
    break;
  default:
    cout << "Error in month: " << decode << endl;
  }
  return decode;
}
