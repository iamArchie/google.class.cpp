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

  double get_percent_sold(){ return percent_sold_;}
  double get_price(){return price_;}
  int get_code(){return code_;}
  string get_mode(){return str_mode_;}
  string get_age(){return str_age_;}
};

class Inventory{
private: 
  int number_on_hand_;
  int prospective_enrollment_;
  int books_to_order_;
  double total_cost_;
  double total_orders_;
  
public:
  // default constructor
  Inventory():books_to_order_(0), number_on_hand_(0), prospective_enrollment_(0), total_cost_(0), total_orders_(0){}
  void set_inventory(int number_on_hand, int prospective_enrollment){
    number_on_hand_ = number_on_hand;
    prospective_enrollment_ = prospective_enrollment;
    books_to_order_ = 0;
    total_cost_ = 0;
  }
  
  void set_books_to_order(double precent_sold){
    books_to_order_ = (prospective_enrollment_* precent_sold) - number_on_hand_;
  }
  int get_books_to_order(){return books_to_order_;}

  void set_total_cost(double book_price){
    total_cost_ = books_to_order_ * book_price;
  }
  double get_total_cost(){return total_cost_;}

  void add_order(){
    total_orders_ += total_cost_;
  }

  double get_total_orders(){ return total_orders_;}
  double get_profit(){return total_orders_ * 0.2;}
  int get_number_on_hand(){return number_on_hand_;}
  int get_prospective_enrollment(){return prospective_enrollment_;}
  void reset_book_inventory(){
    books_to_order_ = 0;
    number_on_hand_ = 0;
    prospective_enrollment_ = 0;
    total_cost_ = 0;
  }

};

void print_stats(Inventory &inventory, Book &book){
  cout << "**************************************************" << endl;
  cout << "Book: " << book.get_code() << endl;
  cout << "Price: " <<  book.get_price() << endl;
  cout << "Inventory: " << inventory.get_number_on_hand() << endl;
  cout << "Enrollement: " << inventory.get_prospective_enrollment() << endl << endl;
  
  cout << "This book is " << book.get_mode() <<  " and " << book.get_age() << "." << endl;
  cout << "**************************************************" << endl;
  cout << "Need to order: " << inventory.get_books_to_order() << endl; 
  cout << "Total Cost: " << inventory.get_total_cost() << endl;
  cout << "**************************************************" << endl << endl;
}

void print_total_and_profit(Inventory & inventory){
  cout << "**************************************************" << endl << endl;
  cout << "Total for all orders: " << inventory.get_total_orders() << endl;
  cout << "Profit: " << inventory.get_profit() << endl;
  cout << "**************************************************" << endl << endl;
}

int main(){

  int book_code(0);
  double single_copy_price;
  int number_on_hand(0);
  int prospective_enrollment(0);
  int book_mode;
  int book_age;
  
  int another_book(0);

  Inventory inventory;
  do{
    // after reading each book and inventory information reset it.
    // keep track of total_orders, order info can go away
    inventory.reset_book_inventory();

    // read input
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
    
    // create book object and init current inventory
    Book book(book_code, single_copy_price, book_mode, book_age);
    inventory.set_inventory(number_on_hand, prospective_enrollment);
    inventory.set_books_to_order(book.get_percent_sold());
    inventory.set_total_cost(book.get_price());
    
    print_stats(inventory, book);
    
    cout << endl << "Enter 1 to do another book, 0 to stop.";
    if( !(cin >> another_book)){
      continue;
    }
    inventory.add_order();
  
  }while(another_book == 1);

  print_total_and_profit(inventory);
}
