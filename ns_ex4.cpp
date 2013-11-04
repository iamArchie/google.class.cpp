// ns_ex4.cpp: Santiago Arias
// Description: classes and objects

#include <iostream>

using namespace std;

// a simple time class
class Time{
private:
  int hours_;
  int minutes_;
  int seconds_;
public:
  void set(int h, int m, int s){hours_ = h; minutes_ = m; seconds_ = s;}
  void increment(void);
  void decrement(void);
  void display(void);
};

void Time::increment(void){
  seconds_++;
  minutes_ += seconds_/60;
  hours_ += minutes_/60;
  seconds_ %= 60;
  minutes_ %= 60;
  hours_ %= 24;
  return;
}


void Time::decrement(void){
  seconds_--;
  if(seconds_ < 0){
    seconds_ += 60;
    minutes_--;
  }
  if(minutes_ < 0){
    minutes_ += 60;
    hours_--;
  }
  if(hours_ < 0)
    hours_ += 24;
  return;
}

void Time::display(void){

  cout << (hours_ % 12? hours_%12:12) << ":" <<
    (minutes_ < 10 ? "0" : "" ) << minutes_ << ":" <<
    (seconds_ < 10 ? "0" : "") << seconds_ << 
    (hours_ < 12 ? " AM" : " PM") << endl;
}

int main(){

  Time timer; timer.set(23,59,58);
  for(int i = 0; i < 5; i++){
    timer.increment();
    timer.display();
  }
  cout << endl;
  for(int i = 4; i >= 0; i--){
    timer.decrement();
    timer.display();
  }

}
