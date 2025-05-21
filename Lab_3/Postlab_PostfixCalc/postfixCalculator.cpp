//Yannie Wu
//ylw4sj
//postfixCalculator.cpp

#include <iostream>
#include <string>
#include "postfixCalculator.h"
#include "ListNode.h"
#include "ListItr.h"
#include "List.h"
#include "Stack.h"

using namespace std;

postfixCalculator::postfixCalculator(){
}


//addition
void postfixCalculator::add(){
	int first = calc.top();
	calc.pop();
	int second = calc.top();
	calc.pop();
	calc.push(first + second);
}

//subtraction
void postfixCalculator::sub(){
	int first = calc.top();
	calc.pop();
	int second = calc.top();
	calc.pop();
	calc.push(second - first);
}

//multiplication
void postfixCalculator::mult(){
	int first = calc.top();
	calc.pop();
	int second = calc.top();
	calc.pop();
	calc.push(first * second);
}

//division
void postfixCalculator::div(){
	int first = calc.top();
	calc.pop();
	int second = calc.top();
	calc.pop();
	calc.push(second / first);
}

//negation
void postfixCalculator::neg(){
	int first = calc.top();
	calc.pop();
	calc.push(first * -1);	

}
	


