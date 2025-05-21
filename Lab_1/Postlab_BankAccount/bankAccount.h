//Yannie Wu
//ylw4sj
//August 31, 2021
//bankAccount.h

#ifndef BANKACCOUNT_H
#define BANKACCOUNT_H
using namespace std;

class bankAccount {
public:
	bankAccount();
	bankAccount(double amount);
	~bankAccount();
	double withdraw(double amount);
	double deposit(double amount);
	double getBalance();

private:
	double balance;

};

#endif