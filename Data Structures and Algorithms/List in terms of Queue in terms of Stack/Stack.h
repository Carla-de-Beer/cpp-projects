#ifndef STACK_H
#define STACK_H

#include "Queue.h"
#include "MyException.h"
#include <iostream>

using namespace std;

template<class T>
class Stack;

template<class T>
ostream& operator<<(ostream&,Stack<T>&);

template<class T>
class Stack
{
	public:
		/*The overloaded stream operator for the Stack class.  If
		a Stack object is printed and contains the elements 4,7,3 and 1, where 
		4 is at the top of the stack, the output must be in the following 
		format:
		[4,7,3,1]
		*/
		friend ostream& operator<< <T>(ostream&,Stack<T>&);

		/*The constructor for the Stack class*/
		Stack();
		
		/*The copy constructor*/
		Stack(const Stack<T>& other);
		
		/*The overloaded assignment operator.*/
		Stack<T>& operator=(const Stack<T>& other);
		
		/*The destructor for the stack class*/
		~Stack();
		
		/*This function adds the element passed as a parameter to the top of 
		the stack*/
		void push(const T& el);
		
		/*This function removes the top element from the stack and returns it */
		T pop();
		
		/*This function returns the top element of the stack without removing 
		it.*/
		T peek();
		
		/*This function must return true if the stack is empty and false 
		otherwise*/
		bool isEmpty();

	private:
		/*The node class.*/
		class Node
		{
			public:
				Node(const T& data, Node* n = 0)
				{
					element = data;
					next = n;
				}
				
				T element;
				Node* next;
		};
		
		/*The top of the stack*/
		Node* top;
	
};

#include "Stack.C"
			 
#endif