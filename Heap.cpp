#include<iostream>
using namespace std;

void maxHeapify(int arr[], int size, int i) {
    int leftChild = (2*i) + 1;
    int rightChild = (2*i) + 2;
    int largest = i;
    if(arr[leftChild] > arr[i] && leftChild < size) {
        largest = leftChild;
    }

    if(arr[rightChild] > largest && rightChild < size) {
        largest = rightChild;
    }

    if(largest != i) {
        swap(arr[i], arr[largest]);
        maxHeapify(arr, size, largest);
    }
}

int main() {
    // int arr[] = {4, 19, 36, 17, 3, 25, 1, 2, 7};
    int arr[] = {2, 3, 4};
    int size = sizeof(arr) / sizeof(arr[0]);
    maxHeapify(arr, size, 0);

    for(int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
}