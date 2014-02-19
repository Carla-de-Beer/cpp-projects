/*
  Carla de Beer
  Date created: 15.02.2014
*/

#ifndef LIST_H
#define LIST_H

#include "Queue.h"
#include "MyException.h"

template<class T>
class List;

template<class T>
ostream& operator<<(ostream&,List<T>&);

/*The List class should be implemented in terms of a Queue object.

Complete the Queue class first before attempting to implement this class.*/
template<class T>
class List
{
	public:
		/*The overloaded stream operator for the List class.  If
		a List object is printed and contains the elements a,c,b and m, with
		element 'a' at index 0 and element 'm' at index 3 (first to last), the 
		output must be in the following format:
		[a,c,b,m]
		*/
		friend ostream& operator<< <T>(ostream&,List<T>&);
		
		/*The constructor*/
		List();
		
		/*The copy constructor*/
		List(const List<T>& other);
		
		/*The overloaded assignment operator.*/
		List<T>& operator=(const List<T>& other);
		
		/*The destructor.*/
		~List();
		
		/*This function adds the element passed as a parameter to the front of 
		the list.  The parameter will become the first element in the list at 
		index 0.*/
		void addToFront(const T& el);
		
		/*This function adds the element passed as a parameter to the back of 
		the list.  The parameter will become the last element in the list.*/
		void addToBack(const T& el);
		
		
		/*This function accepts a numerical index and places the element passed 
		as a parameter at this index in the list.  
		
		It is always allowed to insert at index 0, even if the structure is 
		empty */
		
		void insertAtIndex(const int& index, const T& el);
		
		/*This function accepts an index from which an element is to be deleted 
		and subsequently returned.  All elements following the deleted element 
		shift one index to the left to close the hole left by the deleted 
		element in the list.*/
		T deleteAtIndex(const int& index);
		
		
		/*Returns the element at the index specified at the received parameter 
		without removing the element from the list
		*/
		T get(const int& index);
		
		/*Replaces the element at the index specified be the received parameter 
		with the second parameter
		*/
		void set(const int& index, const T& el);
		
		/*This function must return true if the list is empty and false 
		otherwise*/
		bool isEmpty();
	
	private:
		
		Queue<T>* queue;
};

#include "List.C"

#endif