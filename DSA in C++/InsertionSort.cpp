#include <iostream>
using namespace std;

void printArray(int *array, int size)
{
	cout << "[";
	for(int i = 0; i < size; i++)
	{
		cout << array[i] << ", ";
	}
	cout << "\b\b]\n";
}


void ascendingInsertionSort(int* array, int size)
{
	for(int i = 1; i < size; i++)
	{
		int j = i;
		while(j > 0 && array[j] < array[j-1])
		{
			int temp = array[j];
			array[j] = array[j-1];
			array[j-1] = temp;
			j--;
		}
	}
}


int main()
{
	int array[8] = {14, 33, 27, 10, 35, 19, 42, 44};
	cout << "Unsorted Array:" << endl;
	printArray(array, 8);
	cout << "Ascending Array:" << endl;
	ascendingInsertionSort(array, 8);
	printArray(array, 8);
	
}
