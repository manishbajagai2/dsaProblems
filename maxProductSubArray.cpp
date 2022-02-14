/*
Maximum Product Subarray

Given an array Arr[] that contains N integers (may be positive, negative or zero). Find the product of the maximum product subarray.

Example 1:

Input:
N = 5
Arr[] = {6, -3, -10, 0, 2}
Output: 180
Explanation: Subarray with maximum product is [6, -3, -10] which gives product as 180.
*/

#include <bits/stdc++.h>
using namespace std;

int maxProduct(vector<int> &vec)
{
    int ans = vec[0], ma = vec[0], mi = vec[0];

    for (int i = 1; i < vec.size(); i++)
    {
        if (vec[i] < 0)
            swap(ma, mi);
        ma = max(vec[i], vec[i] * ma);
        mi = min(vec[i], vec[i] * mi);
        ans = max(ans, ma);
    }
    return ans;
}

int main()
{
    vector<int> vec{6, -3, -10, 0, 2};
    cout << "\nThe maximum product subarray is : ";
    cout << maxProduct(vec) << endl;
    return 0;
}
