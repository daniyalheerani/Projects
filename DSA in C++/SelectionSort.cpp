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

void selectionSort(int *array, int size)
{
	for(int i = 0; i < size-1; i++)
	{
		int minIndex = i; //index of the minimum value
		for(int j = i+1; j < size; j++)
		{
			if(array[j] < array[minIndex])
			{
				minIndex = j;
			}
		}
		int temp = array[i];
		array[i] = array[minIndex];
		array[minIndex] = temp;
	}
}


int main()
{
	int array[6] = {42, 3, 100, 56, -1, 0};
	cout << "Before Sorting:\n";
	printArray(array, 6);
	cout << "After using selection sort in ascending order:\n";
	selectionSort(array, 6);
	printArray(array, 6);
}
