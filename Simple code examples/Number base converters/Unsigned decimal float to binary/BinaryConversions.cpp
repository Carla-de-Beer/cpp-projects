// Carla de Beer
// Binary converter: unsigned decimal float to binary
// Date created: 06.08.2014

#include <string>
#include <string.h>
#include <sstream>
#include <cmath>
#include <iostream>

using namespace std;

/**
function to convert a float value to a string
*/
string convertToString(float input){
  ostringstream buff;
  buff << input;
  return buff.str();
}

/**
function to convert int value to a string
*/
string convertToInt(int input){
  ostringstream buff;
  buff << input;
  return buff.str();
}

/**
function to convert int value to a binary string
*/
string binaryDivisionRemainder(unsigned int _input) {
    if ( _input == 0 ) return "0";
    if ( _input == 1 ) return "1";
    if ( _input % 2 == 0 )
        return binaryDivisionRemainder(_input / 2) + "0";
    else
        return binaryDivisionRemainder(_input / 2) + "1";
}

/**
function to reverse a C-string
*/
void reverse(char word[]) {
    int len = strlen(word);
    char  temp;
    for (int i = 0;i < len/2;++i) {
            temp = word[i];
            word[i] = word[len-i-1];
            word[len-i-1] = temp;
    }
}

/**
function to convert a floating point value to a char array
*/
char * calculateFraction(float number, unsigned int bitCount){
 
  char * array = new char[bitCount];
  
  for(unsigned int i = 0; i < bitCount; ++i) {
    array[i] = '0';  
  }
  
  for(unsigned int i = 0; i < bitCount; ++i) {
    number = number*2;
    
    if(number >= 1) {
     number = number - 1;
     array[i] = '1';
    }    
  }
    
   return array;  
}

/**
function to convert a floating point decimal value to a floating point binary value
*/
string unsignedFloatToBinary(float _input, unsigned int _fractionalBits) {
  if (!cin.good()) {
    cout << "You entered an incorrect value. Please try again." << endl;
    cin.clear();
    cin.ignore(800, '\n');
    return "";
  }
  
  if((int)_input == 0) return "0";
  
  // get whole part of number
  
  int wholePart = static_cast<int>(_input);
  string wholeNumber = binaryDivisionRemainder(wholePart);  
  if(_fractionalBits == 0) return wholeNumber;  
 
  // get float part of number
  
  float intpart;
  float fractPart = modff(_input, &intpart);
  
  //cout << "fractPart = " << fractPart << endl; // works  
  char * res = calculateFraction(fractPart,_fractionalBits);    
  //cout << "res = " << res << endl; // works
  
  for(unsigned int i = _fractionalBits; i > 0; --i) {
    if(res[i] == '0') {
      res[i] = '\0';
    }    
    else if( res[i] == '1')
      break;
  }
  
  // cout << "res after loop = " << res << endl; // works 
  string result(res);   
  result = wholeNumber + ".";  
 // int resSize = result.size();  
  
  // remove unwanted zeros
  if(res[0] == '0' && res[1] == '\0') return wholeNumber;  
  result = result + res; 
  
  return result;	
}