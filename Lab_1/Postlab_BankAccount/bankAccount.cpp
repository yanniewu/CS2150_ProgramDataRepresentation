//Yannie Wu
//ylw4sj
//August 31, 2021
//bankAccount.cpp

#include <iostream>
#include <string>
#include "bankAccount.h"

bankAccount::bankAccount() {
	balance = 0.00;
}

bankAccount::bankAccount(double amount){
	balance = amount;
}

bankAccount::~bankAccount(){

}

double bankAccount::withdraw(double amount){
	if(amount < balance){
		balance -= amount;
		return balance;
	}
	else
		return balance;
}

double bankAccount::deposit(double amount){
	balance += amount;
	return balance;
}

double bankAccount::getBalance(){
	return balance;
}

