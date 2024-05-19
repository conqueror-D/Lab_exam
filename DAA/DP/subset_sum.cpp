// Subset Sum Problem – Dynamic Programming Solution
//     Given a set of positive integers and an integer k,
//     check if there is any non - empty subset that sums to k.For example,
//     Input : A = {7, 3, 2, 5, 8} k = 14 Output : Subset with the given sum exists Subset{7, 2, 5} sums to 14

#include <bits/stdc++.h>
using namespace std;

//              Memoization
// bool find(int idx, int k, vector<int> &arr, vector<vector<int>> &dp)
// {
//     if (k == 0)
//         return true;
//     if (k < 0)
//         return false;
//     if (idx == 0)
//         return arr[0] == k;
//     if (dp[idx][k] != -1)
//         return dp[idx][k];
//     int dontTake = find(idx - 1, k, arr, dp);
//     int take = false;
//     if (arr[idx] <= k)
//         take = find(idx - 1, k - arr[idx], arr, dp);
//     return dp[idx][k] = dontTake || take;
// }

// Space optimization
bool subset_sum(vector<int> &arr, int k)
{
    vector<int> dp(k + 1, 0), curr(k + 1, 0);
    // return find(arr.size() - 1, k, arr, dp);

    for (int i = 0; i < arr.size(); i++)
        dp[0] = true;
    if (arr[0] <= k)
    {
        dp[arr[0]] = true;
    }

    for (int i = 1; i < arr.size(); i++)
    {
        for (int j = 0; j <= k; j++)
        {
            int dontTake = dp[j];
            int take = false;
            if (arr[i] <= j)
                take = dp[j - arr[i]];
            curr[j] = dontTake || take;
        }
        dp = curr;
    }

    return dp[k];
}
int main()
{
    vector<int> arr = {11, 4, 4, 12, 5, 2};
    int k = 9;
    bool ans = subset_sum(arr, k);
    if (ans)
    {
        cout << "Subset does exist" << endl;
    }
    else
    {
        cout << "Subset does not exist" << endl;
    }
    return 0;
}