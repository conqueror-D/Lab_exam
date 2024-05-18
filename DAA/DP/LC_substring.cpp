// The longest common substring problem is the problem of finding the longest string(or strings)
// that is a substring(or are substrings) of two strings.The problem differs from the problem of finding
// the Longest Common Subsequence(LCS)
// Unlike subsequences, substrings are required to occupy consecutive positions within the original string.
// For example,
// The longest common substring of strings ABABC, BABCA is the string BABC having length 4.
// Other common substrings are ABC, A, AB, B, BA, BC, and C.

#include <bits/stdc++.h>
using namespace std;

void LC_substring(string &a, string &b)
{ // lil variation of typical dp
    int n = a.length();
    int m = b.length();
    vector<int> dp(n + 1);
    int ans = 0;
    for (int i = 1; i <= n; i++)
    {
        for (int j = m; j >= 0; j--)
        {
            if (a[i - 1] == b[j - 1])
            {
                dp[j] = 1 + dp[j - 1];
                if (ans < dp[j])
                    ans = dp[j];
            }
            else
                dp[j] = 0;
        }
    }
    cout << ans << endl;
}
int main()
{
    string a = "zxabcdezy";
    string b = "yzabcdezx";
    // string ans = LC_substring(a, b);
    LC_substring(a, b);
    // cout << "Longest common substring of " << a << " and " << b << " is: " << ans << endl;
    return 0;
}