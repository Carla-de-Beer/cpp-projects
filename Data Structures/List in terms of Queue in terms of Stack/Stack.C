/*
  Carla de Beer
  Date created: 15.02.2014
*/

#include "Stack.h"
#include "MyException.h"
#include <iostream>
#include <cstdlib>
using namespace std;

template <class T>
Stack<T>::Stack()
{
  top = NULL;
}

template <class T>
Stack<T>::Stack(const Stack<T>& other)
{  
  top = NULL;
  // if stack is not empty, reset it first (delete all contents)
    if (!isEmpty()) 
    {
      //Node *temp = NULL;
    
    // continue deleting nodes while there are any remaining
      while (top != NULL)
      {
	//temp = top;
	top = top->next;
	//delete temp;
      }
  }
  
  if (other.top == NULL)
  {
      top = NULL;
  }
  else
    {
	// the situation where otherStack contains at least 1 element
	// start by copying the first node in otherStack
	Node *source = other.top;	    
	top = new Node(source->element, NULL);
	Node *destination = top;
	source = source->next;
	
	//copy the remaining nodes
	while (source != NULL)
	{
	    Node *newNode = new Node(source->element, NULL);
	    destination->next = newNode;
	    destination = newNode;
	    source = source->next;
	}
    }
}

template <class T>
Stack<T>& Stack<T>::operator=(const Stack<T>& other)
{
  if (this != &other)
  {
  // if stack is not empty, reset it first (delete all contents)
    if (!isEmpty()) 
    {
      Node *temp = NULL;
    
    // continue deleting nodes while there are any remaining
      while (top != NULL)
      {
	      temp = top;
	      top = top->next;
	      delete temp;
      }
  }
  
  if (other.top == NULL)
  {
	  // the situation where otherStack is empty
	  top = NULL;
  }
  else
    {
	  // the situation where otherStack contains at least 1 element
	  // start by copying the first node in otherStack
	  Node *source = other.top;	    
	  top = new Node(source->element, NULL);
	  
	  Node *destination = top;
	  source = source->next;
	  
	  //copy the remaining nodes
	  while (source != NULL)
	  {
	      Node *newNode = new Node(source->element, NULL);
	      destination->next = newNode;
	      destination = newNode;
	      source = source->next;
	  }
    }
  
  }
    return *this;    
}

template <class T>
Stack<T>::~Stack()
{
    Node *temp = NULL;  
    // continue deleting nodes while there are any remaining
    while (top != NULL)
    {
	    temp = top;
	    top = top->next;
	    delete temp;
    }
}

template <class T>
void Stack<T>::push(const T& el)
{
  Node *newNode = new Node(el, top);
  top = newNode;  
}

template <class T>
T Stack<T>::pop()
{    
  if(isEmpty())
  {
	throw MyException("Attempt to access top in an empty stack");
  }
  else
  {
	Stack<T> element;	
	Node *temp = top;
	element.push(temp->element);
	top = top->next;
	delete temp;
	temp = NULL;	
	return element.peek();
  }
}

template <class T>
T Stack<T>::peek()
{
  if (isEmpty())
  {
      throw MyException("Attempt to access top in an empty stack");    
  }
    
 return top->element;   
}

template <class T>
bool Stack<T>::isEmpty()
{
  return (top == NULL);
}

template <class T>
ostream& operator<< (ostream& out,Stack<T>& aStack)
{
   out << "[";
   if(!aStack.isEmpty())
   {
      typename Stack<T>::Node *temp = aStack.top;
      out << temp->element;
      temp = temp->next;
      while(temp != NULL)
      {
	out << "," << temp->element;
	temp = temp->next;
      }
   }
   out << "]";

   return out;
}