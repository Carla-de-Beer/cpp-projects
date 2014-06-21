/*
  Carla de Beer
  Date created: 15.02.2014
*/

#include "List.h"

template <class T>
List<T>::List()
{
  queue = new Queue<T>();
}

template <class T>
List<T>::List(const List<T>& other)
{
   queue = new Queue<T>();
  *(this->queue) = *(other.queue);  
}

template <class T>
List<T>& List<T>::operator=(const List<T>& other)
{
  if(this != &other)
  {
    while(!this->isEmpty())
    {
	 queue->dequeue();
    }
    
    *(this->queue) = *(other.queue);    
  }
  return *this;
}

template <class T>
List<T>::~List()
{
  if(queue)
  {
    delete queue;
    queue = 0;
  }
}

template <class T>
void List<T>::addToFront(const T& el)
{
  if(!isEmpty())
  {
   Queue<T> temp;
   temp.enqueue(el);
   while(!(queue->isEmpty()))
   {
     temp.enqueue(queue->dequeue());
   }
  
  *queue = temp;
  }
  else
    queue->enqueue(el);
}

template <class T>
void List<T>::addToBack(const T& el)
{
    queue->enqueue(el);
}

template <class T>
void List<T>::insertAtIndex(const int& index, const T& el)
{
  if(!isEmpty())
  {
    // Check for index out of bounds
    int count = 0;
    Queue<T> temp1;
    temp1 = *queue;
    
    while(!(temp1.isEmpty()))
    {
      count++;
      temp1.dequeue();
    }
    
    if((count-1) < index || index < 0 || index != static_cast<int>(index))
    {
      throw MyException("Index out of bounds or invalid");
    }
    
    Queue<T> temp2;
    Queue<T> temp3;
    int i = 0;
    
    while(!(queue->isEmpty()))
    {
      temp2.enqueue(queue->dequeue());
    }
    
    while(i < index)
    {
      temp3.enqueue(temp2.dequeue()); 
      ++i;
    }
    
    temp3.enqueue(el); 
    
    while(!temp2.isEmpty())
    {
      temp3.enqueue(temp2.dequeue());
    }
    *queue = temp3;
  }
  
  else if (queue->isEmpty() && index == 0)
  {
    queue->enqueue(el);
  }
   else if (queue->isEmpty() && index != 0)
  {
    throw MyException("Attempt to access element in an empty list");
  }
}

template <class T>
T List<T>::deleteAtIndex(const int& index)
{
  if(isEmpty())
  {
    throw MyException("Attempt to access element in an empty list");
  }
  else
  {
    // Check for index out of bounds
    int count = 0;
    Queue<T> temp1;
    temp1 = *queue;
    
    while(!(temp1.isEmpty()))
    {
      count++;
      temp1.dequeue();
    }
    
    if((count-1) < index || index < 0 || index != static_cast<int>(index))
    {
      throw MyException("Index out of bounds or invalid");
    }
    
    // deleteAtIndex
    Queue<T> temp2;
    Queue<T> temp3;
    int i = 0;
    
    while(!(queue->isEmpty()))
    {
      temp2.enqueue(queue->dequeue());
    }
    
    while(i < index)
    {
      temp3.enqueue(temp2.dequeue());
      ++i;
    }
    
    T answer = temp2.dequeue();
    
    while(!temp2.isEmpty())
    {
      temp3.enqueue(temp2.dequeue()); 
    }
    
    *queue = temp3; 
    return answer;
  }
  
}

template <class T>
T List<T>::get(const int& index)
{
  if(isEmpty())
  {
    throw MyException("Attempt to access element in an empty list");
  }
  
  else 
  {
    // Check for index out of bounds
    int count = 0;
    Queue<T> temp1;
    temp1 = *queue;
    
    while(!(temp1.isEmpty()))
    {
      count++;
      temp1.dequeue();
    }
    
    if((count-1) < index || index < 0 || index != static_cast<int>(index))
    {
      throw MyException("Index out of bounds or invalid");
    }

    // Get value
    Queue<T> temp2;
    temp2 = *queue;
    int i = 0;
    
    while(i < (index))
    {
      temp2.dequeue();
      ++i;
    }
    
    return temp2.dequeue();
  }
}

template <class T>
void List<T>::set(const int& index, const T& el)
{
  if (!isEmpty())
  {
    // Check for index out of bounds
    int count = 0;
  
    Queue<T> temp1;
    temp1 = *queue;
    
    while(!(temp1.isEmpty()))
    {
      count++;
      temp1.dequeue();
    }
    
    if((count-1) < index || index < 0 || index != static_cast<int>(index))
    {
      throw MyException("Index out of bounds or invalid");
    }
    
    // Swap value
    int i = 0;
    Queue<T> temp2;
    
    while ( i < index)
    {
      temp2.enqueue(queue->dequeue()); 
      ++i;
    }
    temp2.enqueue(el);
    queue->dequeue();
    
    while(!(queue->isEmpty()))
    {
      temp2.enqueue(queue->dequeue()); 
    }
    
    *queue = temp2;
  }
  
  if (isEmpty() && index == 0)
  {
    queue->enqueue(el); 
  }
  
  else if (isEmpty() && index != 0)
  {
    throw MyException("Attempt to access element in an empty list");
  }
}

template <class T>
bool List<T>::isEmpty()
{
  if(queue)
  {
      return (queue->isEmpty());
  }
  else
      return false;
}

template <class T>
ostream& operator<< (ostream& out,List<T>& aList) // Problem here
{
   
   out << *(aList.queue);
    
     return out;
}


