// Rod Cutting Problem
// Given a rod of length n and a list of rod prices of length i, where 1 <= i <= n, find the
// optimal way to cut the rod into smaller rods to maximize profit.
// For example, consider the following rod lengths and values:
// Input:
// length[] = [1, 2, 3, 4, 5, 6, 7, 8]
// price[] = [1, 5, 8, 9, 10, 17, 17, 20]
// Rod length: 4
// Best: Cut the rod into two pieces of length 2 each to gain revenue of 5 + 5 = 10

#include <bits/stdc++.h>
using namespace std;

//              Memoization
// int maximize(int idx, vector<int> &len, vector<int> &prices, int rodLen, vector<vector<int>> &dp)
// {
//     if (rodLen < 1)
//         return 0;
//     if (idx == 0)
//     {
//         return prices[0] * rodLen;
//     }
//     if (idx < 0)
//         return 0;
//     if (dp[idx][rodLen] != -1)
//         return dp[idx][rodLen];
//     int dontTake = maximize(idx - 1, len, prices, rodLen, dp);
//     int take = INT_MIN;
//     if (len[idx] <= rodLen)
//         take = prices[idx] + maximize(idx, len, prices, rodLen - len[idx], dp);
//     return dp[idx][rodLen] = max(dontTake, take);
// }

int cutTheRod(vector<int> &len, vector<int> &prices, int k)
{
    vector<vector<int>> dp(prices.size(), vector<int>(k + 1, 0));
    // return maximize(len.size() - 1, len, prices, rodLen, dp);
    for (int j = 1; j <= k; j++)
    {
        dp[0][j] = prices[0] * j;
    }

    for (int idx = 1; idx < prices.size(); idx++)
    {
        for (int rodLen = 1; rodLen <= k; rodLen++)
        {
            int dontTake = dp[idx - 1][rodLen];
            int take = INT_MIN;
            if (len[idx] <= rodLen)
                take = prices[idx] + dp[idx][rodLen - len[idx]];
            dp[idx][rodLen] = max(dontTake, take);
        }
    }
    return dp[prices.size() - 1][k];
}

int main()
{
    vector<int> len = {1, 2, 3, 4, 5, 6, 7, 8};
    vector<int> prices = {3, 5, 8, 9, 10, 17, 17, 20};
    int rodLen = 8;
    int ans = cutTheRod(len, prices, rodLen);
    cout << ans << endl;
    return 0;
}