#ifndef MERGESORT_H
#define MERGESORT_H

//Prototypes for defeinitions
template <class T> void mergeSort(vector<T>&, bool (*compare)(const T&, const T&));
template <class T> void mergeSort(vector<T>&, int, int, bool (*compare)(const T&, const T&));
template <class T> void merge(vector<T>&, int, int, int, bool (*compare)(const T&, const T&));


/***************************************************************
Function: mergeSort
Use: calls recursive mergeSort method
Parameters: set: reference to a vector object
	    compare: bool pointer to compare refernces to 2 data type T
Returns: nothing
***************************************************************/
template <class T>
void mergeSort(vector<T>& set, bool (*compare)(const T&, const T&))
	{
	mergeSort(set, 0, set.size()-1, compare);
	}

/***************************************************************
Function: mergeSort
Use: divides a vector into two subvectors and sorts
Parameters: set: reference to a vector object
	    low: int to lowest subscript
	    high: int to highest subscript
	    compare: bool pointer to compare to 2 data type T
Returns: nothing
***************************************************************/
template <class T>
void mergeSort(vector<T>& set, int low, int high, bool (*compare)(const T&, const T&))
	{
	int mid;
   
   	if (low < high)
      		{
      		mid = (low + high) / 2;
  
      		mergeSort(set, low, mid, compare);
      		mergeSort(set, mid+1, high, compare);
      		merge(set, low, mid, high, compare);
      		}
	}

/***************************************************************
Function: merge
Use: merges two sorted subvectors
Parameters: set: reference to a vector object
            low: int to lowest subscript
            high: int to highest subscript
            compare: bool pointer to compare to 2 data type T
Returns: nothing
***************************************************************/
template <class T>
void merge(vector<T>& set, int low, int mid, int high, bool (*compare)(const T&, const T&))
	{
	vector<T> temp(high-low+1);

	int i = low;
	int j = mid+1;
	int k = 0;

	while(i <= mid && j <= high)
		{
		if(compare(set[j], set[i]))
			{
			temp[k] = set[j];
			j++;
			k++;
			}
		else
			{
			temp[k] = set[i];
			i++;
			k++;
			}
		}

	while(i <= mid)
		{
		temp[k] = set[i];
		i++;
		k++;
		}

	while(j <= high)
		{
		temp[k] = set[j];
		j++;
		k++;
		}

	for(i = 0, j = low; j <= high; i++, j++)
		set[j] = temp[i];
	}

#endif
