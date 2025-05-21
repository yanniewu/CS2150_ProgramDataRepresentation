//Yannie Wu
//ylw4sj
//testPostfixCalc.h

#include <iostream>
#include <string>
#include <cstdlib>
#include "postfixCalculator.h"
#include "ListNode.h"
#include "ListItr.h"
#include "List.h"
#include "Stack.h"
using namespace std;

int main(){
	string token;
	postfixCalculator calc2;

	while(cin >> token){
		if(token == "+"){
			calc2.add();
		}
		else if(token == "-"){
			calc2.sub();
		}
		else if(token == "*"){
			calc2.mult();
		}
		else if(token == "/"){
			calc2.div();
		}
		else if(token == "~"){
			calc2.neg();
		}
		else{
			calc2.calc.push(stoi(token));
		}

	}
	cout <<calc2.calc.top() << endl;
}