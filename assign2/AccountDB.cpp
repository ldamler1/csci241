//*****************************************************************
// FILE:      AccountDB.cpp
// AUTHOR:    Damler, Lucas
// LOGON ID:  z1761739
// DUE DATE:  16 FEB 2017
// PURPOSE:   Implementation for AccountDB header file
//*****************************************************************/

#include "AccountDB.h"
#include <fstream>
#include <iostream>
#include <iomanip>
#include <string.h>

using namespace std;

/********************************************************************
Function: AccountDB
Use: initalize empty AccountDB database
Parameters: none
Returns: nothing
********************************************************************/
AccountDB::AccountDB(){
	acNum = 0;
}

/********************************************************************
Function: AccountDB (alternate)
Use: reads passed in file and  then sorts accounts
Parameters: fileName: string containing name of passed in file
Returns: nothing
********************************************************************/
AccountDB::AccountDB(std::string fileName){
	ifstream inFile;
	inFile.open(fileName, ios::binary);
	if(inFile.fail()){
		cout << "Error Opening File\n";
	}
	inFile.read((char*) this, sizeof(AccountDB));
	inFile.close();
	sortAccounts();
}

/********************************************************************
Function: print
Use: prints elements contained in created CreditAccount object
Parameters: none
Returns: nothing
********************************************************************/
void  AccountDB::print(){
	cout << "Credit Card Accounts" << endl << endl;
	for(int i = 0; i < acNum; i++){
		accounts[i].print();
	}
	cout << endl << endl;
}

/********************************************************************
Function: sortAccounts
Use: sorts elements in CreditAccount object in ascending order using insertion sort
Parameters: none
Returns: nothing
********************************************************************/
void AccountDB::sortAccounts(){
	int i, j;
	CreditAccount bucket;
	for(i = 1; i < acNum; i++){
		bucket = accounts[i];
		for(j = i; ((j > 0)&&(strcmp(accounts[j-1].getAccountNumber(), bucket.getAccountNumber())) > 0); j--){
			accounts[j] = accounts[j-1];
		}
		accounts[j] = bucket;
	}
}

/********************************************************************
Function: searchForAccount
Use: searches CreditAccount object with passed in value for identical value
Parameters: searchAccount: char array containing account number to search for
Returns: mid: if compared values are equal
	 -1: if compared values are different
*******************************************************************/
int AccountDB::searchForAccount(char* searchAccount){
	int low = 0;
	int high = acNum - 1;
	int mid;
	while(low <=  high){
		mid = (low + high)/2;
		if(strcmp(searchAccount, accounts[mid].getAccountNumber()) == 0)
			return mid;
		if(strcmp(searchAccount, accounts[mid].getAccountNumber()) < 0)
			high = mid - 1;
		else{low = mid +1;}
	}
	return -1;
}

/********************************************************************
Function: processTransaction
Use: reads transaction list and processes charges and payments and displays modified values
Parameters: fileName: c++ string containing name of passed in file name
Returns: nothing
********************************************************************/
void AccountDB::processTransactions(std::string fileName){
	ifstream inFile;
	char date[6];
	char accountNum[20];
	char transType;
	double amount;

	double trans;

	inFile.open(fileName);
	if(inFile.fail()){
		cout << "ERROR: Failure to open file";
	}

	cout << fixed  << setprecision(2);

	inFile >> date;
	cout << setw(52) << "Transaction List\n\n";
	cout << left << setw(14) << "Date" << left <<  setw(24) << "Account" << left << setw(10) << "Type" << left << setw(14) << "Amount" << left << setw(14) << "New Balance" << endl << endl;
	while(inFile){
		inFile >> accountNum;
		inFile >> transType;
		inFile >> amount;

		int index = searchForAccount(accountNum);
		if(index == -1){
			cout << left << setw(14) << date << left << setw(24) << accountNum << left << setw(10) << transType << left << setw(14) << amount << left << setw(14) << "ERROR Invalid Account Number\n";
		}
		else{
			if(transType == 'C' || transType == 'c'){
				trans = accounts[index].processCharge(amount);
				if(trans == 0)
					cout << left << setw(14) << date << left << setw(24) << accountNum << left << setw(10) << transType << left << setw(14) << amount << left << setw(14) << "ERROR Credit Limit Exceeded\n";
				else
					cout << left << setw(14) << date << left << setw(24) << accountNum << left << setw(10) << transType << left << setw(14) << amount << left << setw(14) << (accounts[index].getBalance())* trans << endl;
			}
			else{
				accounts[index].processPayment(amount);
				if(accounts[index].getBalance() < 0)
					cout << left << setw(14) << date << left << setw(24) << accountNum << left << setw(10) << transType << left << setw(14) << amount << (accounts[index].getBalance())*-1 << " CR\n";
				else
					cout << left << setw(14) << date << left << setw(24) << accountNum << left << setw(10) << transType << left << setw(14) << amount << left << setw(14) << (accounts[index].getBalance()) << endl;
			}
		}
	inFile >> date;
	}
	inFile.close();
	cout << endl;
}
