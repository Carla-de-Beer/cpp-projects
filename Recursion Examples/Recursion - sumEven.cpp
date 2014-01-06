/* Carla de Beer
 * October 2013
 * Code to sum a set of even numbers recursively
 */

#include <iostream>
#include <cstring>
using namespace std;

int sumEven(const int a[], unsigned int n);

int main()
{
  int array[] = {5,6,2,4,7,3};
  unsigned int length = 6;
  int answer = sumEven(array, length);
  cout << answer << endl;
  
  return 0;
}

int sumEven(const int a[], unsigned int n)
{
  if(n==0) return 0;
  else if(a[n-1] % 2 == 0) return sumEven(a, n-1) + a[n-1];
  else return sumEven(a,n-1);
}