/*
Given three arrays sorted in increasing order. Find the elements that are common in all three arrays.
Note: can you take care of the duplicates without using any additional Data Structure?

Example 1:

Input:
n1 = 6; A = {1, 5, 10, 20, 40, 80}
n2 = 5; B = {6, 7, 20, 80, 100}
n3 = 8; C = {3, 4, 15, 20, 30, 70, 80, 120}
Output: 20 80
Explanation: 20 and 80 are the only common elements in A, B and C.

*/
#include <bits/stdc++.h>
using namespace std;

vector<int> commonEles(int A[], int B[], int C[], int n1, int n2, int n3)
{
    unordered_map<int, int> m1, m2, m3;

    for (int i = 0; i < n1; i++)
        m1[A[i]]++;

    for (int i = 0; i < n2; i++)
        m2[B[i]]++;

    for (int i = 0; i < n3; i++)
        m3[C[i]]++;
    vector<int> ans;

    for (int i = 0; i < n1; i++)
    {
        if (m1[A[i]] and m2[A[i]] and m3[A[i]])
            ans.push_back(A[i]);
    }
    return ans;
}

vector<int> commonElements(int A[], int B[], int C[], int n1, int n2, int n3)
{
    int i = 0, j = 0, k = 0;
    vector<int> ans;
    int zero_index_flag = 0;

    while ((i < n1) && (j < n2) && (k < n3))
    {
        int a = A[i];
        int b = B[j];
        int c = C[k];

        if (a == b && a == c)
        {
            if (zero_index_flag == 0)
            {
                ans.push_back(c);
                zero_index_flag = 1;
            }
            else
            {
                if (ans.back() != c)
                    ans.push_back(c);
            }
        }
        if (a <= b && a <= c)
            i++;
        if (b <= a && b <= c)
            j++;
        if (c <= b && c <= a)
            k++;
    }

    return ans;
}

int main()
{
    int A[] = {1, 5, 10, 20, 40, 80};
    int B[] = {6, 7, 20, 80, 100};
    int C[] = {3, 4, 15, 20, 30, 70, 80, 120};
    int n1 = 6, n2 = 5, n3 = 8;
    cout << "\nCommon elements are : ";
    vector<int> res1 = commonElements(A, B, C, n1, n2, n3);
    for (int i : res1)
        cout << i << " ";
    cout << endl;

    cout << "\nCommon elements are : ";
    vector<int> res2 = commonEles(A, B, C, n1, n2, n3);
    for (int i : res2)
        cout << i << " ";
    cout << endl;
    return 0;
}