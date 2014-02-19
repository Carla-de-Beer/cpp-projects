<<<<<<< HEAD
// Carla de Beer
// October 2013
// Code to calculate Ackermann numbers recursively

=======
>>>>>>> Added files
#include <iostream>
#include <cstring>
using namespace std;

int ackermann(int m, int n);

int main()
{    
    cout <<  ackermann(1, 2) << endl;	
    return 0;
}

int ackermann(int m, int n)
{
 if(m == 0)
   return n + 1;
 else if (n == 0 && m > 0)
 {
    return ackermann(m-1, 1);

 }
 else
 {
    return ackermann((m-1), ackermann(m, n-1));
 }
}