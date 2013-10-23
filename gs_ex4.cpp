// gs_ex4.cpp: Santiago Arias
// Description: Guess a secret number game
#include <iostream>
#include <stdlib.h>
#include <time.h>

using namespace std;

int main(void){
  
  // Initialize random seed
  srand(time(NULL));
  
  // Generate random number between 1 and 100
  int guess_number = 0;
  int random_number = rand() % 100 + 1;
  bool found = false;
  do{
    if(!(cin >> guess_number)){
      cout << "You entered a non-numeric value. Try again." << endl;
      cin.clear();
      cin.ignore(1000, '\n');
    }else{
      if(guess_number < random_number){
	cout << "number is lower than secret number" << endl;
      }else if(guess_number > random_number){
	cout << "number is higher than secret number" << endl;
      }else{
	cout << "you found the secret number!" << endl;
	found = true;
      }      
    }
  }while(!found);
  cout << "Your random number:" << random_number << endl;
  return 0;
}
