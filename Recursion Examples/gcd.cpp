#include <iostream>
using namespace std;

int gcd(int x, int y);

int main()
{
  int result = gcd(8, 24);
  
  cout << "The greatest common divsior is: " << result << endl;

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
     //cout << "x % y = " << (double) (x % y) << endl;
     gcd(x,y);
   }
  }
  
  else
  {
   if(y % x == 0) return x;
   else
   {
    x = y % x;
    gcd(x,y);
   }
  }
}


/*
int gcd(int x, int y)
{
  
  if(x > y)
  {
   if(y == 0) return x;
   
   else
   {
    if (x == 0) return y;
    return (x, y%x);
   }
  }
  
}
*/