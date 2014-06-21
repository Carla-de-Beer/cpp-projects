// Carla de Beer
// October 2013
// Singly linked linked List

#include "linkedList.h"
#include <iostream>
#include <fstream>
#include <string>


using namespace std;

int main() 
{
	/*
	// ----------------- Test 
	
	LinkedList<int> list1;
	list1.insertFirst(0);
	list1.insertFirst(100);
	list1.insertFirst(-50);
	list1.insertLast(25);
	list1.deleteItem(100);
	cout << "list1 contents: " << list1 << endl;
	
	LinkedList<int> list2;
	list2.insertFirst(55);
	list2.insertFirst(128);
	cout << "list2 contents: " << list2 << endl;
	
	LinkedList<int> combinedList	= list1 + list2;
	//cout << "combinedList contents: " << combinedList << endl;
	cout << "Combined list has " << combinedList.getElementCount() << " elements." << endl;
	cout << "Combined list: " << combinedList << endl;
	
	LinkedList<int> list3;
	list3 = list1 = list2;
	cout << "list3 = " << list3 << endl;
	*/
  
  	LinkedList<std::string> list1;
	list1.insertFirst("linked");
	list1.insertFirst("love");
	list1.insertFirst("I");
	list1.insertLast("lists");
	list1.deleteItem("structures");
	cout << "list1 contents: " << list1 << endl;
	
	LinkedList<string> list2;
	list2.insertFirst("really");
	list2.insertFirst("yes");
	list2.insertFirst(",");
	cout << "list2 contents: " << list2 << endl;
	
	LinkedList<string> combinedList	= list1 + list2;
	cout << "Combined list has " << combinedList.getElementCount() << " elements." << endl;
	cout << "Combined list: " << combinedList << endl;
	
	// ----------------- Create an add an even and odd list
	
	LinkedList<int> evenList; 
	for(int i=0; i<20; i+=2)
	  evenList.insertLast(i);
	
	LinkedList<int> oddList; 
	for(int i=1; i<20; i+=2)
	  oddList.insertLast(i);
	
	cout << "oddList has " << oddList.getElementCount() << " elements." << endl;
	cout << "evenList has " << evenList.getElementCount() << " elements." << endl;
	
	LinkedList<LinkedList<int> > listOfLists;
	listOfLists.insertLast(evenList);
	listOfLists.insertLast(oddList);
	cout << listOfLists << endl;
	cout << "ListOfLists has " << listOfLists.getElementCount() << " elements." << endl;
	
	
	// ----------------- count number of words in a text
	 
	LinkedList<string> storyList;
	ifstream inData;
	string tempStr;
	inData.open("slyfox.txt");
	while (inData >> tempStr) 
	{
	  storyList.insertLast(tempStr);
	}
	inData.close(); 
	cout << storyList.getElementCount() << endl;
	cout << "number of times function 'getElementCount()' is called: " << storyList.getCount() << endl;
	
	return 0;
}
