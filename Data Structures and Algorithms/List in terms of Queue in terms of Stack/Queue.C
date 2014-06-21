/*
  Carla de Beer
  Date created: 15.02.2014
*/

#include "Queue.h"
#include <cstdlib>

template <class T>
 Queue<T>::Queue() 
{
  stack = new Stack<T>();
}

template <class T>
Queue<T>::Queue(const Queue<T>& other)
{
  stack = new Stack<T>();
  *(this->stack) = *(other.stack);  
  
}

template <class T>
Queue<T>& Queue<T>::operator=(const Queue<T>& other)
{
  if(this != &other)
  {
    while(!this->isEmpty())
    {
	 stack->pop();
    }
    
    *(this->stack) = *(other.stack);   
  }
  return *this;
}


template <class T>
Queue<T>::~Queue()
{
  if(stack)
  {
    delete stack;
    stack = 0;
  }
}

template <class T>
void Queue<T>::enqueue(const T& el)
{  
  if(!isEmpty())
  {
    Stack<T> temp;
    
    while(!(stack->isEmpty()))
    {
      temp.push(stack->pop());
    }

    stack->push(el);
    while(!(temp.isEmpty()))
    {
      stack->push(temp.pop());
    }
  }
  else
  {
   stack->push(el); 
  }
}

template <class T>
T Queue<T>::dequeue()
{
    if (this->isEmpty())
    {
	throw MyException("Attempt to access element in an empty queue");
    } 
  
   return stack->pop();
}

template <class T>
void Queue<T>::increasePriority(const T& el)
{ 
 if(!(stack->isEmpty()) && (stack->peek()) != el)
  {
    Stack<T> temp1;
    Stack<T> temp2;
    Stack<T> temp3;
    Stack<T> temp4;
    Stack<T> temp5;
    temp5 = *stack;
    
    while(!(stack->isEmpty()) && stack->peek() != el) 
    {
      temp1.push(stack->pop());     
    } 
    
    if(!(stack->isEmpty())) // if stack is empty then number isn't inside list
    {
      temp2.push(temp1.pop());
      stack->pop(); // elminate el from stack
      
      while(!(stack->isEmpty())) 
      {
      temp3.push(stack->pop());    
      }
    
      while(!(temp3.isEmpty())) // reverse
      {
      temp4.push(temp3.pop());    
      }
      
      temp4.push(temp2.pop());
      temp4.push(el);
    
      while(!(temp1.isEmpty())) // reverse
      {
      temp4.push(temp1.pop());    
      }

      *(this->stack) = temp4;
    }
    
    else
      *stack = temp5; // inefficient but works
 }  
 }  
 

template <class T>
bool Queue<T>::isEmpty()
{
  if(stack)
  {
      return (stack->isEmpty());
  }
  else
      return false;
}

template <class T>
ostream& operator<< (ostream& out,Queue<T>& aQueue)
{
    out << *(aQueue.stack);
     return out;
}