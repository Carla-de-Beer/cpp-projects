// Carla de Beer
// Binary converter: uses both the division-remainder and repeated subtraction methods
// Run the code and enter an unsigned decimal integer for conversion
// Date created: 06/08/2014

#include <iostream>
#include <cmath>

using namespace std;

string repeatedSubtraction(unsigned int _input);
string divisionRemainder(unsigned int _input);


int main() {  
  cout << "Enter an unsigned decimal number for conversion:" << endl;
  int decimal;
  cin >> decimal;
  
  cout << "The binary value of " << decimal << " is ";
  cout << divisionRemainder(decimal);
  cout << " when using the division remainder method." << endl;
  
  cout << "The binary value of " << decimal << " is ";
  cout << repeatedSubtraction(decimal) ;
  cout << " when using the repeated subtraction method." << endl;
  
  return 0; 
}


void reverse(char word[]) {
    int len=strlen(word);
    char  temp;
    for (int i=0;i<len/2;i++) {
            temp=word[i];
            word[i]=word[len-i-1];
            word[len-i-1]=temp;
    }
}

int check(unsigned int _input, int i) {
    while (_input >= pow(2,i)) {
     ++i;
   }  
   
   return i;
}

string repeatedSubtraction(unsigned int _input) {
  if (_input == 0) return "0";
  
   int i = 0;
   char * array;  

   // get number of iterations for the powers of 2
   while (_input >= pow(2,i)) {
     ++i;
   }  
   
   int size = i;
   
   // create an array with i number of places
   array = new char[size];
     
   // set all the positions in the array to zero
   for(int j = 0; j < i; ++j)
     array[j] = '0';
   
   // add 1 for the i-th position
    array[i-1] = '1';
   
   // reduce the original input
    _input = _input - pow(2,i-1);    

    
   while (_input >= 1 && i != 0) {
     int j = 0;
      j = check(_input, j);
     array[j-1] = '1'; 
      _input = _input - pow(2,j-1);  
   }  

   // reverse the array
   reverse(array); 
    
   // convert as a string
   string str(array);    
   delete [] array;    
   return str;     
}


string divisionRemainder(unsigned int _input) {
    if ( _input == 0 ) return "0";
    if ( _input == 1 ) return "1";
    if ( _input % 2 == 0 )
        return divisionRemainder(_input / 2) + "0";
    else
        return divisionRemainder(_input / 2) + "1";
}
