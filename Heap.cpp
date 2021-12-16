#include<iostream>
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

int extractMax(int arr[], int &size) {

    if(size < 1) {
        cout << "Heap Underflow";
        return -1;
    }

    int max = arr[0];
    arr[0] = arr[size-1];
    size -= 1;
    maxHeapify(arr, size, 0);
    return max;
}

void swap(int arr[], int i, int j) {
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}

void increaseKey(int arr[], int size, int i, int key) {
    if(key < arr[i]) {
        return;
    }
    arr[i] = key;
    while(i > 0 && arr[i/2] < arr[i]) {
        swap(arr, i, i/2);
        i /= 2;
    }
}

void decreaseKey(int arr[], int size, int i, int key) {
    if(key > arr[i]) {
        return;
    }
    arr[i] = key;
    maxHeapify(arr, size, i);
}

void insertValue(int arr[], int &heapSize, int value) {
    heapSize += 1;
    int index = heapSize - 1;
    arr[index] = value;

    while(index > 0 && arr[index] > arr[index/2]) {
        swap(arr, index, index/2);
        index = index/2;
    }
}

void printHeap(int arr[], int size) {
    cout << "Array representation of Heap is:\n";
    for (int i = 0; i < size; ++i)
        cout << arr[i] << " ";
    cout << "\n";
}


int main() {

    int arr[20] = { 1, 3, 5, 4, 6, 13, 10, 9, 8, 15, 17 };
    // int arr[] = {2, 3, 4};

    int heapSize = 11;
    // int size = sizeof(arr) / sizeof(arr[0]);
    cout << "size: " << heapSize << endl;

    buildHeap(arr, heapSize);
    printHeap(arr, heapSize);
    // Array representation of Heap is:
    // 17 15 13 9 6 5 10 4 8 3 1

    // int max = extractMax(arr, size);
    // cout << "max: " << max << endl;
    // printHeap(arr, size);

    // increaseKey(arr, size, 7, 40);
    // printHeap(arr, size);

    // decreaseKey(arr, heapSize, 6, 0);
    // printHeap(arr, heapSize);

    insertValue(arr, heapSize, 200);
    printHeap(arr, heapSize);

    decreaseKey(arr, heapSize, 0, 0);
    printHeap(arr, heapSize);
}