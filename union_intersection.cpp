/*
Union and Intersection of two sorted arrays

Given two sorted arrays, find their union and intersection.

Example:

Input : arr1[] = {1, 3, 4, 5, 7}
        arr2[] = {2, 3, 5, 6}
Output : Union : {1, 2, 3, 4, 5, 6, 7}
         Intersection : {3, 5}

Input : arr1[] = {2, 5, 6}
        arr2[] = {4, 6, 8, 10}
Output : Union : {2, 4, 5, 6, 8, 10}
         Intersection : {6}
*/

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int arr1[] = {1, 3, 4, 5, 7};
    int arr2[] = {2, 3, 5, 6};
    int n1 = sizeof(arr1) / sizeof(arr1[0]);
    int n2 = sizeof(arr2) / sizeof(arr2[0]);

    map<int, int> unionIntersection;
    for (int i = 0; i < n1; i++)
        unionIntersection[arr1[i]]++;
    for (int j = 0; j < n2; j++)
        unionIntersection[arr2[j]]++;

    cout << "\nUnion : ";
    for (auto it : unionIntersection)
        cout << it.first << " ";

    cout << "\nIntersection : ";
    for (auto it : unionIntersection)
    {
        if (it.second > 1)
            cout << it.first << " ";
    }
    return 0;
}