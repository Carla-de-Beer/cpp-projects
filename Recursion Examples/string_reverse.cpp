/*
 * Carla de Beer
 * October 2013
 * Code to reverse a C-string recursively
 */

#include <iostream>
#include <cstring>
using namespace std;

void reverse(char * s);

int main()
{
  char * ptr = new char[10];
  strcpy(ptr, "words");
  reverse(ptr);
  cout << endl;
  
  return 0;
}

void reverse(char * s)
{
  if(*s == '\0') return;
  else
    reverse(s+1);
   cout << *s;
}
