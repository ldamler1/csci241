/*********************************************************************
   PROGRAM:    CSCI 241 Assignment 2
   PROGRAMMER: Damler, Lucas
   LOGON ID:   z1761739
   DUE DATE:   16 FEB 2017
   PURPOSE:    Main routine logic for assignment 2
*********************************************************************/


#include <iostream>
#include "AccountDB.h"

int main(){
	AccountDB account("accounts");
	account.print();
	account.processTransactions("transactions.txt");
	account.print();
}
