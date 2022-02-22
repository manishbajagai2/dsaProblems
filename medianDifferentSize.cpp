/*
Median of two sorted arrays of different sizes

Given two sorted arrays, a[] and b[], the task is to find the median of these sorted arrays, where n is the number of elements in the first array, and m is the number of elements in the second array.

Input: ar1[] = {-5, 3, 6, 12, 15},ar2[] = {-12, -10, -6, -3, 4, 10}
Output : The median is 3.
Explanation : The merged array is :
ar3[] = {-12, -10, -6, -5 , -3, 3, 4, 6, 10, 12, 15},
So the median of the merged array is 3

Input: ar1[] = {2, 3, 5, 8}, ar2[] = {10, 12, 14, 16, 18, 20}
Output : The median is 11.
Explanation : The merged array is :
ar3[] = {2, 3, 5, 8, 10, 12, 14, 16, 18, 20}
if the number of the elements are even, so there are two middle elements, take the average between the two : (10 + 12) / 2 = 11.

Here we handle arrays of unequal size also.
*/

#include <bits/stdc++.h>
using namespace std;

// Time Complexity is O(m+n) and Space Complexity is O(1)
int linearMerging(int a[], int b[], int n, int m)
{
    int i = 0, j = 0, m1 = -1, m2 = -1;
    for (int count = 0; count <= (m + n) / 2; count++)
    {
        m2 = m1;
        if (i != n and j != m)
            m1 = a[i] > b[j] ? b[j++] : a[i++];
        else if (i < n)
            m1 = a[i++];
        else
            m1 = b[j++];
    }
    if ((m + n) % 2 == 1)
        return m1;
    else
        return ((m1 + m2) / 2);
}

int main()
{
    int ar1[] = {-5, 3, 6, 12, 15};
    int ar2[] = {-12, -10, -6, -3, 4, 10};
    int n1 = sizeof(ar1) / sizeof(ar1[0]);
    int n2 = sizeof(ar2) / sizeof(ar2[0]);

    cout << "\nBy linearly merging two arrays, median is " << linearMerging(ar1, ar2, n1, n2) << endl;

    cout << endl;
    return 0;
}