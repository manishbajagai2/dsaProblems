/*
Maximum profit by buying and selling a share at most twice

In daily share trading, a buyer buys shares in the morning and sells them on the same day. If the trader is allowed to make at most 2 transactions in a day, whereas the second transaction can only start after the first one is complete (Buy->sell->Buy->sell). Given stock prices throughout the day, find out the maximum profit that a share trader could have made.

Examples:

Input:   price[] = {10, 22, 5, 75, 65, 80}
Output:  87
Trader earns 87 as sum of 12, 75. Buy at 10, sell at 22. Buy at 5 and sell at 80
*/

#include <bits/stdc++.h>
using namespace std;

// Time and Space Complexity are both O(n)
int dpApproach(int prices[], int n)
{
    int dp[n];
    for (int i = 0; i < n; i++)
        dp[i] = 0;
    int ma = prices[n - 1];
    for (int i = n - 2; i >= 0; i--)
    {
        if (prices[i] > ma)
            ma = prices[i];
        dp[i] = max(dp[i + 1], ma - prices[i]);
    }
    int mi = prices[0];
    for (int i = 1; i < n; i++)
    {
        if (prices[i] < mi)
            mi = prices[i];
        dp[i] = max(dp[i - 1], dp[i] + prices[i] - mi);
    }
    return dp[n - 1];
}

// Time and Space Complexity is 0(n) and O(1) respectively.
int secondApproach(int arr[], int n)
{
    int firstBuy = INT_MIN, firstSell = 0;
    int secondBuy = INT_MIN, secondSell = 0;
    for (int i = 0; i < n; i++)
    {
        firstBuy = max(firstBuy, -arr[i]);
        firstSell = max(firstSell, firstBuy + arr[i]);
        secondBuy = max(secondBuy, firstSell - arr[i]);
        secondSell = max(secondSell, secondBuy + arr[i]);
    }
    return secondSell;
}

int main()
{
    int price[] = {10, 22, 5, 75, 65, 80};
    int n = sizeof(price) / sizeof(price[0]);
    cout << "\nThe max profit at most two transaction is " << dpApproach(price, n) << endl;

    cout << "\nThe max profit at most two transaction is " << secondApproach(price, n) << endl;
    cout << endl;
    return 0;
}