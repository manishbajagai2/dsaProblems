/*
Three way partitioning

Given an array of size n and a range [a, b]. The task is to partition the array around the range such that array is divided into three parts.
1) All elements smaller than a come first.
2) All elements in range a to b come next.
3) All elements greater than b appear in the end.
The individual elements of three sets can appear in any order. You are required to return the modified array.

Example :

Input:
arr[] = {1, 14, 5, 20, 4, 2, 54, 20, 87, 98, 3, 1, 32}
lowVal = 14, highVal = 20
Output:
arr[] = {1, 5, 4, 2, 1, 3, 14, 20, 20, 98, 87, 32, 54}
*/

#include <bits/stdc++.h>
using namespace std;

// Brute Force Approach is to simply sort the Array having Time Complexity O(nlogn) and Space Complexity of O(n)

//  Using Two Pointer approach here Time Complexity is O(n) and Space Complexity is O(1).
void threeWayPartitioned(vector<int> &vec, int a, int b)
{
    int s = 0, i = 0, e = vec.size() - 1;
    while (i <= e)
    {
        if (vec[i] < a)
        {
            swap(vec[i], vec[s]);
            i++;
            s++;
        }
        else if (vec[i] > b)
        {
            swap(vec[i], vec[e]);
            e--;
        }
        else
            i++;
    }
}

int main()
{
    vector<int> vec{1, 14, 5, 20, 4, 2, 54, 20, 87, 98, 3, 1, 32};
    int a = 14, b = 20;

    cout << "\nOriginal Array is ";
    for (int i : vec)
        cout << i << " ";

    threeWayPartitioned(vec, a, b);

    cout << "\nModified Array is ";
    for (int i : vec)
        cout << i << " ";

    cout << endl;
    return 0;
}