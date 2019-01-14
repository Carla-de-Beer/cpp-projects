// Carla de Beer
// October 2013
// Code to calculate the Greatest Common Denominator recursively

#include <iostream>
using namespace std;

int gcd1(int, int);
int gcd2(int, int); 

int main()
{
  int result = gcd1(8, 24);
  cout << "gcd(8, 24): The greatest common divsior is: " << result << endl;

  result = gcd2(54, 24);
  cout << "gcd(54, 24): The greatest common divsior is: " << result << endl;
  
  return 0;
}

int gcd1(int x, int y)
{
  if (x > y)
  {
   if (x % y == 0)
     return y;
   
   else 
   {
     y = x % y;
     gcd1(x, y);
   }
  }
  
  else
  {
   if (y % x == 0) return x;
   else
   {
    x = y % x;
    gcd1(x, y);
   }
  }
}

int gcd2(int a, int b) 
{
  if (a == 0) {
    return b;
  } 
  return gcd2(b % a, a);
}