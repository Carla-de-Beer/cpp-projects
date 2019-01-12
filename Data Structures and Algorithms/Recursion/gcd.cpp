// Carla de Beer
// October 2013
// Code to calculate the Greatest Common Denominator recursively

#include <iostream>
using namespace std;

int gcd(int, int);
int gcdRecursive(int, int); 

int main()
{
  int result = gcd(8, 24);
  cout << "gcd(8, 24): The greatest common divsior is: " << result << endl;

  result = gcdRecursive(54, 24);
  cout << "gcd(54, 24): The greatest common divsior is: " << result << endl;
  
  return 0;
}

int gcd(int x, int y)
{
  if (x > y)
  {
   if (x % y == 0)
     return y;
   
   else 
   {
     y = x % y;
     gcd(x, y);
   }
  }
  
  else
  {
   if (y % x == 0) return x;
   else
   {
    x = y % x;
    gcd(x, y);
   }
  }
}

int gcdRecursive(int a, int b) 
{
  if (a == 0) {
    return b;
  } 
  return gcd(b % a, a);
}