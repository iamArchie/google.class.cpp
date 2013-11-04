// ns_ex3.cpp: Santiago Arias
// Description: Passing values by reference.

#include <iostream>

using namespace std;

void accelerate(double& speed, double amount_to_add){
  speed += amount_to_add;
}

int main(){

  double speed = 80;
  cout << speed << endl;
  accelerate(speed, 20);
  cout << speed << endl;
}
