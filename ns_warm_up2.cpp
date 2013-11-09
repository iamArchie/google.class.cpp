// ns_warm_up2.cpp: Santiago Arias
// Description: https://developers.google.com/edu/c++/next-steps

#include <iostream>
using namespace std;

// Book class:
class Book{
private:
  int code_;
  double price_;
  string str_mode_;
  string str_age_;
  bool is_new_;
  bool is_required_;  
  double percent_sold_;

  double compute_percent_sold(){
    if( is_required_ && is_new_ ){
      return 0.9;
    } else if( is_required_ && !is_new_ ){
      return 0.65;
    } else if( !is_required_ && is_new_ ){
      return 0.4;
    } else if( !is_required_ && !is_new_ ){
      return 0.2;
    }
    
  }
public:
  Book(int code, double price, int mode, int age ):
    code_(code), price_(price), percent_sold_(0) {

    is_new_ = (age == 1)? true : false;
    is_required_ = (mode == 1)? true : false;
    str_age_ = is_new_? "new" : "used";
    str_mode_ = is_required_? "required" : "optional";
    percent_sold_ = compute_percent_sold();

  }

  double get_precent_sold(){ return percent_sold_;}
  double get_price(){return price_;}
  int get_code(){return code_;}
  string get_mode(){return str_mode_;}
  string get_age(){return str_age_;}
};

int main(){

  int book_code(0);
  double single_copy_price;
  int number_on_hand(0);
  int prospective_enrollment(0);
  int book_mode;
  int book_age;
  
  double precent_sold;
  int number_books_to_order(0);
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

    cout << "1 for new/0 for used: 0: ";
    if(!(cin >> book_age)){
      continue;
    }

    Book book(book_code, single_copy_price, book_mode, book_age);
    number_books_to_order = (prospective_enrollment* book.get_precent_sold()) - number_on_hand;
    total_cost =  number_books_to_order * book.get_price();

    cout << "**************************************************" << endl;
    cout << "Book: " << book.get_code() << endl;
    cout << "Price: " <<  book.get_price() << endl;
    cout << "Inventory: " << number_on_hand << endl;
    cout << "Enrollement: " << prospective_enrollment << endl << endl;
    
    cout << "This book is " << book.get_mode() <<  " and " << book.get_age() << "." << endl;
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
