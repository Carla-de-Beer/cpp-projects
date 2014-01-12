/*
 * Carla de Beer
 * October 2013
 * Code to calculate Catalan numbers recursively
 */

#include <iostream>
using namespace std;

int catalanNumber(int n);

int main()
{
  cout << catalanNumber(19) << endl;
  
  return 0;

}

int catalanNumber(int n)
{
  if (n==0)
  {
    return 1;
  }
  int result = 0;
  for(int i = 1; i <=n; ++i)
  {
    result+= catalanNumber(i - 1)*catalanNumber(n-i);
  }
  return result;
}
