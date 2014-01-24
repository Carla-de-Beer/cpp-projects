#ifndef LINKEDLIST_H
#define LINKEDLIST_H
#include <iostream>
using namespace std;

template <class T>
class LinkedList 
{
	private:		
		struct Node 
		{
			T info;
			Node *link;
			Node(T _info, Node* _link = NULL): info(_info), link(_link) {}
		};
		Node *head;
		void copyList(const LinkedList&);
		void deallocateList();
		int getElementCount(Node * ptr) const;
		static int count;

	public:
		LinkedList(): head(NULL){};
		~LinkedList();				
		LinkedList(const LinkedList&);
		LinkedList& operator=(const LinkedList&);
		int getElementCount() const;		
		void insertFirst(T);
		void insertLast(T);
		void deleteItem(T);		
		LinkedList operator+(const LinkedList& other) const;
		int getCount() const;

		friend ostream& operator<<(ostream& out, const LinkedList& obj) 
		{
		    Node *current = obj.head;	
		    while (current != NULL) 
		    {
		      out << current->info << " ";
		      current = current->link;
		      //cout << "calling friend" << endl;
		    }	
		return out;
	}		
};

#include "linkedList.cpp"
#endif
