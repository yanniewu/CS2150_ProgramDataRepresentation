//Yannie Wu
//ylw4sj
//Stack.h

#ifndef STACK_H
#define STACK_H

#include <iostream>
#include "postfixCalculator.h"
#include "ListNode.h"
#include "ListItr.h"
#include "List.h"

using namespace std;

class Stack{
public:
	Stack();
	~Stack();
	void push(int e);
	int top();
	void pop();
	bool empty();
private:
	List calc;
	
};

#endif
