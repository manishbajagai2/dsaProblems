/*
Given an array of size n and a number k, find all elements that appear more than n/k times

For example, if the input arrays is {3, 1, 2, 2, 1, 2, 3, 3} and k is 4, then the output should be [2, 3]. Note that size of array is 8 (or n = 8), so we need to find all e

*/

#include <bits/stdc++.h>
using namespace std;

// Time complexity is O(n^2) and space Complexity is O(n)
void countingApproach(int arr[], int n, int k)
{
    int countingTo = n / k;
    int visited[n];
    for (int i = 0; i < n; i++)
    {
        if (visited[i] != 1)
        {
            int count = 1;
            for (int j = i + 1; j < n; j++)
            {
                if (arr[i] == arr[j])
                {
                    count++;
                    visited[j] = 1;
                }
            }
            if (count > countingTo)
                cout << arr[i] << " ";
        }
    }
}

// Time Complexity is O(nlogn) and Space Complexity is O(1)
void sortingApproach(int arr[], int n, int k)
{
    int countTo = n / k;
    sort(arr, arr + n);
    int count = 1;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == arr[i + 1])
            count++;
        else if (count > countTo)
        {
            cout << arr[i] << " ";
            count = 1;
        }
        else
            continue;
    }
    cout << endl;
}

// Time Complexity is O(n) and Space Complexity is O(n)
void usingMapFreq(int arr[], int n, int k){
    int countTo = n / k;
    unordered_map<int, int>mp;
    for(int i = 0; i < n; i++)
        mp[arr[i]]++;
    for(auto it : mp){
        if(it.second > countTo)
            cout<<it.first<<" ";
    }
}

int main()
{
    int arr[] = {3, 1, 2, 2, 1, 2, 3, 3};
    int n = sizeof(arr) / sizeof(arr[0]);
    int k = 4;

    cout << "\nUsing Counting, elements more than n/k are ";
    countingApproach(arr, n, k);
    cout << endl;

    cout << "\nUsing Sorting, elements more than n/k are ";
    sortingApproach(arr, n, k);

    cout << "\nUsing Map DS, elements more than n/k are ";
    usingMapFreq(arr, n, k);
    cout << endl;

    return 0;
}