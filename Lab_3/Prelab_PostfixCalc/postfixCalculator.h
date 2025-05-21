//Yannie Wu
//ylw4sj
//postfixCalculator.h

#ifndef POSTFIXCALCULATOR_H
#define POSTFIXCALCULATOR_H
#include <iostream>
#include <stack>
#include <cstdlib>
using namespace std;

class postfixCalculator{
public:
	postfixCalculator();
	
	void push(int e);
	int top();
	void pop();
	bool empty();

	void add();
	void sub();
	void mult();
	void div();
	void neg();

	stack<int> calculator;
};

#endif