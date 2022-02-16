/*
Triplet Sum in Array

Given an array arr of size n and an integer X. Find if there's a triplet in the array which sums up to the given integer X.

Example 1:

Input:
n = 6, X = 13
arr[] = [1 4 45 6 10 8]
Output:
1
Explanation:
The triplet {1, 4, 8} in
the array sums up to 13.
*/

#include <bits/stdc++.h>
using namespace std;

// Time and Space Complexity is O(n^3) and O(1) respectively
bool find3Numbers1(int arr[], int n, int x)
{
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            for (int k = j + 1; k < n; k++)
            {
                if (arr[i] + arr[j] + arr[k] == x)
                    ans = 1;
            }
        }
    }
    return ans;
}

// Time and Space Complexity is O(n^2) and O(n) respectively
bool find3Numbers2(int arr[], int n, int x)
{
    int ans = 0;
    unordered_set<int> s;
    for (int i = 0; i < n - 2; i++)
    {
        int curr = x - arr[i];
        for (int j = i + 1; j < n; j++)
        {
            if (s.find(curr - arr[j]) != s.end())
            {
                ans = 1;
                break;
            }
            s.insert(arr[j]);
        }
    }
    return ans;
}

// Time and Space Complexity is O(n^2) and O(1) respectively
bool find3Numbers3(int arr[], int n, int x)
{
    int ans = 0;
    sort(arr, arr + n);
    for (int i = 0; i < n - 2; i++)
    {
        int l = i + 1, r = n - 1;
        while (l < r)
        {
            if (arr[i] + arr[l] + arr[r] == x)
            {
                ans = 1;
                break;
            }
            else if (arr[i] + arr[l] + arr[r] < x)
                l++;
            else
                r--;
        }
        if (ans == 1)
            break;
    }
    return ans;
}

int main()
{
    int arr[] = {1, 4, 45, 6, 10, 8};
    int n = sizeof(arr) / sizeof(arr[0]);
    int x = 13;

    cout << "\nUsing three loops returned value is " << find3Numbers1(arr, n, x) << endl;

    cout << "\nUsing the set DS the returned value is " << find3Numbers2(arr, n, x) << endl;

    cout << "\nSorting and by three pointers, value is " << find3Numbers3(arr, n, x) << endl;

    cout << endl;
    return 0;
}