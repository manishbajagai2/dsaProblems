// Write a program to find the maximum and minimum element in an array

#include <bits/stdc++.h>
using namespace std;

// simple linear search algorithm

int findMaxi(int arr[], int n, int mx)
{
    for (int i = 0; i < n; i++)
    {
        if (arr[i] > mx)
            mx = arr[i];
    }
    return mx;
}
int findMini(int arr[], int n, int mi)
{
    for (int i = 0; i < n; i++)
    {
        if (arr[i] < mi)
            mi = arr[i];
    }
    return mi;
}

// finding with minimum number of comparison :
// Tournament method (Divide and Conquer) -

struct Pair
{
    int min, max;
};

struct Pair getminmax(int arr[], int low, int high)
{
    struct Pair minmax, cleft, cright;
    // for one element
    if (low == high)
    {
        minmax.min = arr[low];
        minmax.max = arr[high];
        return minmax;
    }
    // for two elements
    if (high == low + 1)
    {
        if (arr[low] > arr[high])
        {
            minmax.min = arr[high];
            minmax.max = arr[low];
        }
        return minmax;
    }
    // for more than teo elements
    int mid;
    mid = (low + high) / 2;
    cleft = getminmax(arr, low, mid);
    cright = getminmax(arr, mid + 1, high);
    // comparison for
    // minimum element
    if (cleft.min < cright.min)
        minmax.min = cleft.min;
    else
        minmax.min = cright.min;
    // maximum element
    if (cleft.max > cright.max)
        minmax.max = cleft.max;
    else
        minmax.max = cright.max;
    return minmax;
}

int main()
{
    int arr[] = {56, 1, 18, 277, 83, 12, 392, 1};
    int size = sizeof(arr) / sizeof(arr[0]);
    int maxi = INT_MIN;
    int mini = INT_MAX;

    cout << "\nMaximum using linear search is " << findMaxi(arr, size, maxi);
    cout << "\nMinimum using linear search is " << findMini(arr, size, mini) << endl;

    struct Pair res = getminmax(arr, 0, size - 1);
    cout << "\nMaximum in pair using lesser comparison is " << res.max;
    cout << "\nMinimum in pair using lesser comparison is " << res.min << endl;

    cout << endl;
    return 0;
}