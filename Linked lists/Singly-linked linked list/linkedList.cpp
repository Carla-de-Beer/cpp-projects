#include "linkedList.h"
#include <iostream>
#include <cassert>

using namespace std;

template <class T>
LinkedList<T>::~LinkedList() 
{
	deallocateList();
}

template <class T>
int LinkedList<T>::count = 0; // initialisation static member variable

template <class T>
int LinkedList<T>::getCount() const
{
  return count;
}

template <class T>
void LinkedList<T>::copyList(const LinkedList& other) 
{  
	if (head != NULL)
		deallocateList();
	if (other.head) // other list is not empty
	{  
		Node *current = other.head;
		head = new Node(current->info, NULL);
		head->info = current->info;//
		//head->link = NULL;//
		current = current->link;
		Node *newNode;
		Node *prev = head;
		while (current) {
			newNode = new Node(current->info, NULL);
			//newNode->info = current->info;//
			//newNode->link = NULL;//
			prev->link = newNode;
			prev = newNode;
			current = current->link;
		}
	}
	else {  // other list is empty
		head = NULL;
	}

}

template <class T>
void LinkedList<T>::deallocateList() 
{
	Node *temp;
	while (head != NULL)	
	{
		temp = head;
		head = head->link;
		delete temp;
	}
}

template <class T>
LinkedList<T>::LinkedList(const LinkedList& other) 
{
	head = NULL;
	copyList(other);
	//cout << "Calling copy constructor" << endl;
}

template <class T>
LinkedList<T>& LinkedList<T>::operator=(const LinkedList<T>& other)
{
	if (this != &other)
		copyList(other);
	return *this;
}

template <class T>
int LinkedList<T>::getElementCount(Node * current) const
{
  assert(current);
  count++;
  if(!current) return 0;
  
  if(!current->link) return 1; 
  else
  {
    return 1 + getElementCount(current->link);
  }
}


template <class T>
int LinkedList<T>::getElementCount() const
{	  
  return getElementCount(head);
}

template <class T>
void LinkedList<T>::insertFirst(T item) 
{
	Node *newNode = new Node(item, head);
	head = newNode;
}

template <class T>
void LinkedList<T>::insertLast(T item) 
{
	Node *newNode = new Node(item, NULL);	
	if (head == NULL) 
		head = newNode;
	else	{
		Node *current = head;		
		while (current->link != NULL) 
			current = current->link;		
		current->link = newNode;
	}
}

template <class T>
void LinkedList<T>::deleteItem(T item)
{
	Node *current = head, *prev = NULL;
	while (current && current->info != item) 
	{
		prev = current;
		current = current->link;
	}
	if (prev == NULL)  // delete first element 
	{
		head = current->link;
		delete current;
	}
	else if (current != NULL) // was found 
	{ 
		prev->link = current->link;
		delete current;
	}
}

template <class T>
LinkedList<T> LinkedList<T>::operator+(const LinkedList<T>& other) const 
{
	LinkedList bigList = *this;
	Node *current = other.head;
	while(current) {
		bigList.insertLast(current->info);	
		current = current->link;
	}
	return bigList;
}

