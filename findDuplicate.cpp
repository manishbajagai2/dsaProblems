/*
Find the Duplicate Number

Given an array of integers nums containing n + 1 integers where each integer is in the range [1, n] inclusive.

There is only one repeated number in nums, return this repeated number.

You must solve the problem without modifying the array nums and uses only constant extra space.

Example 1:

Input: nums = [3,1,3,4,2]
Output: 3

Constraints:

1 <= n <= 105, nums.length == n + 1, 1 <= nums[i] <= n

All the integers in nums appear only once except for precisely one integer which appears two or more times.

*/

#include <bits/stdc++.h>
using namespace std;

// Time Complexity is O(nlogn) and Space Complexity is O(1)
int sorting(vector<int> &nums)
{
    int duplicate = 0;
    sort(nums.begin(), nums.end());
    for (int i = 0; i < nums.size() - 1; i++)
    {
        if (nums[i] == nums[i + 1])
        {
            duplicate = nums[i + 1];
            break;
        }
    }
    return duplicate;
}

// Time Complexity is O(n) but Space Complexity is O(n)
int usingSet(vector<int> &arr)
{
    set<int> s;
    int duplicate = 0;
    for (int i : arr)
    {
        if (s.count(i) != 0)
        {
            duplicate = i;
        }
        s.insert(i);
    }
    return duplicate;
}

// Time Complexity is O(n) and Space Complexity is O(1)
// Since the array elements are in the range of [1,n] inclusive
int usingRange(vector<int> &arr)
{
    int duplicate = 0;
    while (1)
    {
        int x = arr[0];
        if (x != arr[x])
            swap(arr[x], arr[0]);
        else
        {
            duplicate = x;
            break;
        }
    }
    return duplicate;
}

int main()
{
    vector<int> arr = {3, 1, 3, 4, 2};
    cout << "\nDuplicate number by sorting is " << sorting(arr);
    cout << "\nUsing set DS, duplicate number is " << usingSet(arr);
    cout << "\nDuplicate Number within range is " << usingRange(arr);
    cout << endl;
    return 0;
}