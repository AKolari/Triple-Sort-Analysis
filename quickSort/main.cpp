
#include <iostream>
using namespace std;
long long steps = 0;
void swap(int *a, int *b) {
  int t = *a;
  *a = *b;
  *b = t;
  steps++;
}

void printArray(int array[], int size) {
  int i;
  for (i = 0; i < size; i++)
    cout << array[i] << " ";
  cout << endl;
}
int partition(int array[], int low, int high) {
  int pivot = array[high];
  int i = (low - 1);
  for (int j = low; j < high; j++) {
   steps++; 
    if (array[j] <= pivot) {
      i++;
      swap(&array[i], &array[j]);
    }
  }
  swap(&array[i + 1], &array[high]);
  return (i + 1);
}

void quickSort(int array[], int low, int high) {
  if (low < high) {

    
      
  
    int pi = partition(array, low, high);

   
    quickSort(array, low, pi - 1);

    quickSort(array, pi + 1, high);
  }
}
void run( int size, int times )
{
    clock_t begin_time = clock();
    
    
    
    for ( int t = 0; t < times; t++ )
    {
        int *arr = new int[size];
    
        for ( int i = 0; i < size; i++ )
        {
            arr[i] = rand() % (size*10);        
        }
    
        
    
        quickSort(arr, 0, size);

        delete[] arr;
    
        
    }

    clock_t end_time = clock();
    cout << size << " ";
    double nswaps = 1. * steps / times;
    printf("%.2f ", nswaps);
    
    cout << ( 1. * (end_time - begin_time) / CLOCKS_PER_SEC)  << endl;
}

int main() {
    for ( int i = 1000; i <= 50000; i += 1000 ){
        steps=0;
        run(i, 500);
        
        
    }
}