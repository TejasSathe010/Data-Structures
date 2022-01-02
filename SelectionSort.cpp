#include <iostream>
using namespace std;

void selectionSort(int arr[], int size) {
  for(int i=0; i<=size-2; i++) {
    int minIndex = i;
    for(int j=i+1; j<=size-1; j++) {
      if(arr[j] < arr[minIndex]) {
        minIndex = j;
      }
    }
    swap(arr[i], arr[minIndex]);
  }
}



int main() 
{
    int arr[] = {99, 7, 3, 5, 5, 6, 8, 2, 1};
    int size = sizeof(arr) / sizeof(arr[0]);
    
    selectionSort(arr, size);
    
    for(int i=0; i<size; i++) {
        cout << arr[i] << " ";
    }
}