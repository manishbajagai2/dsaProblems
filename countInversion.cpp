/*
Given an array of integers. Find the Inversion Count in the array. 

Inversion Count: For an array, inversion count indicates how far (or close) the array is from being sorted. If array is already sorted then the inversion count is 0. If an array is sorted in the reverse order then the inversion count is the maximum. 
Formally, two elements a[i] and a[j] form an inversion if a[i] > a[j] and i < j.
 
Example 1:

Input: N = 5, arr[] = {2, 4, 1, 3, 5}
Output: 3
Explanation: The sequence 2, 4, 1, 3, 5 has three inversions (2, 1), (4, 1), (4, 3).
*/

#include<bits/stdc++.h>
using namespace std;

// Time complexity is O(n^2)
void countInv(int arr[], int n){
    int inv = 0;
    for(int i = 0; i < n; i++){
        for(int j = i+1; j<n; j++){
            if(arr[i]>arr[j])
                inv++;
        }
    }
    cout<<"\nCount inversion by naive method is : "<<inv<<endl;
}

// Worst Time Complexity is O(n^2). Littl better than the above in average

void countingInv(int arr[], int n){
    multiset<int>s;
    s.insert(arr[0]);
    int inv = 0;
    for(int i = 1; i<n; i++){
        s.insert(arr[i]);
        inv += distance(s.upper_bound(arr[i]),s.end());
    }
    cout<<"\nCount inversion using STL is : "<<inv<<endl;
}

int main(){
    int arr[] = {2, 4, 1, 3, 5};
    int n = 5;
    countInv(arr,n);
    countingInv(arr,n);
    return 0;
}