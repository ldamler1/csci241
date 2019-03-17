#ifndef ACCOUNT_DB_H
#define ACCOUNT_DB_H

//*****************************************************************
// FILE:      AccountDB.h
// AUTHOR:    Damler, Lucas
// LOGON ID:  z1761739
// DUE DATE:  16 FEB 2017
// PURPOSE:   Contains the declaration for the AccountDB class
//*****************************************************************/

#include "CreditAccount.h"
#include <string>

class AccountDB{
	private:
		CreditAccount accounts[20];
		int acNum;
	public:
		AccountDB();
		AccountDB(std::string);
		void print();
		void sortAccounts();
		int searchForAccount(char*);
		void processTransactions(std::string);
};

#endif
