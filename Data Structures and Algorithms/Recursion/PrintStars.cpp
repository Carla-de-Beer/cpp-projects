<<<<<<< HEAD
// Carla de Beer
// October 2013
// Code to print a star triangle recursively

#include <iostream>
=======
#include <iostream>

>>>>>>> Added files
using namespace std;

void printStars(int );
void printTriangle(int );

int main()
{
  //printStars(5);
  printTriangle(5);
  cout << endl;
  
  return 0;
}

void printStars(int num)
{
 if(num == 0) return;
 printStars(num-1);
 cout << "*";
}

void printTriangle(int level)
{
 if(level == 0) return; 
 printTriangle(level-1);
 printStars(level);
 cout << endl;
}