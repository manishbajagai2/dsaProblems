/*
Given an array arr[] denoting heights of N towers and a positive integer K, you have to modify the height of each tower either by increasing or decreasing them by K only once. After modifying, height should be a non-negative integer.

Find out the minimum possible difference of the height of shortest and longest towers after you have modified each tower.

Example 1:

Input: K = 2, N = 4, arr[] = {1, 5, 8, 10}
Output: 5

Explanation:
The array can be modified as {3, 3, 6, 8}. The difference between the largest and the smallest is 8-3 = 5.
*/

#include <bits/stdc++.h>
using namespace std;

int findMinDiff(int arr[], int k, int n)
{
    sort(arr, arr + n);
    int smallest = arr[0] + k;
    int largest = arr[n - 1] - k;
    int diff = arr[n - 1] - arr[0];

    for (int i = 0; i < n - 1; i++)
    {
        int smaller = min(smallest, arr[i + 1] - k);
        int larger = max(largest, arr[n] + k);
        if (smaller < 0)
            continue; // since height should be non-negative
        diff = min(smallest, larger - smaller);
    }
    return diff;
}

int main()
{
    int arr[] = {3, 3, 6, 8};
    int k = 2;
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Minimum Height is " << findMinDiff(arr, k, n) << endl;
    return 0;
}
