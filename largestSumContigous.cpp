/*
Given an array Arr[] of N integers. Find the contiguous sub-array (containing at least one number) which has the maximum sum and return its sum.

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

// All solution has space complexity of O(1)

// 1. Brute Force Approach - Worst Time Complexity = O(n^3)

int brute(int arr[], int n)
{
    int maxSoFar = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        for (int j = i; j < n; j++)
        {
            int curSum = 0;
            for (int k = i; k <= j; k++)
                curSum += arr[k];
            if (curSum > maxSoFar)
                maxSoFar = curSum;
        }
    }
    return maxSoFar;
}

// Little Optimized with - Better Time Complexity = O(n^2)

int optimized(int arr[], int n)
{
    int maxSoFar = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        int curSum = 0;
        for (int j = 0; j < n; j++)
        {
            curSum += arr[j];
            if (curSum > maxSoFar)
                maxSoFar = curSum;
        }
    }
    return maxSoFar;
}

// Kadane's Algorithm = Best Time Complexity = O(n)
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
    int arr1[] = {1, 2, 3, -2, 5};
    int arr2[] = {1, 2, 3, -2, 5};
    int arr3[] = {1, 2, 3, -2, 5};

    int n = sizeof(arr1) / sizeof(arr1[0]);

    cout << "\nLargest sum contiguous subarray using brute force is " << brute(arr1, n) << endl;

    cout << "\nLargest sum contiguous subarray using in O(n^2) is " << optimized(arr2, n) << endl;

    cout << "\nLargest sum contiguous subarray using Kadane's Algorithm is " << kadane(arr3, n) << endl;

    cout << endl;
    return 0;
}