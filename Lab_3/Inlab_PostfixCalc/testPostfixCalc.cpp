//Yannie Wu
//ylw4sj
//testPostfixCalc.h

#include <iostream>
#include <string>
#include <stdlib.h>
#include <cmath>
#include <iomanip>
#include "postfixCalculator.h"
using namespace std;

int main(){
	string token;
	postfixCalculator calc;

	while(cin >> token){
		if(token == "+"){
			calc.add();
		}
		else if(token == "-" && token.length() == 1){
			calc.sub();
		}
		else if(token == "*"){
			calc.mult();
		}
		else if(token == "/"){
			calc.div();
		}
		else if(token == "~"){
			calc.neg();
		}
		else{
			calc.push(stoi(token));
		}

	}
	cout <<calc.top() << endl;
}