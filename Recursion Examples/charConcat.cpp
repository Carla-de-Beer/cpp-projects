/*
 * Carla de Beer
 * October 2013
 * Code to concatenate C-strings recursively
 */

#include <iostream>
#include <cstring>
using namespace std;

char * concat(char * s1, char * s2);

int main()
{
  char word1[] = "Adding";
  char word2[] = "_together";
  char * t = concat(word1, word2);
  
  cout << t << endl;
  return 0;
}

char * concat(char * s1, char * s2)
{
  if(*s1 == '\0')
    return s2;
  
  if(*s2 == '\0')
    return s1;
  
  else // memory leak problem
  {
    char * t = new char[strlen(s1) + 1];
    strcpy(t, s1);
    s1 = new char[strlen(s1) + 2];
    strcpy(s1, t);
    delete t;
    t = 0;
    
    s1[strlen(s1)] = *s2;
    s1[strlen(s1) + 1] = '\0';
    concat(s1, ++s2);
    
  }
}
