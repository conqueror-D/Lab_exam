// The Longest Common Subsequence (LCS) problem is finding the longest subsequence
// present in given two sequences in the same order, i.e., find the longest sequence which can be
// obtained from the first original sequence by deleting some items and from the second original
// sequence by deleting other items.
// The problem differs from the problem of finding the longest common substring. Unlike
// substrings, subsequences are not required to occupy consecutive positions within the original
// string.
// For example, consider the two following sequences, X and Y:
// X: ABCBDAB
// Y: BDCABA
// The length of the LCS is 4
// LCS are BDAB, BCAB, and BCBA

#include <bits/stdc++.h>
using namespace std;

int memoize(string &a, string &b, int i, int j, vector<vector<int>> &dp)
{
    if (i < 0 || j < 0)
        return 0;

    if (dp[i][j] != -1)
        return dp[i][j];
    if (a[i] == b[j])
    {
        return dp[i][j] = 1 + memoize(a, b, i - 1, j - 1, dp);
    }

    return dp[i][j] = max(memoize(a, b, i - 1, j, dp), memoize(a, b, i, j - 1, dp));
}
string LCS(string &a, string &b)
{
    int i = a.length() - 1;
    int j = b.length() - 1;
    vector<vector<int>> dp(i + 1, vector<int>(j + 1, -1));
    // If the problem is to print the LCS the solution cannot be space optimized
    // as the whole n*m dp array will be needed to print the LCS

    memoize(a, b, i, j, dp);
    for (int x = 0; x <= i; x++)
    {
        for (int y = 0; y < j + 1; y++)
        {
            cout << dp[x][y] << " ";
        }
        cout << endl;
    }
    string ans = "";
    int x = a.length() - 1, y = b.length() - 1;
    cout << x << " " << y << endl;
    while (x >= 0 && y >= 0)
    {
        cout << a[x] << b[y] << endl;
        if (a[x] == b[y])
        {
            ans += a[x];
            x--, y--;
        }
        else
        {
            if (dp[x][y - 1] >= dp[x - 1][y])
            {
                y--;
            }
            else
            {
                x--;
            }
        }
    }

    cout << "Length of LCS: " << dp[a.length() - 1][b.length() - 1] << endl;
    reverse(ans.begin(), ans.end());
    return ans;
}
int main()
{
    string a = "ABCBDAB";
    string b = "BDCABA";

    string ans = LCS(a, b);
    cout << "The longest common subsequence of the strings " << a << " and " << b << " is " << ans << endl;
    return 0;
}