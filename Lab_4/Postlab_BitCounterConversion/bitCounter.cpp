//Yannie Wu
//ylw4sj
//bitCounter.coo


#include <iostream>
#include <string> 
#include <stdio.h>
#include <cmath>
#include <algorithm>

using namespace std;

int binaryBitCounter(int n);
string baseConverter(string str, int startBase, int endBase);

int main(int argc, char **argv){
	
	int n =  stoi(argv[1]);
	string str = argv[2];
	int startBase = stoi(argv[3]);
	int endBase = stoi(argv[4]);
	
	cout << n << " has " << binaryBitCounter(n) << " bit(s)" << endl;  
	cout << str << " (base " << startBase << ") = " << baseConverter(str, startBase, endBase) << " (base " << endBase << ")" << endl; 
	
	return 0;

}


//prints out number of 1s in the binary representation of n
int binaryBitCounter(int n){
	if(n == 1){
		return 1;
	}
	if(n == 0){
		return 0;
	}
	else{
		return binaryBitCounter(n%2) + binaryBitCounter(n/2);
	}
}


//Converts from one base to another
string baseConverter(string str, int startBase, int endBase){

	//Converts string to ascii value, then to base 10
	int base10 = 0;
	
	for (int i=0; i<str.length(); i++){
		if(isdigit(str[i])){
			int ascii = str[i] - '0';
			base10 += (ascii * pow(startBase, str.length()-i-1));
		}
		else{
			int ascii = (str[i] - '0' - 7);
			base10 += (ascii * pow(startBase, str.length()-i-1));
		}
	}

	//Returns already converted number
	if(endBase == 10){
		return to_string(base10);
	}

	//Converts base10 to endBase
	else{
		string converted = "";
		char x = 'a';
	
		//Creates endBase string
		while(base10 != 0){

			//Converts from number to char
			if(base10 % endBase < 10){
				x = (base10 % endBase) + '0';
			}

			
			else{
				x = (base10 % endBase) + '0' + 7;
			}

			converted += x; 
			base10 = base10/endBase;				
		}

		//Reverses endBase string
		reverse(converted.begin(), converted.end());
		return converted;

	}

}
