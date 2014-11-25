// Carla de Beer
// Binary converter: unsigned decimal float to binary
// Date created: 06.08.2014

#include <iostream>
#include <string>

using namespace std;

string unsignedFloatToBinary(float _input, unsigned int _fractionalBits);

int main() {
  
  cout << "Enter a floating point number for conversion:" << endl;
  float decimal;
  cin >> decimal;
  
  cout << "Enter the number of fractional bits:" << endl;
  unsigned int limit;
  cin >> limit;
  
  string result = unsignedFloatToBinary(decimal, limit);
  
  cout << "The binary value of " << decimal << " to " << limit << " bits is ";  
  cout << result<< endl;
  
  return 0; 
}