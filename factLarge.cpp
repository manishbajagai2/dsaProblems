/*
Factorials of large numbers

Given an integer N, find its factorial.

Example 1:

Input: N = 10
Output: 3628800
Explanation :
10! = 1*2*3*4*5*6*7*8*9*10 = 3628800

*/

#include <bits/stdc++.h>
using namespace std;

vector<int> factorial(int n){
    vector<int>ans;
    ans.push_back(1);
    for(int i = 2; i<=n; i++){
        int carry = 0;
        for(int d = 0; d<ans.size(); d++){
            int val = ans[d] * i + carry;
            ans[d] = val % 10;
            carry = val / 10;
        }
        while(carry != 0){
            ans.push_back(carry % 10);
            carry /= 10;
        }
    }
    reverse(ans.begin(), ans.end());
    return ans;
}

int main()
{
    int n = 10;
    vector<int>res = factorial(n);
    cout<<"\nThe factorial of "<<n<<" is : ";
    for(int i = 0; i<res.size(); i++)
        cout<<res[i];
    cout<<endl;
    return 0;
}