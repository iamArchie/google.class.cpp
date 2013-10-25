// gs_ex9.cpp: Santiago Arias
// Description: An illustration of file processing
#include <fstream>
#include <iostream>

using namespace std;

int main(){
  char first_name[30], last_name[30]; int age;
  char file_name[20];
  char done;
  // Collect the data.
  cout << endl << "Enter the name of the file: "; cin >> file_name;

  // Create an ofstream called People, open the stream for output.
  ofstream People(file_name, ios::out);
  // Write the output to the stream.

  while(1){
    cout << "Enter First Name: "; cin >> first_name;
    cout << "Enter Last Name: "; cin >> last_name;
    cout << "Enter Age: "; cin >> age;
    People << first_name << endl << last_name << endl << age << endl;
    cout << "Continue? (y/n)"<< endl;
    cin >> done;
    if(done == 'n'){
      break;
    }
  }
  People.close();

  ifstream People_in (file_name, ios::in);
  while(1){
    People_in >> first_name >> last_name >> age;

    if(People_in.eof()){
      break;
    }
    cout << endl << "Enter First Name: " << first_name;
    cout << endl << "Enter Last Name: " << last_name;
    cout << endl << "Enter Age: " << age;
    cout << endl;
  }

  People_in.close();
  return 0;
}
