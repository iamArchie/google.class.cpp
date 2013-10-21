//  gs_ex1.cpp: Santiago Arias
// Description: a program that prints the immortal saying "hello world"

#include <iostream>
#include <iomanip> // needed for setw

using namespace std;

int main(){

  // set up cout to right-align. if not set default is left align
  cout<< setiosflags(ios::left);
  for(int i = 0; i < 6; i++){
    for(int j = 0; j < 4; j++){
      // setw(int) sets the column width
      cout << setw(17);
      cout << "Hello World!";
    }
    cout<< endl;
  }
  return 0;
}
