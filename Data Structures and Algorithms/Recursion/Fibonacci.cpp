<<<<<<< HEAD
// Carla de Beer
// October 2013
// Code to calculate Fibonacci numbers recursively

=======
>>>>>>> Added files
#include <iostream>
using namespace std;

unsigned long fibonacci(unsigned int n);

int main()
{
  cout << fibonacci(19) << endl;
  
  return 0;
}

unsigned long fibonacci(unsigned int n)
{
 if( (n == 1) || (n == 2) ) return n-1;
 else return fibonacci(n-1) + fibonacci(n-2);
}