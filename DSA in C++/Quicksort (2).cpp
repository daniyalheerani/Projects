#include <iostream>
using namespace std;



void quickSort(int* array, int left, int right)
{
	if(left < right)
	{
        // 1st STEP : partitioning around the pivot 
        int pivot = array[right]; //using the rightmost element as pivot
        int j = left-1;
        for(int i = left; i < right; i++)
        {
            if(array[i] < pivot)
            {
                int temp = array[++j];
                array[j] = array[i];
                array[i] = temp;
            }
        }
        int temp = array[++j];
        array[j] = array[right];
        array[right] = temp;
		//sort left half
		quickSort(array, left, j-1);
		//sort right half
		quickSort(array, j+1, right);
    }
}

void printArray(int *array, int size)
{
	cout << "[";
	for(int i = 0; i < size; i++)
	{
		cout << array[i] << ", ";
	}
	cout << "\b\b]\n";
}

int main()
{
    int array[6] = {42, 3, 100, 56, -1, 0};
	cout << "Before Sorting:\n";
	printArray(array, 6);
	cout << "After using quick sort in ascending order:\n";
	quickSort(array, 0, 6-1);
	printArray(array, 6);
}