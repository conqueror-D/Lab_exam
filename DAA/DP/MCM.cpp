// Matrix Chain Multiplication using Dynamic Programming
// (10x100), (100x5), (5x500)minimum cost is 5000

// Given a sequence of matrices, find the most efficient way to multiply these matrices together.
// The efficient way is the one that involves the least number of multiplications.
// The dimensions of the matrices are given in an array arr[] of size N
// (such that N = number of matrices + 1) where the ith matrix has the dimensions (arr[i-1] x arr[i]).

// Input : N = 5 arr = {40, 20, 30, 10, 30} Output : 26000
// Explanation : There are 4 matrices of dimension 40x20, 20x30, 30x10, 10x30.
// Say the matrices are named as A, B, C, D.Out of all possible combinations,
// the most efficient way is(A *(B *C)) *D.The number of operations are -
//      20 * 30 * 10 + 40 * 20 * 10 + 40 * 10 * 30 = 26000.

#include <bits/stdc++.h>
using namespace std;

// Memoization
//  int find(vector<int> &matrices, int i, int j, vector<vector<int>> &dp)
//  {
//      if (i == j)
//          return 0;
//      if (dp[i][j] != -1)
//          return dp[i][j];
//      int mini = INT_MAX;
//      for (int k = i; k < j; k++)
//      {
//          int curr = matrices[i - 1] * matrices[k] * matrices[j] + find(matrices, i, k, dp) + find(matrices, k + 1, j, dp);
//          mini = min(mini, curr);
//      }
//      return dp[i][j] = mini;
//  }

int MCM(vector<int> &matrices)
{
    int m = matrices.size();
    vector<vector<int>> dp(m, vector<int>(m, -1));
    // int ans = find(matrices, i, j, dp);
    for (int i = 0; i < m; i++)
        dp[i][i] = 0;
    for (int i = m - 1; i >= 1; i--)
    {
        for (int j = i + 1; j < m; j++)
        {
            int ans = INT_MAX;
            for (int k = i; k < j; k++)
            {
                int curr = matrices[i - 1] * matrices[k] * matrices[j] + dp[i][k] + dp[k + 1][j];
                ans = min(ans, curr);
            }
            dp[i][j] = ans;
        }
    }
    return dp[1][m - 1];
}
int main()
{
    vector<int> matrices = {40, 20, 30, 10, 30};
    int minOperations = MCM(matrices);
    cout << minOperations << " are the minimum number of operations required" << endl;
    return 0;
}