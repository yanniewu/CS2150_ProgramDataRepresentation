//Yannie Wu
//ylw4sj
//August 29, 2021
//xToN.cpp



#include <iostream>
using namespace std;


int xton(int base, int exponent){
	if(exponent == 0){
		return 1;
	}
	else
		return base * xton(base, exponent - 1);
}

int main(){
	int base, exponent, ans;
	cin >> base;
	cin >> exponent;
	ans = xton(base, exponent);
	cout << ans << endl;
	return 0;

}