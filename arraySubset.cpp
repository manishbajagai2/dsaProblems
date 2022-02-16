/*
Given two arrays: a1[0..n-1] of size n and a2[0..m-1] of size m. Task is to check whether a2[] is a subset of a1[] or not. Both the arrays can be sorted or unsorted. It may be assumed that elements in both array are distinct.

Example 1:

Input:
a1[] = {11, 1, 13, 21, 3, 7}
a2[] = {11, 3, 7, 1}
Output: Yes

Explanation:
a2[] is a subset of a1[]
*/

#include <bits/stdc++.h>
using namespace std;

// Time Complexity and Space Complexity is O(n^2) and O(1) respt.
string isSubset1(int a1[], int a2[], int n, int m)
{
    int i = 0;
    for (int j = 0; j < m; j++)
    {
        for (i = 0; i < n; i++)
        {
            if (a2[j] == a1[i])
                break;
        }
        if (i == n)
            return "No";
    }
    return "Yes";
}

// Time Complexity and Space Complexity is O(nlogn) and O(1) respt.
string isSubset2(int a1[], int a2[], int n, int m)
{
    int count = 0;
    sort(a1, a1 + n);
    for (int i = 0; i < m; i++)
    {
        if (binary_search(a1, a1 + n, a2[i]))
            count++;
    }
    if (count == m)
        return "Yes";
    else
        return "No";
}

// Time Complexity and Space Complexity is O(n) and O(n) respt.
string isSubset3(int a1[], int a2[], int n, int m)
{
    set<int> s;
    for (int i = 0; i < n; i++)
        s.insert(a1[i]);

    for (int i = 0; i < n; i++)
    {
        if (s.find(a2[i]) == s.end())
            return "No";
    }
    return "Yes";
}

int main()
{
    // int a1[] = {11, 1, 13, 21, 3, 7};
    // int a2[] = {11, 3, 7, 1};
    int a1[] = {10, 5, 2, 23, 19};
    int a2[] = {19, 5, 3};
    int n1 = sizeof(a1) / sizeof(a1[0]);
    int n2 = sizeof(a2) / sizeof(a2[0]);

    cout << "\nBy two loops, array2 subset of array1 : " << isSubset1(a1, a2, n1, n2) << endl;

    cout << "\nBy Sorting and Searching, array2 subset of array1 : " << isSubset2(a1, a2, n1, n2) << endl;

    cout << "\nBy set DS, array2 subset of array1 : " << isSubset3(a1, a2, n1, n2) << endl;

    return 0;
}