// gs_ex5_bis.cpp: Santiago Arias
// Description: How many ways can you arrange 6 different books, left to right, on a shelf?

#include <iostream>

using namespace std;

int main(void){
  int arrangement = 0;
  for(int b1 = 0; b1 < 6; b1++){
    for(int b2 = 0; b2 < 6; b2++){
      for(int b3 = 0; b3 < 6; b3++){
	for(int b4 = 0; b4 < 6; b4++){
	  for(int b5 = 0; b5 < 6; b5++){
	    for(int b6 = 0; b6 < 6; b6++){
	      if( ((b1 != b2)&& (b1 != b3) && (b1 != b4) && (b1 != b5) && (b1 != b6)   ) &&
		  ((b2 != b1)&& (b2 != b3) && (b2 != b4) && (b2 != b5) && (b2 != b6)   ) &&
		  ((b3 != b1)&& (b3 != b2) && (b3 != b4) && (b3 != b5) && (b3 != b6)   ) &&
		  ((b4 != b1)&& (b4 != b2) && (b4 != b3) && (b4 != b5) && (b4 != b6)   ) &&
		  ((b5 != b1)&& (b5 != b2) && (b5 != b3) && (b5 != b4) && (b5 != b6)   )){
		arrangement++;
	      }
	    }
	  }
	}
      }
    }
  }
  cout << "Number of arrangements: " << arrangement << endl;
  return 0;
}
