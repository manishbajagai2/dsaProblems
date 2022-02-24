/*
Median of two sorted arrays of same size

Input:
ar1[] = {1, 12, 15, 26, 38}
ar2[] = {2, 13, 17, 30, 45}

Output:
16

Explanation:
Middle two elements are 15 and 17 Average of middle elements is (15 + 17) / 2 which is equal to 16
*/

#include <bits/stdc++.h>
using namespace std;

// Time complexity is O(n) and Space Complexity is O(1)
int countMerge(int a[], int b[], int n)
{
    int i = 0, j = 0, m1 = -1, m2 = -1;
    for (int count = 0; count <= n; count++)
    {
        if (i == n)
        {
            m1 = m2;
            m2 = b[0];
            break;
        }
        else if (j == n)
        {
            m1 = m2;
            m2 = a[0];
            break;
        }
        if (a[i] <= b[j])
        {
            m1 = m2;
            m2 = a[i];
            i++;
        }
        else
        {
            m1 = m2;
            m2 = b[j];
            j++;
        }
    }
    return (m1 + m2) / 2;
}

// Time Complexity is O(nlog n) and Space Complexity is O(1)
int takingUnion(int ar1[], int ar2[], int n){
    int j = 0;
    int i = n - 1;
    while (ar1[i] > ar2[j] && j < n && i > -1)
        swap(ar1[i--], ar2[j++]);
    sort(ar1, ar1 + n);
    sort(ar2, ar2 + n);
    return (ar1[n - 1] + ar2[0]) / 2;
}

int main()
{
    int ar1[] = {1, 12, 15, 26, 38};
    int ar2[] = {2, 13, 17, 30, 45};
    int n = sizeof(ar1) / sizeof(ar1[0]);

    cout << "\nCounting and Merging both array, the median is " << countMerge(ar1, ar2, n) << endl;

    cout << "\nBy union of both arrays and sorting, median is " << takingUnion(ar1, ar2, n) << endl;

    cout << endl;
    return 0;
}