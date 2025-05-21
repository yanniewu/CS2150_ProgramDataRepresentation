//Yannie Wu
//ylw4sj
//September 5, 2021
//ListItr.cpp

#include <iostream>
#include <string>
#include "List.h"
#include "ListNode.h"
#include "ListItr.h"
using namespace std;

ListItr::ListItr(){
	ListNode* n = new ListNode();
	current = n;
}

ListItr::ListItr(ListNode* theNode){
	current = theNode;

}

bool ListItr::isPastEnd() const{
	if(current->next == NULL){
		return true;
	}
	else{
		return false;
	}
}

bool ListItr::isPastBeginning() const{
	if(current->previous == NULL){
		return true;
	}
	else{
		return false;
	}
}

void ListItr::moveForward(){
	if(!isPastEnd()){
		current = current->next;
	}
	else{
		return;
	}

}

void ListItr::moveBackward(){
	if(!isPastBeginning()){
		current = current->previous;
	}
	else{
		return;
	}

}

int ListItr::retrieve() const{
	return current->value;
}