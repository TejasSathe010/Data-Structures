#include<iostream>
using namespace std;

int* input(int arr[], int size){

    cout << "Enter elements: " << endl;

    for(int i=0; i<size; i++){
        cin >> arr[i];
    }
    return arr;
}

int* traversing(int arr[], int size){
    
    cout << "Entered elements: " << endl;
    
    for(int i=0; i<size; i++){
        cout << arr[i] << endl;
    }
    return arr;
}

int* insertion(int arr[], int &size, int pos){

    int item = 0;
    size ++;

    for(int i=size; i > pos; i--){
        arr[i] = arr[i-1];
    }

    cout << "Enter the item you want to ins at " << pos << endl;
    cin >> item;
    arr[pos] = item;

    return arr;
}

int* deletion(int arr[], int &size, int pos){

    for(int i=pos; i < size; i++){
        arr[i] = arr[i+1];
    }

    size --;

    return arr;
}

int* reverse(int arr[], int size){
    
    int temp = 0;
    for(int i=0, j=size-1; i < size / 2 && j >= size / 2; i++, j--){
        temp = arr[j];
        arr[j] = arr[i];
        arr[i] = temp;
    }
    return arr;
}


int main(){

    int arr[100], size, inPos, delPos;

    cout << "Enter the size of array" << endl;
    cin >> size;

    input(arr, size);
    traversing(arr, size);

    // cout << "Enter the pos you want insert at" << endl;
    // cin >> inPos;

    // insertion(arr, size, inPos);
    // cout << "Updated size " << size << endl;
    // traversing(arr, size);


    // cout << "Enter the pos you want delete " << endl;
    // cin >> delPos;

    // deletion(arr, size, delPos);
    // cout << "Updated size " << size << endl;
    // traversing(arr, size);

    cout << "Reversing the array" << endl;
    reverse(arr, size);
    traversing(arr, size);

    return 0;
}