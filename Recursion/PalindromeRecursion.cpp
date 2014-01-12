<<<<<<< HEAD
// Carla de Beer
// October 2013
// Code to determine a palindrome recursively 

#include <iostream>
#include <cstring>
=======
 #include <iostream>
  #include <cstring>
>>>>>>> Added files
using namespace std;

bool isPalindrome(char[], int size);

int main()
{
	cout << "Enter a string: ";
	char str[20];

	cin.getline(str,20,'\n');
	cout << "The entered string " << ( (isPalindrome(str,strlen(str)+1))? "is":"is not" ) << " a Palindrome string." << endl;
	return 0;
}

bool isPalindrome(char * str, int size)
{
	if (*str!= str[size-2]) //if first element is not equal to last element.
		return false;
	
	else if (strlen(str) <= 1) // if length is 1 or null-terminating
		return true;
	
	else
		return isPalindrome(++str,size-2); // can use ++s or (s+1) in this case
}