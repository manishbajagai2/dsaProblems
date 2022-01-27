// Write a program to reverse an array or string
#include<bits/stdc++.h>
using namespace std;

void reverseit(int arr[], int start, int end){
    while(start<end){
        int temp = arr[start];
        arr[start] = arr[end];
        arr[end] = temp;
        start++;
        end--;
    }
}

void reverserec(int arr[], int start, int end){
    if(start >= end)
        return;
    int temp = arr[start];
    arr[start] = arr[end];
    arr[end] = temp;
    reverserec(arr, start+1, end-1);
}

void printArr(int arr[], int n){
    for(int i = 0; i<n; i++)
        cout<<arr[i]<<" ";
}

int main(){
    int arr[] = {1,2,3,4,5,6};
    int n = sizeof(arr)/sizeof(arr[0]);
    
    cout<<"\nOriginal Array is : "<<endl;
    printArr(arr,n);
    cout<<endl;

    // cout<<"\nReversing using iteration : "<<endl;
    // reverseit(arr,0,n-1);
    // printArr(arr,n);
    // cout<<endl;

    cout<<"\nReversing using recursion : "<<endl;
    reverserec(arr,0,n-1);
    printArr(arr,n);
    cout<<endl;
    return 0;
}