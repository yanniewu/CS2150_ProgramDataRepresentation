//Yannie Wu
//ylw4sj
//threexinput.cpp

#include <iostream>
#include "timer.h"

using namespace std;

extern "C" long threexplusone (long);

/* Recursive C++ function
int threexplusone(int num){
	if(num == 1){
		return 0;
	}
	if(num%2 == 0){
		num = n / 2;
		return 1 + threexplusone(num);
	}
	if(num%2 == 1){
		num = 3 * num + 1;
		return 1 + threexplusone(num);
	}
} */

int main(){
	long x = 0;
	long n = 0;

	cout << "Enter a number: ";
	cin >> x;

	cout << "Enter iterations of subroutine: ";
	cin >> n;

	cout << "Steps: " << threexplusone(x) << endl;

	//Timer code
	timer t;
	t.start();
	for(int i=0; i<n; i++){
		threexplusone(x);
	}
	t.stop();
	float avg = t.getTime()/n;

	//cout << "Average time: " << avg << endl;

	return 0;

}

