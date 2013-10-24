// gs_ex7.cpp: Santiago Arias
// Description: Next steps with decomposition

#include <iostream>

using namespace std;

#define kPricePerUnit 225 // avg price of pair of shoes
#define kWeeklyWage 600 // current weekly wage - method 1
#define kSalary 7.0 // hourly salary - method 2
#define kHoursPerWeek 40 // number of hours worked - method 2
#define kCommission2 0.1 // commission - method 2
#define kCommission3 0.2 // commission - method 3
#define kBonusPerUnit 20 // bonus - method 3

// To get weekly sales of units
void GetInput(int & WeeklySales){
  cout << "Enter number of units sold per week:" << endl;
  if( !(cin >> WeeklySales) ){
    cout << "Please enter only integers" << endl;
  }
  return;
}

// always $600 per week
void CalcMethod1(int WeeklySales){
  cout << "Method 1" << endl;
  cout << kWeeklyWage << endl;
}

// salary of 7$ per hour plus 10% commission on sale
void CalcMethod2(int WeeklySales){
  cout << "Method 2" << endl;
  int res = kSalary * kHoursPerWeek + kCommission2 * (WeeklySales * kPricePerUnit); 
  cout << "Total = " << res << endl;
}

// no salary, 20% commission on sales and 20 bonus per unit
void CalcMethod3(int WeeklySales){
  cout << "Method 3" << endl;
  int res  =kCommission3 * (WeeklySales * kPricePerUnit) + kBonusPerUnit * WeeklySales;
  cout << "Total = " << res << endl;
}

int main(void){

  int WeeklySales = 0;
  GetInput(WeeklySales);
  CalcMethod1(WeeklySales);
  CalcMethod2(WeeklySales);
  CalcMethod3(WeeklySales);
}
