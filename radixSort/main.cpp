
#include <iostream>
using namespace std;
int steps=0;
int d;
int getMax(int arr[], int n)
{
    int mx = arr[0];
    for (int i = 1; i < n; i++)
        if (arr[i] > mx)
            mx = arr[i];
    return mx;
}
void countSort(int arr[], int n, int exp)
{
    int output[n]; 
    int i, count[10] = { 0 };
    for (i = 0; i < n; i++)
        count[(arr[i] / exp) % 10]++;
        
    for (i = 1; i < 10; i++)
        count[i] += count[i - 1];
    for (i = n - 1; i >= 0; i--) {
        output[count[(arr[i] / exp) % 10] - 1] = arr[i];
        count[(arr[i] / exp) % 10]--;
        steps++;  
    }
    for (i = 0; i < n; i++)
        arr[i] = output[i];

}
void radixsort(int arr[], int n)
{
    int m = getMax(arr, n);
    for (int exp = 1; m / exp > 0; exp *= 10){
        countSort(arr, n, exp);   
    }
    
}
void print(int arr[], int n)
{
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
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
         radixsort(arr, size);
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
    for ( int i = 1000; i < 100000; i += 1000 ){
        steps=0;
        run(i, 500);
    }      
}