/*

Given an array of positive and negative numbers. Find if there is a subarray (of size at-least one) with 0 sum.

Example 1:

Input:
5
4 2 -3 1 6

Output:
Yes

Explanation:
2, -3, 1 is the subarray
with sum 0.

*/
#include <bits/stdc++.h>
using namespace std;

// Time Complexity is O(n^2) and Space Complexity is O(1)
void subarraySum(int arr[], int n)
{
    int f = 0;
    for (int i = 0; i < n; i++)
    {
        int s = 0;
        for (int j = i; j < n; j++)
        {
            s += arr[j];
            if (s == 0)
            {
                f = 1;
                break;
            }
        }
        if (f == 1)
            break;
    }
    if (f == 1)
        cout << "Yes" << endl;
    else
        cout << "No" << endl;
}

void subArraySumZero(int arr[], int n)
{
    int s = 0, f = 0;
    unordered_map<int, int> map;
    for (int i = 0; i < n; i++)
    {
        s += arr[i];
        if (s == 0 or map[s] or arr[i] == 0)
        {
            f = 1;
            break;
        }
        else
        {
            map[s] = 1;
        }
    }
    if (f == 1)
        cout << "Yes" << endl;
    else
        cout << "No" << endl;
}

int main()
{
    int arr[] = {4, 2, -3, 1, 6};
    int n = 5;
    cout << "\nSubarray exists = ";
    subarraySum(arr, n);
    cout << "\nSubarray exists = ";
    subArraySumZero(arr, n);
    return 0;
}