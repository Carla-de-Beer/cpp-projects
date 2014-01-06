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
	//cout<<"1";
  if (*s != '\0') reverse(1+s); // if you use ++s, you skip the first character, rather use (s + 1) or (1 + s)
	//cout<<"2";
   cout << *s;
	//cout<<"3";
	
	// Alternative:
	
	/*
	if(*s == '\0') return;
	  else
	    reverse(s+1);
	   cout << *s;
	*/

}