/*
Longest consecutive subsequence

Given an array of positive integers. Find the length of the longest sub-sequence such that elements in the subsequence are consecutive integers, the consecutive numbers can be in any order.

Example 1:

Input:
N = 7
a[] = {2,6,1,9,4,5,3}
Output: 6
Explanation:
The consecutive numbers here are 1, 2, 3, 4, 5, 6. These 6 numbers form the longest consecutive subsquence.

*/

#include <bits/stdc++.h>
using namespace std;

int longestConseqSubseq(vector<int> &nums)
{
    unordered_set<int> s;
    for (int i : nums)
        s.insert(i);
    int ans = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        if (s.find(nums[i] - 1) != s.end())
            continue;
        else
        {
            int count = 0, current = nums[i];
            while (s.find(current) != s.end())
            {
                count++;
                current++;
            }
            ans = max(ans, count);
        }
    }
    return ans;
}

int main()
{
    vector<int> vec{2, 6, 1, 9, 4, 5, 3};
    cout << "\nThe longest consecutive sequence is " << longestConseqSubseq(vec) << endl;
    return 0;
}