/*
Given an array of intervals where intervals[i] = [starti, endi], merge all overlapping intervals, and return an array of the non-overlapping intervals that cover all the intervals in the input.

Example 1:

Input: intervals = [[1,3],[2,6],[8,10],[15,18]]
Output: [[1,6],[8,10],[15,18]]

Explanation: Since intervals [1,3] and [2,6] overlaps, merge them into [1,6].
*/

#include <bits/stdc++.h>
using namespace std;

struct Interval
{
    int s, e;
};

vector<vector<int>> merge(vector<vector<int>>a)
{
    if (a.size() == 0)
        return a;
    sort(a.begin(), a.end());
    vector<vector<int>> res;
    res.push_back(a[0]);
    int j = 0;
    for (int i = 1; i <= a.size(); i++)
    {
        if (res[j][1] >= a[i][0])
            res[j][1] = max(res[j][1], a[i][1]);
        else
        {
            j++;
            res.push_back(a[i]);
        }
    }
    return res;
}

bool mycomp(Interval a, Interval b)
{ 
    return a.s < b.s; 
}

void mergeIntervals(Interval arr[], int n)
{
    sort(arr, arr+n, mycomp);
    int index = 0;
    for(int i = 1; i < n; i++){
        if(arr[index].e > arr[i].s)
            arr[index].e = max(arr[index].e, arr[i].e);
        else {
			index++;
			arr[index] = arr[i];
		}
    }
    cout << "The Merged Intervals are: ";
	for (int i = 0; i < index; i++)
		cout << "[" << arr[i].s << ", " << arr[i].e << "] , ";
	cout<<"[" << arr[index].s << ", " << arr[index].e << "]" ;
}

int main()
{
    //Time Complexity is O(nlogn) and Space Complexity is O(n)
    vector<vector<int>> a{{1, 3}, {2, 6}, {8, 10}, {15, 18}};
    vector<vector<int>> ans = merge(a);
    for (int i = 0; i < ans.size(); i++)
    {
        for (int j = 0; j < ans[0].size(); j++)
            cout << ans[i][j] << " ";
        cout << " ";
    }
    cout<<endl;

    //Time Complexity is O(nlogn) and Space Complexity is O(1)
    Interval a2[] = {{1, 3}, {2, 6}, {8, 10}, {15, 18}};
	int n = sizeof(a2)/sizeof(a2[0]);
	mergeIntervals(a2, n);
    cout<<endl;
    return 0;
}