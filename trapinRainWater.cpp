/*
Trapping Rain Water

Given an array arr[] of N non-negative integers representing the height of blocks. If width of each block is 1, compute how much water can be trapped between the blocks during the rainy season.

Input:
N = 4
arr[] = {7,4,0,9}
Output:
10
Explanation:
Water trapped by above block of height 4 is 3 units and above block of height 0 is 7 units. So, the total unit of water trapped is 10 units.
*/

#include <bits/stdc++.h>
using namespace std;

// Time Complexity is O(n^2) and Space complexity is O(1)
int maxWater(int arr[], int n)
{
    int res = 0;
    for (int i = 1; i < n - 1; i++)
    {
        int left = arr[i];
        for (int j = 0; j < i; j++)
            left = max(left, arr[j]);

        int right = arr[i];
        for (int j = i + 1; j < n; j++)
            right = max(right, arr[j]);

        res += min(left, right) - arr[i];
    }
    return res;
}

// Time Complexity is O(n) and Space complexity is O(n)
int maxStoredWater(int arr[], int n)
{
    int left[n], right[n], water = 0;

    left[0] = arr[0];
    right[n - 1] = arr[n - 1];

    for (int i = 1; i < n; i++)
        left[i] = max(left[i - 1], arr[i]);

    for (int i = n - 2; i >= 0; i--)
        right[i] = max(right[i + 1], arr[i]);

    for (int i = 1; i < n - 1; i++)
    {
        int val = min(left[i - 1], right[i + 1]);
        if (val > arr[i])
            water += val - arr[i];
    }
    return water;
}

// Time Complexity is O(n) and Space complexity is O(1)
int findWaterStored(int arr[], int n)
{
    int l = 0, r = n - 1, lmax = 0, rmax = 0, res = 0;
    while (l <= r)
    {
        if (arr[l] <= arr[r])
        {
            if (arr[l] >= lmax)
                lmax = arr[l];
            else
                res += lmax - arr[l];
            l++;
        }
        else
        {
            if (arr[r] >= rmax)
                rmax = arr[r];
            else
                res += rmax - arr[r];
            r--;
        }
    }
    return res;
}

int main()
{
    int arr[] = {7, 4, 0, 9};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << "\nUsing two loops, amount of water stored in unit is " << maxWater(arr, n) << endl;

    cout << "\nUsing Arrays, the amount of water stored in unit is " << maxStoredWater(arr, n) << endl;

    cout << "\nUsing Two Pointer,amount of water stored in unit is " << findWaterStored(arr, n) << endl;

    cout << endl;
    return 0;
}
