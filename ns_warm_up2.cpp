// ns_warm_up2.cpp: Santiago Arias
// Description: https://developers.google.com/edu/c++/next-steps

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

  double precent_sold;
  int number_books_to_order;
  int another_book(0);
  double total_cost(0);
  double total_orders(0);
  double profit(0);
  do{
    total_orders += total_cost;
    total_cost = 0;
    
    cout << "Please enter the book code: "; 
    if(!(cin >> book_code)){
      continue;
    }

    cout << "single copy price: " ;
    if(!(cin >> single_copy_price)){
      continue;
    }

    cout << "number on hand: " ;
    if(!(cin >> number_on_hand)){
      continue;
    }

    cout << "prospective enrollment: ";
    if(!(cin >> prospective_enrollment)){
      continue;
    }

    cout << "1 for reqd/0 for optional: ";
    if(!(cin >> book_mode)){
      continue;
    }
    if(book_mode == 1) {
      book_required = true;
      str_book_mode = "required";
    }else{
      book_optional = true;
      str_book_mode = "optional";
    }

    cout << "1 for new/0 for used: 0: ";
    if(!(cin >> book_age)){
      continue;
    }
    if(book_age == 1) {
      book_new = true;
      str_book_age = "new";
    }else{
      book_used = true;
      str_book_age = "used";
    }

    if( book_required && book_new ){
      precent_sold = 0.9;
    } else if( book_required && book_used ){
      precent_sold = 0.65;
    } else if( book_optional && book_new ){
      precent_sold = 0.4;
    } else if( book_optional && book_used ){
      precent_sold = 0.2;
    }
    number_books_to_order = (prospective_enrollment* precent_sold) - number_on_hand;
    total_cost =  number_books_to_order * single_copy_price;

    cout << "**************************************************" << endl;
    cout << "Book: " << book_code << endl;
    cout << "Price: " <<  single_copy_price << endl;
    cout << "Inventory: " << number_on_hand << endl;
    cout << "Enrollement: " << prospective_enrollment << endl << endl;
    
    cout << "This book is " << str_book_mode <<  " and " << str_book_age << "." << endl;
    cout << "**************************************************" << endl;
    cout << "Need to order: " << number_books_to_order << endl; 
    cout << "Total Cost: " << total_cost << endl;
    cout << "**************************************************" << endl << endl;
    
    cout << endl << "Enter 1 to do another book, 0 to stop.";
    if( !(cin >> another_book)){
      continue;
    }
    total_orders += total_cost;
    total_cost = 0;
  }while(another_book == 1);

  profit = total_orders * 0.2;
  cout << "**************************************************" << endl << endl;
  cout << "Total for all orders: " << total_orders << endl;
  cout << "Profit: " << profit << endl;
  cout << "**************************************************" << endl << endl;
}
