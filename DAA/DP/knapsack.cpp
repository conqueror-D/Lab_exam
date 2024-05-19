// 0–1 Knapsack problem
// Input : N = 3,W = 4, profit[] = {1, 2, 3}, weight[] = {4, 5, 1} Output : 3

// Given N items where each item has some weight and profit associated with it and also given a
// bag with capacity W, [i.e., the bag can hold at most W weight in it ].The task is to put the items
// into the bag such that the sum of profits associated with them is the maximum possible.

// Note : The constraint here is we can either put an item completely into the bag or
// cannot put it at all[It is not possible to put a part of an item into the bag].

#include <bits/stdc++.h>
using namespace std;

//                  memoization

// int maximize(int idx, int profit[], int weight[], int w, vector<vector<int>> &dp)
// {
//     if (idx == 0)
//     {
//         if (w > weight[0])
//             return profit[0];
//         return 0;
//     }
//     if (dp[idx][w] != -1)
//         return dp[idx][w];
//     int take = INT_MIN;
//     if (weight[idx] <= w)
//     {
//         take = profit[idx] + maximize(idx - 1, profit, weight, w - weight[idx], dp);
//     }
//     int dontTake = maximize(idx - 1, profit, weight, w, dp);
//     return dp[idx][w] = max(dontTake, take);
// }

int Knapsack(int profit[], int weight[], int w, int n)
{
    // Using 1D array as we only need the previous and current rows
    vector<int> dp(w + 1, 0), curr(w + 1, 0);
    // return maximize(n - 1, profit, weight, w, dp);

    for (int wt = weight[0]; wt <= w; wt++)
    {
        dp[wt] = profit[0];
    }
    for (int idx = 1; idx < n; idx++)
    {
        for (int wt = 0; wt <= w; wt++)
        {
            int take = INT_MIN;
            if (weight[idx] <= wt)
            {
                take = profit[idx] + dp[wt - weight[idx]];
            }
            int dontTake = dp[wt];
            curr[wt] = max(dontTake, take);
            // cout << dp[idx][wt] << " ";
        }
        dp = curr;
    }
    return dp[w];
}

int main()
{
    int profit[] = {1, 2, 3};
    int weight[] = {4, 5, 6};
    int w = 2, n = 3;
    int ans = Knapsack(profit, weight, w, n);
    cout << "Maixmum possible profit achievable: " << ans << endl;
    return 0;
}
