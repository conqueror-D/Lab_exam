// Optimal BST
// Input:  keys[] = {10, 12}, freq[] = {34, 50}
// There can be following two possible BSTs
//         10                       12
//           \                     /
//            12                 10
//           I                     II
// Frequency of searches of 10 and 12 are 34 and 50 respectively.
// The cost of tree I is 34*1 + 50*2 = 134
// The cost of tree II is 50*1 + 34*2 = 118

// Input:  keys[] = {10, 12, 20}, freq[] = {34, 8, 50}
// There can be following possible BSTs
//     10                12                 20         10              20
//       \             /    \              /             \            /
//       12          10     20           12               20         10
//         \                            /                 /           \
//          20                        10                12             12
//      I               II             III             IV             V
// Among all possible BSTs, cost of the fifth BST is minimum.
// Cost of the fifth BST is 1*50 + 2*34 + 3*8 = 142

// Fucking loved the problem

#include <bits/stdc++.h>
using namespace std;

int OBST(vector<int> &keys, vector<int> &freq)
{
    int n = keys.size();

    vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));
    // Filling the initial cost of creating a BST with only single elements
    for (int i = 1; i <= n; i++)
    {
        dp[i - 1][i] = freq[i - 1];
    }

    for (int diff = 2; diff <= n; diff++)
    { // For difference of j and i
        for (int j = diff; j <= n; j++)
        {
            int i = j - diff;
            int sum = 0;
            for (int k = i; k < j; k++)
                sum += freq[k];
            int mini = INT_MAX;
            for (int cnt = 0; cnt < diff; cnt++)
            {
                mini = min(mini, dp[i][i + cnt] + dp[i + cnt + 1][j] + sum);
            }
            dp[i][j] = mini;
        }
    }
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= n; j++)
        {
            cout << dp[i][j] << " ";
        }
        cout << endl;
    }

    return dp[0][n];
}
int main()
{
    vector<int> keys = {10, 20, 30, 40}, freq = {4, 2, 6, 3};
    int ans = OBST(keys, freq);
    cout << "Optimal cost is: " << ans << endl;
    return 0;
}