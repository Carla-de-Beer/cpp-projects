/*
  Carla de Beer
  Date created: 15.02.2014
*/

#ifndef QUEUE_H
#define QUEUE_H

#include <iostream>
#include "MyException.h"
#include "Stack.h"

using namespace std;

template<class T>
class Queue;

template<class T>
ostream& operator<<(ostream&,Queue<T>&);

/*The Queue class should be implemented in terms a of a Stack object.

Complete the Stack class first before attempting to implement this class.*/
template<class T>
class Queue
{
	public:
		/*The overloaded stream operator for the Queue class.  If
		an object is printed and contains the elements 1,2,3 and 8, where 
		1 is at the front of the queue and 8 at the back, the output must be in 
		the following format:		
		[1,2,3,8]
		*/
		friend ostream& operator<< <T>(ostream&,Queue<T>&);
		
		/*The default constructor*/
		Queue();
		
		/*The copy constructor*/
		Queue(const Queue<T>& other);
		
		/*The overloaded assignment operator*/
		Queue<T>& operator=(const Queue<T>& other);
		
		/*The destructor*/
		~Queue();
		
		/*This function adds the element passed as a parameter to the back of 
		the queue*/
		void enqueue(const T& el);
		
		/*This function removes the first element from the queue and returns it
		*/
		T dequeue();
		
		/*It is possible in a queue structure to request that the priority of 
		an element in the queue should be increased.  When an element's 
		priority is increased, it is simply swapped with its predecessor in the 
		queue.  This function receives as a parameter the element of which the 
		priority should be increased.  Given the queue [5,6,7,8,9], after a 
		call to the increasePriority, function with the parameter 8, the queue 
		becomes [5,6,8,7,9].  If there are multiple instances of an element, 
		only the first instance of that element (reading the queue front to back) 
		should have its priority increased.		
		*/
		void increasePriority(const T& el);
		
		/*This function must return true if the queue is empty and false 
		otherwise*/
		bool isEmpty();
	
	private:
	
		Stack<T>* stack;
	
};

#include "Queue.C"
			 
#endif