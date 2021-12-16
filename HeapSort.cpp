#include <iostream>
using namespace std;

void maxHeapify(int arr[], int size, int i) {
    int leftChild = (2*i) + 1;
    int rightChild = (2*i) + 2;
    int largest = i;
    if(arr[leftChild] > arr[largest] && leftChild < size) {
        largest = leftChild;
    }

    if(arr[rightChild] > arr[largest] && rightChild < size) {
        largest = rightChild;
    }

    if(largest != i) {
        swap(arr[i], arr[largest]);
        maxHeapify(arr, size, largest);
    }
}

void buildHeap(int arr[], int size) {
    int startIndex = (size / 2) - 1;
    for(int i=startIndex; i >= 0; i--) {
        maxHeapify(arr, size, i);
    }
}


void heapSort(int arr[], int size) {
  buildHeap(arr, size);
  for(int i=size-1; i>=1; i--) {
    swap(arr[0], arr[i]);
    maxHeapify(arr, size, 0);
  }
}

int main() {
    int arr[] = {3, 4, 6, 7, 2, 1};
    int size = sizeof(arr) / sizeof(arr[0]);
    heapSort(arr, size);
    
    for(int j=0; j<=size-1; j++) {
      cout << arr[j] << " ";
    }
}