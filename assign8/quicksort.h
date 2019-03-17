#ifndef QUICKSORT_H
#define QUICKSORT_H

#include <iostream>

using namespace std;

//Prototypes for function definitions
template <class T> void quickSort(vector<T>&, bool (*compare)(const T&, const T&));
template <class T> void quickSort(vector<T>&, int, int, bool (*compare)(const T&, const T&));
template <class T> int partition(vector<T>&, int, int, bool (*compare)(const T&, const T&));

/***************************************************************
Function: quickSort
Use: calls recursive quickSort method
Parameters: set: reference to vector object
	    compare: pointer to a comparison function
Returns: nothing
***************************************************************/
template <class T>
void quickSort(vector<T>& set, bool (*compare)(const T&, const T&))
	{
	quickSort(set, 0, set.size()-1, compare);
	}

/***************************************************************
Function: quickSort
Use: Preforms recursive call to quick sort algorithm
Parameters: set: reference to vector object
	    start: int of beginning of vector list
	    end: int of end of vector list
	    compare: pointer to a comparison function
Returns: nothing
***************************************************************/
template <class T>
void quickSort(vector<T>& set, int start, int end, bool (*compare)(const T&, const T&))
	{
	int pivotPoint;

	if (start < end)
      		{
      		pivotPoint = partition(set, start, end, compare);     // Get the pivot point
      		quickSort(set, start, pivotPoint - 1, compare);       // Sort first sublist
      		quickSort(set, pivotPoint + 1, end, compare);         // Sort second sublist
      		}
	}

/***************************************************************
Function: partition
Use: selects pivot element and partitions vector around pivot
Parameters: set: reference to vector object
            start: int of beginning of vector list
            end: int of end of vector list
            compare: pointer to a comparison function
Returns: nothing
***************************************************************/
template <class T>
int partition(vector<T>& set, int start, int end, bool (*compare)(const T&, const T&))
	{
	int pivotIndex, mid;
   	T pivotValue;
   
   	mid = (start + end) / 2;

	swap(set[start], set[mid]);
 
  	pivotIndex = start;
  	pivotValue = set[start];
 
   	for (int scan = start + 1; scan <= end; scan++)
      		{
      		if (compare(set[scan], pivotValue))
         		{
         		pivotIndex++;
			swap(set[pivotIndex], set[scan]);
         		}
      		}

	swap(set[start], set[pivotIndex]);

	return pivotIndex; 
	}

#endif
