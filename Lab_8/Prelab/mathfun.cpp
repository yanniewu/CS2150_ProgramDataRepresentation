//Yannie Wu
//ylw4sh
//mathfun.cpp

#include <iostream>

using namespace std;

extern "C" long product (long, long);
extern "C" long power (long, long);

/*int power(int x, int n)
{
    if (n == 0)
    	int rax = 1;
    	return rax;

    rax = x * power(x, n-1);
    return rax;
}*/

int main(){
	
	//Initialize variabels
	long x = 0;
	long y = 0;

	cout << "Enter integer 1: ";
	cin >> x;

	cout << "Enter integer 2: ";
	cin >> y;

	//Calculate product and power
	long prod = product(x, y);
	long pow = power(x, y);

	//Print out results
	cout << "Product: " << prod << endl;
	cout << "Power: " << pow << endl;

	return 0;



}




