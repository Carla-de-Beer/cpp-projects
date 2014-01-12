<<<<<<< HEAD
// Carla de Beer
// October 2013
// Code to calculate Ackermann numbers recursively

=======
>>>>>>> Added files
#include <iostream>
#include <cstring>
using namespace std;

int ack(int m, int n);

int main()
{    
    cout <<  ack(1, 2) << endl;	
    return 0;
}

int ack(int m, int n)
{
 if(m == 0)
   return n + 1;
 else if (n == 0 && m > 0)
 {
    return ack(m-1, 1);

 }
 else
 {
    return ack((m-1), ack(m, n-1));
 }
}