//*****************************************************************
// FILE:      CreditAccount.cpp
// AUTHOR:    Damler, Lucas
// LOGON ID:  z1761739
// DUE DATE:  16 FEB 2017
// PURPOSE:   Implementation file for CreditAccount class
//*****************************************************************/

#include <iostream>
#include <iomanip>
#include <string.h>
#include "CreditAccount.h"

using namespace std;

/********************************************************************
Function: CreditAccount
Use: creates empty CreditAccount object
Parameters: none
Returns: nothing
********************************************************************/
CreditAccount::CreditAccount(){
	strcpy(accountNum, "");
	strcpy(customerName, "");
	creditLimit = 0;
	accountBalance = 0;
}

/********************************************************************
Function: CreditAccount (alternate)
Use: copies passed in values into the empty CreditAccount object
Parameters: aNum: char array with new account number
	    cName: char array with customers name
	    crdLim: contains accounts credit limit
	    aBal: contains accounts current balance
Returns: nothing
********************************************************************/
CreditAccount::CreditAccount(char *aNum, char *cName, double crdLim, double aBal){
	strcpy(accountNum, aNum);
	strcpy(customerName, cName);
	creditLimit = crdLim;
	accountBalance = aBal;
}

/********************************************************************
Function: getAccountNumber
Use: used to access private data member account number
Parameters: none
Returns: account number as char accountNum
********************************************************************/
char *CreditAccount::getAccountNumber(){
	return accountNum;
}

/********************************************************************
Function: getName
Use: used to access private data member of customers name
Parameters: none
Returns: customer name as char customerName
********************************************************************/
char *CreditAccount::getName(){
	return customerName;
}

/********************************************************************
Function: getLimit
Use: used to access private data member of account credit limit
Parameters: none
Returns: account credit limit as double creditLimit
********************************************************************/
double CreditAccount::getLimit(){
	return creditLimit;
}

/********************************************************************
Function: getBalance
Use: used to access private data member of account current balance
Parameters: none
Returns: account balance as double accountBalance
********************************************************************/
double CreditAccount::getBalance(){
	return accountBalance;
}

/********************************************************************
Function: processPayment
Use: used to modify current account balance
Parameters: payment: a double as amount to be subtracted from current account balance
Returns: nothing
********************************************************************/
void CreditAccount::processPayment(double payment){
	accountBalance = accountBalance - payment;
}

/********************************************************************
Function: processCharge
Use: used to modify current balance
Parameters: chargeAmount: a double as the amount to be added to current balance
Returns: true: if charge is processed
	 false: if charge is denied
********************************************************************/
bool CreditAccount::processCharge(double chargeAmount){
	if(chargeAmount + accountBalance > creditLimit){
		return false;
	}
	else{
		accountBalance = accountBalance + chargeAmount;
		return true;
	}
}

/********************************************************************
Function: print
Use: used to display account information
Parameters: none
Returns: nothing
********************************************************************/
void CreditAccount::print(){
	cout << fixed << setprecision(2);
	cout << "Account Number: " << accountNum <<  endl;
	cout << "Name: " << customerName << endl;
	cout << "Credit Limit: $" << creditLimit << endl;
	if(accountBalance < 0){
		cout << "Current Balance: $" << accountBalance*-1 << " CR\n";
	}
	else{
		cout << "Current Balance: $" << accountBalance << endl;
	}
	cout << endl;
}




