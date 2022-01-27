/*
Given an array arr[] and an integer K where K is smaller than size of array, the task is to find the Kth smallest element in the given array. It is given that all array elements are distinct.

Example 1:

Input:
N = 6
arr[] = 7 10 4 3 20 15
K = 3
Output : 7
Explanation :
3rd smallest element in the given array is 7.

*/

#include <bits/stdc++.h>
using namespace std;

int kthSmallest(int arr[], int n, int k)
{
    sort(arr, arr + n);
    return arr[k - 1];
}

int main()
{
    int arr[] = {55, 12, 1, 6, 32, 54, 99, 67, 2};
    int n = sizeof(arr) / sizeof(arr[0]);
    int k = 7;
    cout << "\nThe " << k << "th smallest element is " << kthSmallest(arr, n, k) << endl;
    return 0;
}