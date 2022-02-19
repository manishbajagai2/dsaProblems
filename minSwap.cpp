/*
Minimum swaps and K together

Given an array arr of n positive integers and a number k. One can apply a swap operation on the array any number of times, i.e choose any two index i and j (i < j) and swap arr[i] , arr[j] . Find the minimum number of swaps required to bring all the numbers less than or equal to k together, i.e. make them a contiguous subarray.

Example 1:

Input :
arr[ ] = {2, 1, 5, 6, 3}
K = 3
Output :
1
Explanation:
To bring elements 2, 1, 3 together, swap index 2 with 4 (0-based indexing), i.e. element arr[2] = 5 with arr[4] = 3 such that final array will be- arr[] = {2, 1, 3, 6, 5}
*/

#include <bits/stdc++.h>
using namespace std;

int minSwap(int arr[], int n, int k)
{
    int good = 0, bad = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] <= k)
            good++;
    }
    for (int i = 0; i < good; i++)
    {
        if (arr[i] > k)
            bad++;
    }
    int i = 0, j = good, ans = bad;
    while (j < n)
    {
        if (arr[i] > k)
            bad--;
        if (arr[j] > k)
            bad++;
        ans = min(ans, bad);
        i++;
        j++;
    }
    return ans;
}

int main()
{
    int arr[] = {2, 1, 5, 6, 3};
    int k = 3;
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << "\nMinimum swaps for numbers less than or equal to K together is " << minSwap(arr, n, k) << endl;
    return 0;
}