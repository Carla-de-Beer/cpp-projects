// Carla de Beer
// Number base converter: unsigned decimal float to any radix
// Date created: 06.08.2014

#include <iostream>
#include <string>

using namespace std;

string unsignedFloatToGivenBase(float _input, unsigned int _fractionalDigits, unsigned int _base);

int main() {
  cout << "Enter a floating point number for conversion:" << endl;
  float decimal;
  cin >> decimal;
  
  cout << "Enter the number of fractional bits:" << endl;
  unsigned int limit;
  cin >> limit;
  
  cout << "Enter the radix:" << endl;
  unsigned int radix;
  cin >> radix;
  
  string result = unsignedFloatToGivenBase(decimal, limit, radix);
  cout << "The binary value of " << decimal << " to " << limit << " digits in base " << radix <<  " bits is ";  
  cout << result<< endl;
  
  return 0; 
}