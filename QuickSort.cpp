#include<iostream>
using namespace std;

int partition(int arr[], int start, int end) {
    int pivot = arr[end];
    int pIndex = start;

    for(int i = start; i < end; i++) {
        if(arr[i] <= pivot) {
            swap(arr[i], arr[pIndex]);
            pIndex++;
        }
    }
    swap(arr[pIndex], arr[end]);
    return pIndex;
}


void quickSort(int arr[], int start, int end) {
    if(start < end) {
        int pivot = partition(arr, start, end);
        quickSort(arr, start, pivot-1);
        quickSort(arr, pivot+1, end);
    }
}


int main() {
    int arr[] = {4, 6, 8, 2, 9, 5};
    int size = sizeof(arr) / sizeof(arr[0]);
    quickSort(arr, 0, size-1);

    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}