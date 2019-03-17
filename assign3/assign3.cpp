/***************************************************************
SCI 241         Program 3     Spring 2017
Programmer: Damler, Lucas
Section:    2
Date Due:   28 FEB 2017
Purpose: Tracks amount of food eaten by three monkeys
***************************************************************/

#include <iostream>
#include <iomanip>
#include "Monkey.h"

using std::cout;
using std::endl;
using std::left;

int main()
   {
   Monkey m;
   int i;       //subscript

   // Print the names of all the monkeys
   cout << "The names of all the monkeys:\n\n";
   for (i = 0;i < NUMMONKEYS; i++)
      cout << m.getName(i) << endl;
   cout << endl << endl;

   // Call printArray 
   cout << "Weekly consumption for all monkeys\n\n";
   m.printArray();	

   // Print Total Food Eaten
   cout << "\n\nTotal Food Eaten This Week: " << m.totalFoodEaten() << " pounds\n"; 

   // Print Average consumption per family
   cout << "\n\nAverage Daily Consumption for All Monkeys: " << m.avgDailyConsumption() << " pounds" << endl;

   // Print weekly amount per monkey
   cout << "\n\nAverage Daily Consumption per Monkey\n";
   m.printDailyConsumptionPerMonkey();

   // Find the monkey who ate the most
   m.mostEaten();	

   return 0;
   }
