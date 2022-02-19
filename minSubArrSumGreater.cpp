/*
Smallest subarray with sum greater than a given value

Given an array of integers and a number x, find the smallest subarray with sum greater than the given value.

Example:
arr[] = {1, 4, 45, 6, 0, 19}
x  =  51
Output: 3
Minimum length subarray is {4, 45, 6}

Return size of the array + 1 if no subarray is found.
*/

#include <bits/stdc++.h>
using namespace std;

// Time Complexity is O(n^2) and Space Complexity is O(1)
int smallestSubWithSum(int arr[], int n, int k)
{
    int mi = n + 1;
    for (int i = 0; i < n; i++)
    {
        int s = 0;
        for (int j = i; j < n; j++)
        {
            s += arr[j];
            if (s > k)
                mi = min(mi, j - i + 1);
        }
    }
    return mi;
}

// Time Complexity is O(n) and Space Complexity is O(1)
int smallSubSumGreater(int arr[], int n, int x)
{
    int mi = n + 1, i = 0, j = 0, s = 0;
    while (i <= j and j < n)
    {
        while (s <= x and j < n)
            s += arr[j++];
        while (s > x and i < j)
        {
            mi = min(mi, j - i);
            s -= arr[i];
            i++;
        }
    }
    return mi;
}

int main()
{
    int arr[] = {1, 4, 45, 6, 0, 19};
    int x = 51;
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "\nBy Brute force, smallest subarray sum greater than given number is " << smallestSubWithSum(arr, n, x) << endl;

    cout << "\nBy Two Pointer, smallest subarray sum greater than given number is " << smallSubSumGreater(arr, n, x) << endl;

    cout << endl;
    return 0;
}