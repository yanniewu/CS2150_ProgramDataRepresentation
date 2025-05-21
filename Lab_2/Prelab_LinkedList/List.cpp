//Yannie Wu
//ylw4sj
//September 5, 2021
//List.cpp

#include <iostream>
#include <string>
#include "List.h"
#include "ListNode.h"
#include "ListItr.h"
using namespace std;

List::List(){
	head = new ListNode();
	tail = new ListNode();
	head->next = tail;
	tail->previous = head;
	count = 0;

}

// Copy constructor
// Called when the code looks something like List list2 = list1;
// (In other words, it is called when you are trying to construct a **new** list from an existing one)
List::List(const List& source){
	head = new ListNode();
    tail = new ListNode();
    head->next = tail;
    tail->previous = head;
    count = 0;

    // Make a deep copy of the list
    ListItr iter(source.head->next);
    while (!iter.isPastEnd()) {
        insertAtTail(iter.retrieve());
        iter.moveForward();
    }
}

List::~List(){
	makeEmpty();
	delete tail;
	tail = NULL;
	delete head;
	head = NULL;

}


// Copy assignment operator
// Called when the code looks something like list2 = list1;
// (In other words, it is called when you are trying to set an **existing** list equal to another one)
List& List::operator=(const List& source) {
    if (this == &source) {
        // The two are the same list; no need to do anything
        return *this;
    } else {
        // Clear out anything this list contained
        // before copying over the items from the other list
        makeEmpty();

        // Make a deep copy of the list
        ListItr iter(source.head->next);
        while (!iter.isPastEnd()) {
            insertAtTail(iter.retrieve());
            iter.moveForward();
        }
    }
    return *this;
}


bool List::isEmpty() const{
	if(count == 0){
		return true;
	}
	else{
		return false;
	}

}

void List::makeEmpty(){
	ListNode * n = new ListNode();
	ListItr position = first();
	while(!position.isPastEnd()){
		n = position.current;
		position.moveForward();
		delete n;
	}

	count = 0;
	head->next = tail;
	tail->previous = head;
}

ListItr List::first(){
	ListItr itr = head->next;
	return itr;
}

ListItr List::last(){
	return ListItr(tail->previous);
}

void List::insertAfter(int x, ListItr position){
	ListNode* n = new ListNode();
	n->value = x;
	position.current->next = n;
	n->previous = position.current;
	count++;
}

void List::insertBefore(int x, ListItr position){
	ListNode* n = new ListNode();
	n->value = x;
	position.current->previous = n;
	n->next = position.current;
	count++;
}

void List::insertAtTail(int x){
	ListNode* n = new ListNode();
	n->value = x;
	n->next = tail;
	n->previous = tail->previous;
	tail->previous->next = n;
	tail->previous = n;
	count++;

}

ListItr List::find(int x){
	ListItr itr(head->next);
	while(!itr.isPastEnd() && itr.retrieve()!= x){
		itr.moveForward();
	}

	if(itr.current == NULL){
		itr.current = tail;
	}
	return itr;
}

void List::remove(int x){
	

}

int List::size() const{
	return count;
}

void printList(List& source, bool forward){
	if(forward){
		ListItr itr = source.first();
		while (!itr.isPastEnd()){
			cout << itr.retrieve() << " ";
			itr.moveForward();
		}
	}
	if(!forward){
		ListItr itr = source.last();
		while (!itr.isPastBeginning()){
			cout << itr.retrieve() << " ";
			itr.moveBackward();
		}
	}


	
}

