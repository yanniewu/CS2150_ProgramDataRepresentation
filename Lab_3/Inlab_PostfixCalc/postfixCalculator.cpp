//Yannie Wu
//ylw4sj
//postfixCalculator.cpp

#include <iostream>
#include <string>
#include <stack>
#include "postfixCalculator.h"


postfixCalculator::postfixCalculator(){

}

//adds element to top of stack
void postfixCalculator::push(int e){
	calculator.push(e);
}

//returns element on top of stack
int postfixCalculator::top(){
 	if(!calculator.empty()){
 		return calculator.top();
 	}
 	else{
 		exit(-1);
 	}
}

//removes element on top of stack
void postfixCalculator::pop(){
	if(!calculator.empty()){
		calculator.pop();
	}
	else{
		exit(-1);
	}
}

//checks if stack is empty
bool postfixCalculator::empty(){
	return calculator.empty();
}

//addition
void postfixCalculator::add(){
	int first = calculator.top();
	calculator.pop();
	int second = calculator.top();
	calculator.pop();
	calculator.push(first + second);
}

//subtraction
void postfixCalculator::sub(){
	int first = calculator.top();
	calculator.pop();
	int second = calculator.top();
	calculator.pop();
	calculator.push(second - first);
}

//multiplication
void postfixCalculator::mult(){
	int first = calculator.top();
	calculator.pop();
	int second = calculator.top();
	calculator.pop();
	calculator.push(first * second);
}

//division
void postfixCalculator::div(){
	int first = calculator.top();
	calculator.pop();
	int second = calculator.top();
	calculator.pop();
	calculator.push(second / first);
}

//negation
void postfixCalculator::neg(){
	int first = calculator.top();
	calculator.pop();
	calculator.push(first * -1);	

}
	


