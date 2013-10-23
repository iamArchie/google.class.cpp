// gs_ex4_bis.cpp: Santiago Arias
// Description: Greatest common divisor
#include <iostream>
using namespace std;

// a non-recursive version of Euclid's algorithm
int gcd(int a, int b){
  
  int temp;
  while(b !=0){
    temp = b;
    b = a%b;
    a = temp;
  }
  return a;
}

int main(void){
  int x, y;
  cout << "Enter two integers";
  if(!(cin >> x >> y)){
    cout << "Please enter only integers" << endl;
  }else{
    cout << "gcd(" << x << ", " << y << ") = " << gcd(x,y) << endl; 
  }
  return 0;
}
