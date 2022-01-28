/*
Move all negative numbers to beginning and positive to end with constant extra space

Examples :

Input: -12, 11, -13, -5, 6, -7, 5, -3, -6
Output: -12 -13 -5 -7 -3 -6 11 6 5

Note : No order is preserved
*/

#include <bits/stdc++.h>
using namespace std;

void partitionProcess(int arr[], int n)
{
    int j = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] < 0)
        { // move i forward if element is positive
            if (i != j)
                swap(arr[i], arr[j]);
            j++;
        }
    }
    cout << endl;
}

void twoPointer(int arr[], int n)
{
    int l = 0, r = n - 1;
    while (l <= r)
    {
        if (arr[l] < 0 and arr[r] < 0)
            l++;
        else if (arr[l] > 0 and arr[r] > 0)
            r++;
        else if (arr[l] > 0 and arr[r] < 0)
        {
            swap(arr[l], arr[r]);
            l++;
            r--;
        }
        else
        {
            l++;
            r--;
        }
    }
}

void printingArray(int arr[], int n)
{
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}

int main()
{
    int arr1[] = {-12, 11, -13, -5, 6, -7, 5, -3, -6};
    int n = sizeof(arr1) / sizeof(arr1[0]);
    partitionProcess(arr1, n);
    cout << "\nRearranged after partition process of quick sort is : ";
    printingArray(arr1, n);

    int arr2[] = {-12, 11, -13, -5, 6, -7, 5, -3, -6};
    twoPointer(arr2, n);
    cout << "\nRearranged after using two pointer approach is : ";
    printingArray(arr2, n);

    cout << endl;
    return 0;
}