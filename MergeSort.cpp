#include <iostream>
using namespace std;

void merge(int left[], int left_size, int right[] ,int right_size, int arr[], int arr_size) {
    int i=0;
    int j=0;
    int k=0;
    while(i < left_size && j < right_size) {
      if(left[i] < right[j]) {
        arr[k++] = left[i++];
      } else {
        arr[k++] = right[j++];
      }
    }
    while(i < left_size) {
      arr[k++] = left[i++];
    }
    while(j < right_size) {
      arr[k++] = right[j++];
    }
}


void mergeSort(int arr[], int size) {
    if(size < 2) {
        return;
    }

    int mid = size / 2;
    int left[mid];
    int right[size-mid];

    for(int i = 0; i < mid; i++) {
        left[i] = arr[i];
    }

    for(int i = mid; i < size; i++) {
        right[i-mid] = arr[i];
    }

    mergeSort(left, mid);
    mergeSort(right, size-mid);
    merge(left, mid, right, size-mid, arr, size);

}


int main() {
    int arr[] = {4, 6, 8, 99, 2, 2, 9, 5};
    int size = sizeof(arr) / sizeof(arr[0]);
    mergeSort(arr, size);

    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}