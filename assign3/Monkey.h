#ifndef MONKEY_H
#define MONKEY_H

//*****************************************************************
// FILE:      Monkey.h
// AUTHOR:    Damler, Lucas
// LOGON ID:  z1761739
// DUE DATE:  28 FEB 2017
// PURPOSE:   Contains declaration for the Monkey class
//*****************************************************************/

#include <string>

using namespace std;

static const int NUMMONKEYS = 3;
static const int NUMDAYS = 7;

class Monkey{
        private:
		string monkeyNames[NUMMONKEYS] = {"Curious George", "Mojo", "Marcel"};
		float foodPounds[NUMMONKEYS][NUMDAYS];
        public:
		Monkey();
		string getName(int);
		void printArray();
		float totalFoodEaten();
		float avgDailyConsumption();
		float avgDailyPerMonkey(int);
		void printDailyConsumptionPerMonkey();
		void mostEaten();
};

#endif
