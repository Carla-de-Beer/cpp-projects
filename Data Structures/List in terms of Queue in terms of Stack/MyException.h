/*
  Carla de Beer
  Date created: 15.02.2014
*/

#ifndef MYEXCEPTION_H
#define MYEXCEPTION_H

#include <string>

using namespace std;

class MyException
{
	public:
		MyException(string s)
		{
			reason = s;
		}
		
		string getCause()
		{
			return reason;
		}
		
	private:
		string reason;
};

#endif
