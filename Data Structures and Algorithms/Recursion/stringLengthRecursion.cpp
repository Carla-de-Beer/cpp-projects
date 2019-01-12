// Carla de Beer
// October 2013
// Code to calculate a string length recursively

#include <iostream>
#include <cstring>
using namespace std;

int strlength(char *s);

int main()
{    
	char word[] = "words";
	char *ptr = word;
	cout << "Word length = " << strlength(ptr) << endl;
	return 0;
}

int strlength(char *s)
{
	if(*s == '\0') 
		return 0;
	else 
		return 1 + strlength(s +1); 	
}
