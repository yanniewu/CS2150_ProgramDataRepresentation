//Yannie Wu
//ylw4sj
//postfixCalculator.h

#ifndef POSTFIXCALCULATOR_H
#define POSTFIXCALCULATOR_H

#include <iostream>
#include <cstdlib>
#include "Stack.h"

using namespace std;

class postfixCalculator{
public:
	postfixCalculator();
	void add();
	void sub();
	void mult();
	void div();
	void neg();

	Stack calc;

};

#endif