/*
Cyclically rotate an array by one

Given an array, rotate the array by one position in clock-wise direction.
 
Example 1:

Input:
N = 5
A[] = {1, 2, 3, 4, 5}
Output:
5 1 2 3 4

Note : Modify the array
*/

#include<bits/stdc++.h>
using namespace std;

void printingArray(int arr[], int n){
    for(int i=0; i < n; i++)    cout<<arr[i]<<" ";
    cout<<endl;
}

int main(){
    int arr[] = {1, 2, 3, 4, 5};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout<<"\nOriginal Array : ";
    printingArray(arr, n);

    reverse(arr,arr+n);
    reverse(arr+1,arr+n);

    cout<<"\nRotated Array by one is : ";
    printingArray(arr, n);

    cout<<endl;
    return 0;
}