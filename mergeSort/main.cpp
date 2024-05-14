
#include <iostream>
#include <stdlib.h>
using namespace std;


int merge(int array[], int const left, int const mid,
		int const right)
{
    int count=0;
	auto const subArrayOne = mid - left + 1;
	auto const subArrayTwo = right - mid;

	
	auto *leftArray = new int[subArrayOne],
		*rightArray = new int[subArrayTwo];

	
	for (auto i = 0; i < subArrayOne; i++){
	    leftArray[i] = array[left + i];
		
	}
		
	for (auto j = 0; j < subArrayTwo; j++){
	    rightArray[j] = array[mid + 1 + j];
	   
	}
		

	auto indexOfSubArrayOne= 0, 
		indexOfSubArrayTwo= 0; 
	int indexOfMergedArray= left; 

	
	while (indexOfSubArrayOne < subArrayOne
		&& indexOfSubArrayTwo < subArrayTwo) {
		if (leftArray[indexOfSubArrayOne]
			<= rightArray[indexOfSubArrayTwo]) {
			array[indexOfMergedArray]
				= leftArray[indexOfSubArrayOne];
			indexOfSubArrayOne++;
		}
		else {
			array[indexOfMergedArray]
				= rightArray[indexOfSubArrayTwo];
			indexOfSubArrayTwo++;
		}
		indexOfMergedArray++;
		count++;
	}
	while (indexOfSubArrayOne < subArrayOne) {
		array[indexOfMergedArray]
			= leftArray[indexOfSubArrayOne];
		indexOfSubArrayOne++;
		indexOfMergedArray++;
		count++;
	}
	
	while (indexOfSubArrayTwo < subArrayTwo) {
		array[indexOfMergedArray]
			= rightArray[indexOfSubArrayTwo];
		indexOfSubArrayTwo++;
		indexOfMergedArray++;
		count++;
	}
	
	delete[] leftArray;
	delete[] rightArray;
	return count;
}


int mergeSort(int array[], int const begin, int const end)
{
    int count=0;
   
	if (begin >= end)
		return count; 

	auto mid = begin + (end - begin) / 2;
	count+=mergeSort(array, begin, mid);
	count+=mergeSort(array, mid + 1, end);
	count+=merge(array, begin, mid, end);
	return count;
	

	
}


void printArray(int A[], int size)
{
	for (auto i = 0; i < size; i++)
		cout << A[i] << " ";
}
void run( int size, int times )
{
    clock_t begin_time = clock();
    
    long long steps = 0;
    
    for ( int t = 0; t < times; t++ )
    {
        int *arr = new int[size];
    
        for ( int i = 0; i < size; i++ )
        {
            arr[i] = rand() % (size*10);
            
        }
    
    
    
        steps += mergeSort(arr, 0, size - 1);

        delete[] arr;
    
        
    }

    clock_t end_time = clock();
    cout << size << " ";
    double nswaps = 1. * steps / times;
    printf("%.2f ", nswaps);
    
    cout << ( 1. * (end_time - begin_time) / CLOCKS_PER_SEC) << "s" << endl;
}

int main()
{
    
   for ( int i = 1000; i <= 50000; i += 1000 )
        run(i, 500);
    
    return 0;
}

