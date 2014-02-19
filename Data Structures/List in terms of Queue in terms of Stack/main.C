/*
  Carla de Beer
  Date created: 15.02.2014
*/

#include "Queue.h"
#include "Stack.h"
#include "List.h"
#include "MyException.h"
#include <iostream>

using namespace std;


int main(int argc, char** argv)
{	
  
      Stack<int>  stack1;
      Stack<int>  stack2;
      Stack<int>  stack4;

      if (stack1.isEmpty())
      cout << "Stack1 is empty." << endl; 
      else 
	cout << "Stack1 is not empty." << endl;

      cout << "Stack1: " << stack1 << endl;
      
      cout << "Try to pop empty stack: " << endl;
      
      try
      {
	stack1.pop();
      }
      
      catch (MyException e)
      {
	cout << "ERROR: " << e.getCause() << endl;
      }
      
      cout << "Try to peek into empty stack: " << endl;
      
      try
      {
	stack1.peek();
      }
      
      catch (MyException e)
      {
	cout << "ERROR: " << e.getCause() << endl;
      }
      
      stack1.push(1);
      stack1.push(3);
      stack1.push(7);
      stack1.push(4);
      
      stack4.push(5);
      stack4.push(3);
      stack4.push(8);
      stack4.push(2);
      
      cout << "Stack1: " << stack1 << endl;
      cout << "Stack2: " << stack2 << endl;
      cout << "Stack4: " << stack4 << endl;
      Stack<int>  stack5(stack1);
              stack5 = stack4;
      cout << "Stack5: " << stack5 << endl;
   
      Stack<int> stack3(stack1);
 
      cout << "Stack3 (should be the same as Stack1: " << stack3 << endl;
      cout << "Stack1: " << stack1 << endl;
      stack3.push(8);
      stack3.push(6);
      cout << "Stack3 (pushed 8, 6) " << stack3 << endl;
      
      cout << "Stack2: " << stack2 << endl;
      
      cout << "Try to peek into Stack2: " << endl;
      
      try
      {
	cout << "Peek into Stack2: " << stack2.peek() << " " << endl;
	cout << "Peek into Stack2: " << stack2.peek() << " " << endl;
      }
      
      catch (MyException e)
      {
	cout << "ERROR: " << e.getCause() << endl;
      }

      // pop()
      try{
      stack2.pop();
      cout << "Pop top off Stack2: " << stack2 << endl;
      stack2.pop();
      cout << "Pop top off Stack2: " << stack2 << endl;
      stack2.pop();
      cout << "Pop top off Stack2: " << stack2 << endl;
      stack2.pop();
      cout << "Pop top off Stack2: " << stack2 << endl;
      }
            catch (MyException e)
      {
	cout << "ERROR: " << e.getCause() << endl;
      }
      try
      {
	stack2.pop(); 
      }
      catch (MyException e)
      {
	cout << "ERROR: " << e.getCause() << endl;
      }
      try
      {
	stack2.pop(); 
      }
      catch (MyException e)
      {
	cout << "ERROR: " << e.getCause() << endl;
      }
      stack1 = stack1;
      cout << "Stack1: " << stack1 << endl;
      
      if (stack3.isEmpty())
      cout << "Stack3 is empty." << endl; 
      else 
	cout << "Stack3 is not empty." << endl;
      
      if (stack2.isEmpty())
      cout << "Stack2 is empty." << endl; 
      else 
	cout << "Stack2 is not empty." << endl;
      
      cout << "Stack1: " << stack1 << endl;
      cout << "Stack2: " << stack2 << endl;
      cout << "Stack3: " << stack3 << endl;
      
      cout << endl;
      
      // -----------------------------------------------
	


      Queue<int> queue1;
      Queue<int> queue2;
      Queue<int> queue3(queue2);
      Queue<int> queue4;
      
      queue4.enqueue(3);
      cout << "Queue4: " << queue4 << endl;
      
      if (queue1.isEmpty())
      cout << "Queue1 is empty." << endl; 
      else 
	cout << "Queue1 is not empty." << endl;
	      
      cout << "Queue1: " << queue1 << endl;
      cout << endl;
      
      try
      {
	queue1.dequeue(); 
      }
      catch (MyException e)
      {
	cout << "ERROR: " << e.getCause() << endl;
      }
      
      queue1.enqueue(3);
      queue1.enqueue(8);
      queue1.enqueue(5);
      queue1.enqueue(8);
      queue1.enqueue(10);
      queue1.enqueue(7);
      cout << "Queue1: " << queue1 << endl;
      
      cout << endl;
      
      int r = queue1.dequeue();
      cout << "r: " << r << endl;
      cout << "Queue1: " << queue1 << endl;
      
      queue1.dequeue();
      queue1.enqueue(2);
      queue2 = queue1;

      cout << "Queue1 (remove top and enqueue 2): " << queue1 << endl;
      cout << "Queue2 (should be same as Queue1): " << queue2 << endl;
      cout << "Queue3: " << queue3 << endl;
      queue2 = queue3;
      cout << "Queue2 (should be same as Queue3): " << queue2 << endl;
      cout << "Queue4: " << queue4 << endl;
      
      Queue<int> queue5(queue1);
      cout << "Queue1: " << queue1 << endl;
      cout << "Queue5 (should be same as Queue1): " << queue5 << endl;
      
      // dequeue()
      try
      {
	queue1.dequeue();
      }
      catch (MyException e)
      {
	cout << "ERROR: " << e.getCause() << endl;
      }
      cout << "Queue1: " << queue1 << endl;
      try
      {
	queue1.dequeue();
      }
      catch (MyException e)
      {
	cout << "ERROR: " << e.getCause() << endl;
      }
      cout << "Queue1: " << queue1 << endl;
      try
      {
	queue1.dequeue();
      }
      catch (MyException e)
      {
	cout << "ERROR: " << e.getCause() << endl;
      }
      cout << "Queue1: " << queue1 << endl;
      try
      {
	queue1.dequeue();
      }
      catch (MyException e)
      {
	cout << "ERROR: " << e.getCause() << endl;
      }
      cout << "Queue1: " << queue1 << endl;
      cout << endl;
      try
      {
	queue1.dequeue();
      }
      catch (MyException e)
      {
	cout << "ERROR: " << e.getCause() << endl;
      }
      try
      {
	queue1.dequeue();
      }
      catch (MyException e)
      {
	cout << "ERROR: " << e.getCause() << endl;
      }
      
      if (queue2.isEmpty())
      cout << "Queue2 is empty." << endl; 
      
      else 
	cout << "Queue2 is not empty." << endl;
      
      if (queue3.isEmpty())
      cout << "Queue3 is empty." << endl; 
      else 
	cout << "Queue3 is not empty." << endl;
      
      queue1.enqueue(5);
      
      if (queue1.isEmpty())
      cout << "Queue1 is empty." << endl; 
      else 
	cout << "Queue1 is not empty." << endl;
      
      queue2.enqueue(3);
      queue2.enqueue(8);
      queue2.enqueue(5);
      queue2.enqueue(8);
      queue2.enqueue(2);
    
      // increasePriority()
      cout << "Queue2: " << queue2 << endl;
      queue2.increasePriority(12);
      cout << "Queue2 increase priority of 12: " << queue2 << endl;
      queue2.increasePriority(2);
      cout << "Queue2 increase priority of 2: " << queue2 << endl;
      queue2.increasePriority(2);
      cout << "Queue2 increase priority of 2: " << queue2 << endl;
      queue2.increasePriority(2);
      cout << "Queue2 increase priority of 2: " << queue2 << endl;
      queue2.increasePriority(5);
      cout << "Queue2 increase priority of 5: " << queue2 << endl;
      queue2.increasePriority(8);
      cout << "Queue2 increase priority of 8: " << queue2 << endl;
      queue2.increasePriority(10);
      cout << "Queue2 increase priority of 10: " << queue2 << endl;
      

    
      // -----------------------------------------------
      
      List<int> list1;
      List<int> list2;
      List<int> list4;
      List<char> list5;
      
      if (list1.isEmpty())
      cout << "List1 is empty." << endl; 
      else 
	cout << "List1 is not empty." << endl;
      
      //list2 = list1;
      
      list1.addToFront(5);
      list1.addToFront(9);
      list1.addToFront(3);
      list1.addToBack(1);
      list1.addToFront(0);
      
      list2 = list1;
      
      cout << "List1: " << list1 << endl;
      cout << "List2 add 3 to front: " << endl;
      list2.addToFront(3);
      cout << "List2 add 7 to back: " << endl;
      list2.addToBack(7);
      cout << "List2 (should be same as List1): " << list2 << endl;
      List<int> list3(list2);
      cout << "List3 (should be same as List2): " << list3 << endl;
      
     
      
      cout << "List1: " << list1 << endl;	
      cout << "List2: " << list2 << endl;
      
      cout << endl;
      
      // get()
      
      cout << "Testing get() " << endl;
      try
      {	
	cout << "The List1 index value at position 2: " << list1.get(2) << endl;
      }
      catch (MyException e)
      {
	cout << "ERROR: " << e.getCause() << endl;
      }
      try
      {	
	cout << "The List1 index value at position 0: " << list1.get(0) << endl;
      }
      catch (MyException e)
      {
	cout << "ERROR: " << e.getCause() << endl;
      }
      try
      {	
	cout << "The List1 index value at position 3: " << list1.get(3) << endl;
      }
      catch (MyException e)
      {
	cout << "ERROR: " << e.getCause() << endl;
      }
      try
      {	
	cout << "The List1 index value at position 4: " << list1.get(4) << endl;
      }
      catch (MyException e)
      {
	cout << "ERROR: " << e.getCause() << endl;
      }
      
      cout << "Try to access index 9: " << endl;
      
      try
      {	
	cout << "The List1 index value at position 9: " << list1.get(9) << endl;
      }
      catch (MyException e)
      {
	cout << "ERROR: " << e.getCause() << endl;
      }
      
      cout << "Try to access index -1: " << endl;
      
      try
      {	
	cout << "The List1 index value at position -1: " << list1.get(-1) << endl;
      }
      catch (MyException e)
      {
	cout << "ERROR: " << e.getCause() << endl;
      }
      
      cout << endl;
      
      // set()
      
      cout << "Testing set() " << endl;
      
      cout << "Insert 7 at position 3 list2: " << list2 << endl;
      try
      {	
	list2.set(3,7);
      }
      catch (MyException e)
      {
	cout << "ERROR: " << e.getCause() << endl;
      }
      
      cout << "Insert 7 at position 30: " << list2 << endl;
      try
      {	
	list2.set(30,7);
      }
      catch (MyException e)
      {
	cout << "ERROR: " << e.getCause() << endl;
      }
      cout << "Insert 7 at position -1: " << list2 << endl;
      try
      {	
	list2.set(-1,7);
      }
      catch (MyException e)
      {
	cout << "ERROR: " << e.getCause() << endl;
      }
      cout << "Insert 7 at position 6.75: " << list2 << endl; // throw execption???
      try
      {	
	list2.set(6.75,7);
      }
      catch (MyException e)
      {
	cout << "ERROR: " << e.getCause() << endl;
      }
      
      cout << "List2: " << list2 << endl;
      
      
      cout << endl;
      
      // deleteAtIndex()
      cout << "Testing deleteAtIndex() " << endl;
      try
      {	
	list2.deleteAtIndex(2);
      }
      catch (MyException e)
      {
	cout << "ERROR: " << e.getCause() << endl;
      }
      
      cout << "List2 deleted at index 2: " << list2 << endl;
      
      try
      {	
	list2.deleteAtIndex(0);
      }
      catch (MyException e)
      {
	cout << "ERROR: " << e.getCause() << endl;
      }
      
      cout << "List2 deleted at index 0: " << list2 << endl;
      
      cout << "Try to delete List2 at index -4: " << list2 << endl;
      
      try
      {	
	list2.deleteAtIndex(-4);
      }
      catch (MyException e)
      {
	cout << "ERROR: " << e.getCause() << endl;
      }
      
      try
      {	
	// Empty list test
	//cout << "List4 (empty) delete at index 5: " << endl;
	//list4.deleteAtIndex(5); 
	//list4.insertAtIndex(0,5); 
	//list4.addToFront(3); 
	//list4.addToBack(4); 
	//list4.addToBack(5); 
	//cout << "List4 (empty) get at index 4: " << endl;
	//list4.get(4); 
	//cout << "List4 (empty) set at index 2: " << endl;
	//list4.set(4,4); 
	//list4.set(0,4); 
	cout << "List4: " << list4 << endl;
      }
      catch (MyException e)
      {
	cout << "ERROR: " << e.getCause() << endl;
      }
           
      cout << endl;
      
      // insertAtIndex()
       cout << "Testing insertAtIndex() " << endl;
      try
      {	
	list2.insertAtIndex(2,5);
      }
      catch (MyException e)
      {
	cout << "ERROR: " << e.getCause() << endl;
      }
      
      cout << "List2 inserted 5 at index 2: " << list2 << endl;
      
      try
      {	
	list2.insertAtIndex(0,3);
      }
      catch (MyException e)
      {
	cout << "ERROR: " << e.getCause() << endl;
      }
      
      cout << "List2 inserted 3 at index 0: " << list2 << endl;
      
      cout << "Try to insert 3 at index -1 List2: " << endl;
      
      try
      {	
	list2.insertAtIndex(-1,3);
      }
      catch (MyException e)
      {
	cout << "ERROR: " << e.getCause() << endl;
      }
      
      cout << "Try to insert 3 at index 14 List2: " << endl;
      
      try
      {	
	list2.insertAtIndex(14,3);
      }
      catch (MyException e)
      {
	cout << "ERROR: " << e.getCause() << endl;
      }
      
      cout << endl;
      
      list5.addToBack('m');
      list5.addToFront('b');
      list5.addToFront('c');
      list5.addToFront('a');

      cout << "List5: " << list5 << endl;
      
      
      return 0;	
}
	
