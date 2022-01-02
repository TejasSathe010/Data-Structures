#include <iostream>
using namespace std;

void BubbleSort(int arr[], int size) {
  for(int i = 1; i <= size-1; i++) {
    int flag = 0;
    for(int j = 0; j <= size-i-1; j++) {
      if(arr[j] > arr[j+1]) {
          swap(arr[j], arr[j+1]);
          flag=1;
      }
    }
    if(flag==0) {
        break;
    }
  }
}


int main()
{
    int arr[] = {99, 7, 3, 5, 5, 6, 8, 2, 1};
    int size = sizeof(arr) / sizeof(arr[0]);
    
    BubbleSort(arr, size);
    
    for(int i=0; i<size; i++) {
        cout << arr[i] << " ";
    }
}