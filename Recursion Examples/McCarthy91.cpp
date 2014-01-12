/*
 * Carla de Beer
 * October 2013
 * Code to calculate McCarthy91 numbers recursively
 */

#include <iostream>
#include <cstring>
using namespace std;

int McCarthy91(int n);

int main()
{    
    cout <<  McCarthy91(87) << endl;	
    return 0;
}

int McCarthy91(int n)
{
  if (n > 100)
    return n - 10;
  
  else
  {
    n = McCarthy91(McCarthy91(n + 11));
    return n;
  }
}
