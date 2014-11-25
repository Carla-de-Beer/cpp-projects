// Carla de Beer
// Number base converter: unsigned decimal float to any radix
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

int * convertStringToIntArray(const string& str, int size) {
    int * newArray = new int[size];
  
    for(int i = 0; i < size; ++i) {     
    if(str[i] == '1') newArray[i] = 1;
    if(str[i] == '2') newArray[i] = 2;
    if(str[i] == '3') newArray[i] = 3;
    if(str[i] == '4') newArray[i] = 4;
    if(str[i] == '5') newArray[i] = 5;
    if(str[i] == '6') newArray[i] = 6;
    if(str[i] == '7') newArray[i] = 7;
    if(str[i] == '8') newArray[i] = 8;
    if(str[i] == '9') newArray[i] = 9;  
  }
  
  return newArray;
}


char *toBaseWhatever(int num, int rad) {
    char digits[] = "0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ!@";
    int i;
    char buf[66];   

    if (rad < 2 || rad > 62)
        return NULL;

    if (!num)
        return strdup("0");

    buf[65] = '\0';
    i = 65;

    if (num > 0) {  
        while (num) {          
            buf[--i] = digits[num % rad];
            num /= rad;
        }
    } else {  
        while (num) {
            buf[--i] = digits[-(num % rad)];
            num /= rad;
        }
        buf[--i] = '-';
    }   

    return strdup(buf + i);
}

string convertToString(char * array) {
	string result(array); 	
	return result;	
}

char * calculateFraction(float number, unsigned int bitCount, unsigned int radix) {
  char digits[] = "0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ!@"; 
  char * array = new char[bitCount];
  
  for(unsigned int i = 0; i < bitCount; ++i) {
    array[i] = '0';  
  }
  
  for(unsigned int i = 0; i < bitCount; ++i) {
    number = number*radix;
    
    // cout << "number1 = " << number << endl;    
    // number = number + 0.00001;
  
    unsigned int intpart = (int) number;
    // cout << "intpart = " << intpart << endl; // works
    
    if(intpart >= 1) {
     number = number - intpart; // works

     if(intpart > 9) {
       char solution = digits[(int)intpart];
       array[i] = solution;
     }
     else {
       string s = convertToInt(intpart);
       array[i] = s[0]; 
     }
    } 
  }
  
  string result(array); 
   
  return array;  
}

string unsignedFloatToGivenBase(float _input, unsigned int _fractionalDigits, unsigned int _base) { 
  if((int)_input == 0) return "0";
  
  // get whole part of number
  
  int wholePart = static_cast<int>(_input);
  
  char * answer = toBaseWhatever(wholePart, _base);
  string wholeNumber = convertToString(answer);
  
  if(_fractionalDigits == 0) return wholeNumber;
  
  float intpart;
  float fractPart = modff(_input, &intpart);
  
  char * fractionalPart = calculateFraction(fractPart, _fractionalDigits, _base);
  
  // cout << "fractionalPart = " << fractionalPart << endl;
  
  string res(fractionalPart);
  
  string result(fractionalPart); 
  result = wholeNumber + ".";
  
  // remove unwanted zeros
  if(res[res.size()-1] == '0' && res.size() == 1) {
    return wholeNumber;
  }
  
  if(res[res.size()-1] == '0') {
    //res[res.size()-1] = '\0';
  }
  
   for(unsigned int i = _fractionalDigits; i > 0; --i) {
    if(res[i] == '0') {
      res[i] = '\0';
    }    
    else if( res[i] == '1')
      break;
  }
  
  //int mantissaSize = res.size();
  int * resCharArray = convertStringToIntArray(res, res.size());
  
  int sum = 0;
  
  for(unsigned int i = 0; i < res.size(); ++i) {
    sum = sum + resCharArray[i];    
  }
  
  if(sum == 0) return wholeNumber;  
  result = result + res; 

  return result;	
}