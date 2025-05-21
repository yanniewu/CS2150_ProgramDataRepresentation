//Yannie Wu
//ylw4sj
//Stack.cpp

#include <iostream>
#include <string>
#include <cstdlib>
#include "postfixCalculator.h"
#include "ListNode.h"
#include "ListItr.h"
#include "List.h"
#include "Stack.h"

using namespace std;

Stack::Stack(){

}

Stack::~Stack(){

}


//adds element to top of stack
void Stack::push(int e){
	calc.insertAtTail(e);
}

//returns element on top of stack
int Stack::top(){
 	if(!empty()){
 		return calc.last().retrieve();
 	}
 	else{
 		exit(-1);
 	}
}

//removes element on top of stack
void Stack::pop(){
	if(!empty()){
		calc.removeAtTail();
	}
	else{
		exit(-1);
	}
}

//checks if stack is empty
bool Stack::empty(){
	return calc.isEmpty();
}