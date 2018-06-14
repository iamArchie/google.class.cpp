// gs_prj6.cpp: Santiago Arias
// Description: 
// The law requires that food product manufacturers place expiration dates 
// on their products, but there is a loophole in the law: 
// it does not require the expiration date to be in any particular form. 
// So, it can be written in Swahili and still be legal.
// Ralph Nader's third cousin, Nadine is a self-appointed Food Quality Spy. 
// She has learned that many food product manufacturers have started encoding 
// the product expiration dates to keep customers from knowing how old the stuff is.

// But the encoding does allow grocers to figure out the expiration dates if 
// for some reason, they want to.

// One popular encoding method:

// encode the months from Jan to Dec as 'A' through 'L'
// encode each digit of the date as 'Q' through 'Z'
// encode the year as 'A' through 'Z' meaning 1 through 26 which is then added to 1995.
// Nadine found a particularly questionable loaf of bread with this date: ARZM. 
// Write a program to determine the date.

#include <iostream>
using namespace std;


int main(){

 string code;
 cin>>code;

 string month[12]={"Jan","Feb","Mar","Apr","May","Jun",
                   "Jul","Aug","Sep","Oct","Nov","Dec"};
 int digit_day[]={0,1,2,3,4,5,6,7,8,9};

 string One="ABCDEFGHIJKL";
 string Two="QRSTUVWXYZ";


 for(int i=0; i<12; i++){
    if(code[0]==One[i]){
            cout<<month[i];
            break;}
 }

 for(int i=0; i<10;i++){
    if(code[1]==Two[i]){
        cout<<" / "<<i;
        break;
    }
 }

 for(int i=0; i<10;i++){
    if(code[2]==Two[i]){
        cout<<i<<" / ";
        break;
    }
 }

 cout<<1995+(code[3]-'A'+1);




 }
