// ns_ex2.cpp: Santiago Arias
// Description: pointers
#include <iostream>

using namespace std;

void print_intptr(int *p){
  cout << "@: " << p << " val: " << *p << endl;  
}
void test_1(){
  int *intptr; // Declare a pointer that holds the adress
  // of a memory location that can store an integer.
  // Note the use of * to indicate this is a pointer variable.
  intptr = new int; // Allocate memory for the integer.
  *intptr = 5;
  
}

void test_2(){
  int *ptr; // Declare integer pointer.
  ptr = new int; // Allocate some memory for the integer.
  *ptr = 5; // Dereference to initialize the pointee.
  *ptr = *ptr + 1; // We are dereferencing ptr in order
  // to add one to the valued stored at the ptr address.
  print_intptr(ptr);
}

void test_3(){
  int *x; // Allocate the pointerx and y
  int *y; // (but not the pointees).
  
  x = new int; // Allocate an int pointee and set x to point to it.

  *x = 42; // Dereference x and store 42 in its pointee.

  //*y = 13; // Crash -- y does not have a pointee yet.

  y = x; // Pointer assignment sets y to point to x's pointee

  *y = 13; // Dereference y and store 13 in its (shared) pointee.
  print_intptr(x);
  print_intptr(y);
}

void test_4(){
  int my_int = 46; // Declare a normal integer variable.
  // Set it equal to 46.

  // Declare a pointer and make it point to the variable my_int
  // by using the address-of operator.
  int *my_pointer = &my_int;

  print_intptr(&my_int); // Displays 46.

  *my_pointer = 107;
  print_intptr(&my_int); // Displays 107
  print_intptr(my_pointer); // Also displays 107
}

void test_5(){
  int *ptr1; // Declare a pointer to int.
  ptr1 = new int; // Reserve storage and point to it.

  float *ptr2 = new float; // Do it all in the same statement

  delete ptr1; // Free storage.
  delete ptr2;
  
}

void Duplicate(int &a, int &b, int &c){
  a *= 2;
  b *= 2;
  c *= 2;
}

// C version
void Duplicate_ex(int *a, int *b, int *c){
  *a *= 2;
  *b *= 2;
  *c *= 2;
}
void test_6(){
  int x = 1, y = 2, z = 3;
  print_intptr(&x);
  print_intptr(&y);
  print_intptr(&z);
  Duplicate(x,y,z);
  print_intptr(&x);
  print_intptr(&y);
  print_intptr(&z);
  Duplicate_ex(&x,&y,&z);
  print_intptr(&x);
  print_intptr(&y);
  print_intptr(&z);  
}

void DoIt(int &foo, int goo) {
  foo = goo + 3;
  goo = foo + 4;
  foo = goo + 3;
  goo = foo;
} 

void test_7(){
  int *foo, *goo;
  foo = new int;
  *foo = 1;
  goo = new int;
  *goo = 3;
  *foo = *goo + 3;
  foo = goo;
  *goo = 5;
  *foo = *goo + *foo;
  DoIt(*foo, *goo);
  cout << (*foo) << endl;
}

int main(){
  test_1();
  test_2();
  test_3();
  test_4();
  test_5();
  test_6();
  test_7();
  return 0;
}
