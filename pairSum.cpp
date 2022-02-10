/*
Count pairs with given sum

Given an array of N integers, and an integer K, find the number of pairs of elements in the array whose sum is equal to K.

Example 1:

Input:
N = 4, K = 6
arr[] = {1, 5, 7, 1}
Output: 2
Explanation:
arr[0] + arr[1] = 1 + 5 = 6 and arr[1] + arr[3] = 5 + 1 = 6.

*/

#include <bits/stdc++.h>
using namespace std;

// Brute force - Time Complexity is O(n^2)
int countPairs(int arr[], int n, int k)
{
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (arr[i] + arr[j] == k)
                count++;
        }
    }
    return count;
}

// Optimal Solutin - Time Complexity is O(n)
int countingPairs(int arr[], int n, int k)
{
    unordered_map<int, int> m;
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        int t = k - arr[i];
        if (m[t])
            count += m[t];
        m[arr[i]]++;
    }
    return count;
}

int main()
{
    int arr[] = {1, 5, 7, 1};
    int k = 6, n = 4;
    cout << "\nBy Brute Force Approach the number of pairs equal to sum is " << countPairs(arr, n, k) << endl;

    cout << "\nThe optimal solution to thr number of pairs equal to sum is " << countingPairs(arr, n, k) << endl;
    return 0;
}