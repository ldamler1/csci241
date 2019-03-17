#ifndef CREDIT_ACCOUNT_H
#define CREDIT_ACCOUNT_H

//*****************************************************************
// FILE:      CreditAccount.h
// AUTHOR:    Damler, Lucas
// LOGON ID:  z1761739
// DUE DATE:  16 FEB 2017
// PURPOSE:   Contains the declaration for the CreditAccount class.
//*****************************************************************/

using namespace std;

class CreditAccount{
	private:
		char accountNum[20];
		char customerName[21];
		double creditLimit;
		double accountBalance;
	public:
		CreditAccount();
		CreditAccount(char*, char*, double, double);
		char *getAccountNumber();
		char *getName();
		double getLimit();
		double getBalance();
		void processPayment(double);
		bool processCharge(double);
		void print();
};


#endif
