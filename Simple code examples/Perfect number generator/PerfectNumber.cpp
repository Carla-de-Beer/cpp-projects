// Created by: Carla de Beer
// Perfect number generator
// Date updated: 21.04.2013

# include <iostream>
# include <sstream>
# include <iomanip>
# include <cmath>

using namespace std;

int main ()
{
	string stringLimit;
	int intLimit = 0;
	float floatLimit = 0;
	
	int sumDivisors = 0;
	
	cout << "Enter a positive integer: ";
	cin >> stringLimit;
	
	
	// --------------------------------------------------------------------- Input validation
	it;
	stringstream (stringLimit) >> floatLimit;
	
	intLimit = static_cast<int> (floatLimit); // cast input into integer
	

	if ( floatLimit - floor(floatLimit) != 0 || !isdigit( stringLimit[0] )  || intLimit <= 0 )
	{
	
		cout << "You entered " << stringLimit << ". Please enter only positive integers." << endl;
		
		return 1;
	}
	
	
	//cout << "intLimit  = " << intLimit << endl; // fine
	
	// --------------------------------------------------------------------- Loops
	
	
	
	for (int i = 2; i <= intLimit; ++i)
	{								
		if (i % 2 == 0)
		{
		
			for (int j = 2; j <=  (i/2); ++j)			
			{						
				if ( ( i % j  == 0 ) )
				{					
					sumDivisors = j + sumDivisors;	
								
				}
			}

			sumDivisors = 1 + sumDivisors;	
				
			if (sumDivisors == i)
					
			{
				cout << i << " is a perfect number" << endl;

			}
				
			sumDivisors = 0;
				
		}
	}					
	cout << "There are no more perfect numbers less than or equal to " << intLimit << endl;	
	
	return 0;
}


