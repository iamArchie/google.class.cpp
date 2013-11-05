// ns_warm_up1.cpp: Santiago Arias
// Description: perfect square, and is also the sum of the integers from 1 through n

#include <iostream>

using namespace std;

// sum of integers from 1 through x
// <=> n * (n+1)/2
long sum_of_integers(long x){
  return (x * (x + 1) )/ 2;
}

// is there a sum of integers that is equal to 'square'?
bool sum_of_integers_exist(long squared){
  for(long i = 0; i < squared; ++i){
    if(sum_of_integers(i) == squared) {
      cout << "sum of integers 1 through " << i << " = " << squared << endl;
      return true;
    }
  }
  return false;
}


int main(){

  long squared = 0;
  // start al 36 + 1 to search the next 'magic number'
  for(int i = 37; i < 5000; ++i){
    squared = i * i;
    if(sum_of_integers_exist(squared)){
      cout << i << " * " << i << " = " << squared << endl;
      break;
    }
  }
}
