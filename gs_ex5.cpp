// gs_ex5.cpp: Santiago Arias
// Description: Math Puzzles
#include <iostream>

using namespace std;

int main(void){

  double horse = 10;
  double pig = 3;
  double rabbit = 0.5;

  double budget = 100;
  int number_animals = 0;
  int number_horse = 0;
  int number_pig = 0;
  int number_rabbit = 0;
  int temp;

  // horse
  temp = budget/horse;
  if(temp > 0){
    if( (number_animals + temp <= 100) && ((budget - number_animals*horse) >= 0)){
      number_animals += temp;
      number_horse = temp;
      budget = budget - number_animals*horse;
    }
  }
  // pig
  temp = budget / pig;
  if(temp > 0){
    if( (number_animals + temp <= 100) && ((budget - number_animals*pig) >= 0)){
      number_animals += temp;
      number_pig = temp;
      budget = budget - number_animals*pig;
    }
  }
  // rabbit
  temp = budget / rabbit;
  if(temp > 0){
    if( (number_animals + temp <= 100) && ((budget - number_animals*rabbit) >= 0)){
      number_animals += temp;
      number_rabbit = temp;
      budget = budget - number_animals*rabbit;
    }
  }
  cout << "Number of horses: " << number_horse << endl;
  cout << "Number of pigs: " << number_pig << endl;
  cout << "Number of rabbit: " << number_rabbit << endl;
  cout << "Budget: " << number_horse*horse + number_pig*pig + number_rabbit*rabbit << endl;
  return 0;
}
