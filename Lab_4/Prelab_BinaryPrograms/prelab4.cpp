//Yannie Wu
//ylw4sj
//prelab4.cpp


#include <iostream>
#include <string> 
#include <stdio.h>

using namespace std;

void sizeOfTest();
void overflow();
void outputBinary(unsigned int n);

int main(){
	unsigned int x;
	cin >> x;
	sizeOfTest();
	overflow();
	outputBinary(x);
	return 0;
}


void sizeOfTest(){
	cout << "Size of int: " << sizeof(int) << endl;
	cout << "Size of unsigned int: " << sizeof(unsigned int) << endl;
	cout << "Size of float: " << sizeof (float) << endl;
	cout << "Size of double: " << sizeof(double) << endl;
	cout << "Size of char: " << sizeof(char) << endl;
	cout << "Size of bool: " << sizeof(true) << endl;
	cout << "Size of int*: " << sizeof(int*) << endl;
	cout << "Size of char*: " << sizeof(char*) << endl;
	cout << "Size of double*: " << sizeof(double*) << endl;

}

void overflow(){
	unsigned int max = 4294967295;
	cout << max << " + 1 = " << max + 1 << endl;


}

void outputBinary(unsigned int n){
	int binary[32] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
	int i = 0;
	double n2 = (double)n;

	/*if(n == 4294967295){
		for(i=0; n<32; i++){    
		binary[i] = 1;
		}
	}*/

	for(i=0; n>0; i++){    
		binary[i] = n%2;    
		n = n/2;  
	}

	
	for(i=31 ;i>=0 ;i-=4){    
		cout << binary[i] << binary [i-1] << binary[i-2] << binary [i-3] << " ";    
	}       
	cout << endl;

}