/*
Minimum number of jumps to reach the end of the array

Given an array of N integers arr[] where each element represents the max number of steps that can be made forward from that element. Find the minimum number of jumps to reach the end of the array (starting from the first element). If an element is 0, then you cannot move through that element.
Note: Return -1 if you can't reach the end of the array.

Example 1:

Input:
N = 11
arr[] = {1, 3, 5, 8, 9, 2, 6, 7, 6, 8, 9}
Output: 3

Explanation:
First jump from 1st element to 2nd element with value 3. Now, from here we jump to 5th element with value 9, and from here we will jump to last.
*/

#include <bits/stdc++.h>
using namespace std;

// Time Complexity is O(n^2) and Space Complexity is O(1)
int bottomUp(int arr[], int n)
{
    int dp[n];
    for (int i = 0; i < n; i++)
        dp[i] = INT_MAX;
    dp[0] = 0;
    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (dp[j] != INT_MAX and arr[j] + j >= i)
            {
                if (dp[j] + 1 < dp[i])
                    dp[i] = dp[j] + 1;
            }
        }
    }
    if (dp[n - 1] != INT_MAX)
        return dp[n - 1];
    else
        return -1;
}

// Time Complexity is O(n) and Space Complexity is O(1)
int minJump(int arr[], int n)
{
    if (n <= 1)
        return 0;
    if (arr[0] == 0)
        return -1;
    int maxReach = arr[0], step = arr[0], jump = 1;
    for (int i = 1; i < n; i++)
    {
        if (i == n - 1)
            return jump;
        maxReach = max(maxReach, i + arr[i]);
        step--;
        if (step == 0)
        {
            jump++;
            if (i >= maxReach)
                return -1;
            step = maxReach - i;
        }
    }
    return -1;
}

int main()
{
    int arr[] = {1, 3, 5, 8, 9, 2, 6, 7, 6, 8, 9};
    int n = 11;
    cout << "\nMinimum Jump using bottom up approach is " << bottomUp(arr, n) << endl;

    cout << "\nMinimum Jump using variables is " << minJump(arr, n) << "\n\n";
    return 0;
}