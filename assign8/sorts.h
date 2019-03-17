#ifndef SORTS_H
#define SORTS_H

#include <iostream>
#include <fstream>

using namespace std;

//Prototypes for method definitions
template <class T> void buildList(vector<T>&, const char*);
template <class T> void printList(const vector<T>&, int, int);
template <class T> bool lessThan(const T&, const T&);
template <class T> bool greaterThan(const T&, const T&);

/***************************************************************
Function: buildList
Use: reads from input file and places them in a vector
Parameters: set: reference to vector list
	    fileName: pointer to char of file name
Returns: nothing
***************************************************************/
template <class T>
void buildList(vector<T>& set, const char* fileName)
	{
	T item;
	ifstream inFile;

	inFile.open(fileName);
	if(inFile.fail())
		{
		cout << "ERROR opening file on buildList()\n";
		exit(1);
		}

	inFile >> item;
	while(inFile)
		{
		set.push_back(item);
		inFile >> item;
		}
	inFile.close();
	}

/***************************************************************
Function: printList
Use: prints list of vector items
Parameters: set: reference to vector list
	    itemWidth: int of width when printed
	    numPerLine: int of maximum items per output line
Returns: nothing
***************************************************************/
template <class T>
void printList(const vector<T>& set, int itemWidth, int numPerLine)
	{
   	int i = 0;
   	while (i < (int) set.size())
      		{
      		cout << setw(itemWidth) << set[i] << ' ';
      		i++;
      		if (i % numPerLine == 0)
         		cout << endl;
      		}

   	if (i % numPerLine != 0)
      		cout << endl;
   	}

/***************************************************************
Function: lessThan
Use: compares passed in items relationship
Parameters: item1: const template data type
	    item2: const template data type
Returns: true or false
***************************************************************/
template <class T>
bool lessThan(const T& item1, const T& item2)
	{
	if(item1 < item2)
		return true;
	else
		return false;
	}

/***************************************************************
Function: greaterThan
Use: compares passed in items relationship
Parameters: item1: const template data type
            item2: const template data type
Returns: true or false
***************************************************************/
template <class T>
bool greaterThan(const T& item1, const T& item2)
	{
	if(item1 > item2)
		return true;
	else
		return false;
	}

#endif
