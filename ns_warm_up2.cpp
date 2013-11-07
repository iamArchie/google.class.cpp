// ns_warm_up2.cpp: Santiago Arias
// Description: 

// Your college book store needs your help in estimating its business for next year. 
// Experience has shown that sales depend greatly on whether a book is required for a 
// course or just optional, and whether or not it has been used in the class before. 
// A new, required textbook will sell to 90% of prospective enrollment, but if it has 
// been used in the class before, only 65% will buy. 
// Similarly, 40% of prospective enrollment will buy a new, optional textbook, but if 
// it has been used in the class before only 20% will buy. 
// (Note that "used" here does not mean second-hand books.)

// Write a program that accepts as input a series of books (until the user enters a sentinel).

// For each book ask for: 
//   - a code for the book, 
//   - the single copy cost for the book, 
//   - the current number of books on hand, 
//   - the prospective class enrollment, 
//   - data that indicates if the book is required/optional
//   - new/used in past. 

// As output, 
//   - show all the input information in a nicely formatted screen 
//   - how many books must be ordered (if any, note that only new books are ordered),
//   - the total cost of each orders.


// Then, after all input is complete.

// show:
//     - the total cost of all book orders
//     - the expected profit if the store pays 80% of list price
//     - process one book at a time
//     - show the output screen for that book.
 
// Then, when the user has finished entering all the data.
//   your program should output:
//   - the total
//   - profit values.

// Before you start writing code, take some time to think about design of this program. 
// Decompose into a set of functions, and create a main() function that reads like an outline 
// for your solution to the problem. Make sure each function does one task.

#include <iostream>
using namespace std;

int main(){
  int book_code;
  double single_copy_price;
  int number_on_hand;
  int prospective_enrollment;
  
  int book_mode;
  string str_book_mode;
  bool book_required = false;
  bool book_optional = false;

  int book_age;
  string str_book_age;
  bool book_new = false;
  bool book_used = false;

  int another_book(0);
  do{

    cout << "Please enter the book code:"; 
    if(!(cin >> book_code)){
      continue;
    }

    cout << "single copy price:" ;
    if(!(cin >> single_copy_price)){
      continue;
    }

    cout << "number on hand:" ;
    if(!(cin >> number_on_hand)){
      continue;
    }

    cout << "prospective enrollment:";
    if(!(cin >> prospective_enrollment)){
      continue;
    }

    cout << "1 for reqd/0 for optional:";
    if(!(cin >> book_mode)){
      continue;
    }
    if(book_mode == 1) {
      book_required = true;
    }else{
      book_optional = true;
    }

    cout << "1 for new/0 for used: 0:";
    if(!(cin >> book_age)){
      continue;
    }
    if(book_age == 1) {
      book_new = true;
    }else{
      book_used = true;
    }

    cout << "**************************************************" << endl;
    cout << "Book:" << book_code << endl;
    cout << "Price:" <<  single_copy_price << endl;
    cout << "Inventory:" << number_on_hand << endl;
    cout << "Enrollement:" << prospective_enrollment << endl << endl;
    
    cout << "This book is" << str_book_mode <<  "and" << str_book_age << "." << endl;
    cout << "**************************************************" << endl;
    cout << "Need to order:" << endl; 
    cout << "Total Cost:" << /*number_books_to_order*single_copy_price <<*/ endl;
    cout << "**************************************************" << endl << endl;
    
    cout << "Enter 1 to do another book, 0 to stop. 0";
    if( !(cin >> another_book)){
      continue;
    }
  }while(another_book == 1);


  // show:
  // total cost of books ordered
  // expected profit it the store pays 80% of list price
  // process one book at a time
  // show the output screen for that book.

  //output total
  // output profil values.
}
