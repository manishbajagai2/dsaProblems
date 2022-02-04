/*
Merge Without Extra Space

Given two sorted arrays arr1[] of size N and arr2[] of size M. Each array is sorted in non-decreasing order. Merge the two arrays into one sorted array in non-decreasing order without using any extra space.


Example 1:

Input:
N = 4, M = 5
arr1[] = {1, 3, 5, 7}
arr2[] = {0, 2, 6, 8, 9}

Output: 0 1 2 3 5 6 7 8 9

Explanation: Since you can't use any extra space, modify the given arraysto form arr1[] = {0, 1, 2, 3}, arr2[] = {5, 6, 7, 8, 9}
*/

#include <bits/stdc++.h>
using namespace std;

void merge(int arr1[], int arr2[], int n, int m)
{
    int i = n - 1, j = 0;
    while (i >= 0 and j < m)
    {
        if (arr1[i] >= arr2[j])
        {
            swap(arr1[i], arr2[j]);
            i--;
            j++;
        }
        else
            break;
    }
    sort(arr1, arr1 + n);
    sort(arr2, arr2 + m);
}

void printtingArr(int arr[], int n)
{
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
}

int main()
{
    int arr1[] = {1, 3, 5, 7};
    int arr2[] = {0, 2, 6, 8, 9};
    int n = sizeof(arr1) / sizeof(arr1[0]);
    int m = sizeof(arr2) / sizeof(arr2[0]);
    merge(arr1, arr2, n, m);
    cout << "\nMerging two Arrays without extra space is : ";
    printtingArr(arr1, n);
    printtingArr(arr2, m);
    cout << endl;
    return 0;
}