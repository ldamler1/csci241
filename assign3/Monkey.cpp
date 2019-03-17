/*****************************************************************
// FILE:      Monkey.cpp
// AUTHOR:    Damler, Lucas
// LOGON ID:  z1761739
// DUE DATE:  28 FEB 2017
// PURPOSE:   Implementation file for Monkey class
*****************************************************************/

#include <iostream>
#include <iomanip>
#include <string.h>
#include <fstream>
#include "Monkey.h"

using namespace std;

/********************************************************************
Function: Monkey
Use: creates empty monkey object
Parameters: none
Returns: nothing
********************************************************************/

Monkey::Monkey(){
	ifstream inFile;

	float monkeyFood;

	inFile.open("monkeyfood.txt");
	if(inFile.fail())
                cout << "ERROR: Failure to open file";
	inFile >> monkeyFood;
	while(inFile){
		for(int r = 0; r < NUMMONKEYS; r++){
			for(int c = 0; c < NUMDAYS; c++){
				foodPounds[r][c] = monkeyFood;
				inFile >> monkeyFood;
			}
		}
	}
}

/********************************************************************
Function: getName
Use: used to access private data member of monkey names
Parameters: i: passed in subscript to determine which name should be returned from the monkeyName array
Returns: monkey name as a string
********************************************************************/

string Monkey::getName(int i){
	return monkeyNames[i];
}

/********************************************************************
Function: printArray
Use: desplay monkey name as well as pounds of food eaten by each monkey
Parameters: none
Returns: nothing
********************************************************************/

void Monkey::printArray(){
	cout << fixed << setprecision(2);
	for(int r = 0; r < NUMMONKEYS; r++){
		cout << left << setw(21) << getName(r);
		for(int c = 0; c < NUMDAYS; c++){
			cout << foodPounds[r][c] << " ";
		}
		cout << endl;
	}
}

/********************************************************************
Function: totalFoodEaten
Use: calculates the total food eaten by all monkeys
Parameters: none
Returns: a float of the total of all values in food array
********************************************************************/

float Monkey::totalFoodEaten(){
	float totalFoodPounds = 0;
	for(int r = 0; r < NUMMONKEYS; r++){
		for(int c = 0; c < NUMDAYS; c++){
			totalFoodPounds += foodPounds[r][c];
		}
	}
	return totalFoodPounds;
}

/********************************************************************
Function: avgDailyConsumption
Use: calcualtes daily average of food eaten of all monkeys
Parameters: none
Returns: a float containg the daily average food consumption
********************************************************************/

float Monkey::avgDailyConsumption(){
	float avg = totalFoodEaten()/(NUMMONKEYS*NUMDAYS);
	return avg;
}

/********************************************************************
Function: avgDailyPerMonkey
Use: calculates the daily food consumption for an individual monkey
Parameters: whichMonkey: an int containg the subscript for which monkey's average to be calculated
Returns: a float with an single monkeys daily food average
********************************************************************/

float Monkey::avgDailyPerMonkey(int whichMonkey){
	float avg, oneMonkeyTotal;

	for(int i = 0; i < NUMDAYS; i++){
		oneMonkeyTotal += foodPounds[whichMonkey][i];
	}
	avg = oneMonkeyTotal/NUMDAYS;
	return avg;	
}

/********************************************************************
Function: printDailyConsumptionPerMonkey
Use: prints out each individual monkey's daily food consumption average
Parameters: none
Returns: nothing
********************************************************************/

void Monkey::printDailyConsumptionPerMonkey(){
	cout << endl;
	for(int i = 0; i < NUMMONKEYS; i++){
		cout << left << setw(20) << getName(i)  << avgDailyPerMonkey(i) << endl;
	}
	cout << endl;
}

/********************************************************************
Function: mostEaten
Use: decides and displays the monkey who ate the most food on a single day
Parameters: none
Returns: nothing
********************************************************************/

void Monkey::mostEaten(){
	float max = 0;
	int row;
	cout << fixed << setprecision(2);
	for(int r = 0; r < NUMMONKEYS; r++){
		for(int c = 0; c < NUMDAYS; c++){
			if(foodPounds[r][c] > max){
				max = foodPounds[r][c];
				row = r;
			}
		}
	}
	cout << monkeyNames[row] << " ate the most food - " << max << " pounds\n";
}
