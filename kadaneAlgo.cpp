/*
Given an array Arr[] of N integers. Find the contiguous sub-array(containing at least one number) which has the maximum sum and return its sum.

Example 1:

Input:
N = 5
Arr[] = {1,2,3,-2,5}
Output:
9
Explanation:
Max subarray sum is 9 of elements (1, 2, 3, -2, 5) which is a contiguous subarray.
*/

#include <bits/stdc++.h>
using namespace std;

int kadane(int arr[], int n)
{
    int curSum = arr[0], maxSoFar = arr[0];
    for (int i = 1; i < n; i++)
    {
        curSum = max(arr[i], curSum + arr[i]);
        maxSoFar = max(curSum, maxSoFar);
    }
    return maxSoFar;
}

int main()
{
    int arr[] = {1, 2, 3, -2, 5};
    int n = 5;
    cout << "\nMaximum contguous subarray sum is " << kadane(arr, n) << endl;
    return 0;
}