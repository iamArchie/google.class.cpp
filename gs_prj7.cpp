// gs_prj7.cpp: Santiago Arias
// Description: 
// This is a number analogy to a famous card trick. 
// Ask the user to enter a three-digit number. 
// Think of the number as ABC (where A, B, C are the three digits of the number). 
// Now, find the remainders of the numbers formed by ABC, BCA, and CAB when divided by 11. 
// We will call these remainders X, Y, Z. 
// Add them up as X+Y, Y+Z, Z+X. 
// If any of the sums are odd, increase or decrease it by 11 
// (whichever operation results in a positive number less than 20; 
// note if the sum is 9, just report this and stop the process). 
// Finally, divide each of the sums in half. 
// The resulting digits are A, B, C. 
// Write a program that implements this algorithm.

#include <iostream>
using namespace std;

int main(){
  int three_digit_number;
  int a,b,c;
  cout<< "Enter a three digit number: ";

  if( !(cin >> three_digit_number)){
    cout<< "error reading number"<< endl;
    return 0;
  }
  a = three_digit_number/100;
  b = (three_digit_number - (a *100))/10;
  c = three_digit_number - (a * 100) - (b * 10);

  int abc = a * 100 + b * 10 + c;
  int bca = b * 100 + c * 10 + a;
  int cab = c * 100 + a * 10 + b;

  int abc_rest, X = abc - (abc/11)*11;
  int bca_rest, Y = bca - (bca/11)*11;
  int cab_rest, Z = cab - (cab/11)*11;

  cout << X <<endl;
  cout << Y <<endl;
  cout << Z <<endl;


  int XY = X + Y;
  int YZ = Y + Z;
  int ZX = Z + X;

  // Add them up as X+Y, Y+Z, Z+X. 
  // If any of the sums are odd, increase or decrease it by 11 
  // (whichever operation results in a positive number less than 20; 
  // note if the sum is 9, just report this and stop the process). 
  
  if( (XY % 2) == 1 ){
    if( (XY + 11) < 20){
      XY += 11;
    } else {
      XY -= 11;
    }

    if( XY == 9){
      cout << "X + Y is 9" << endl;
    }
  }

  if( (YZ % 2) == 1){
    if( (YZ + 11) < 20){
      YZ += 11;
    } else {
      YZ -= 11;
    }
    
    if( YZ == 9){
      cout << "Y + Z is 9" << endl;
    }
  }

  if( (ZX % 2) == 1){
    if( (ZX + 11) < 20){
      ZX += 11;
    } else {
      ZX -= 11;
    }
    if( ZX == 9){
      cout << "Z + X is 9" << endl;
    }
  }
  // devide in half
  XY = XY/2;
  YZ = YZ/2;
  ZX = ZX/2;
  
  cout << "A: " << XY << " B: " << YZ << " C: " << ZX << endl;
  
}
