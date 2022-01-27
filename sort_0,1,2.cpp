/*
Given an array of size N containing only 0s, 1s, and 2s; sort the array in ascending order.

Example :

Input:
N = 5
arr[]= {0 2 1 2 0}
Output:
0 0 1 2 2
Explanation:
0s 1s and 2s are segregated into ascending order.
*/
#include <bits/stdc++.h>
using namespace std;

void printingArray(int arr[], int n)
{
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}

void sortByCount(int arr[], int n)
{
    int zero = 0, ones = 0, twos = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == 0)
            zero++;
        else if (arr[i] == 1)
            ones++;
        else
            twos++;
    }
    for (int i = 0; i < n; i++)
    {
        if (i < ones)
            cout << "0 ";
        else if (i >= ones and i <= ones + twos)
            cout << "1 ";
        else
            cout << "2 ";
    }
    cout << endl;
}

void swap(int arr[], int a, int b)
{
    int temp = arr[a];
    arr[a] = arr[b];
    arr[b] = temp;
}

void dnfsort(int arr[], int n)
{
    int low = 0, mid = 0, high = n - 1;
    while (mid <= high)
    {
        if (arr[mid] == 0)
        {
            swap(arr, low, mid);
            low++;
            mid++;
        }
        else if (arr[mid] == 1)
        {
            mid++;
        }
        else
        {
            swap(arr, mid, high);
            high--;
        }
    }
}

int main()
{
    int arr[] = {2, 1, 0, 1, 0, 0, 1, 2, 1, 2, 0};
    int n = sizeof(arr) / sizeof(arr[0]);

    int arr1[n], arr2[n], arr3[n];

    for (int i = 0; i < n; i++)
    {
        arr1[i] = arr[i];
        arr2[i] = arr[i];
        arr3[i] = arr[i];
    }

    cout << "\n Original Array is - ";
    printingArray(arr, n);

    cout << "\n Sorting using sort function is - ";
    sort(arr1, arr1 + n);
    printingArray(arr1, n);

    cout << "\n Sorting by counting numbers is - ";
    sortByCount(arr2, n);

    cout << "\n By using concept of DNF Sort is - ";
    dnfsort(arr3, n);
    printingArray(arr3, n);

    cout << endl;
    return 0;
}