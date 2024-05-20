// Find the maximum sum of a subsequence with no adjacent elements.
// Given an integer array, find the maximum sum of subsequence where the subsequence
// contains no element at adjacent positions.
// Please note that the problem specifically targets subsequences that need not be contiguous,
// i.e., subsequences are not required to occupy consecutive positions within the original
// sequences.
// For example,
// Input: { 1, 2, 9, 4, 5, 0, 4, 11, 6 }
// Output: The maximum sum is 26
// The maximum sum is formed by subsequence { 1, 9, 5, 11 }

#include <bits/stdc++.h>
using namespace std;

//                  Memoization
// int maximize(int idx, bool safe, vector<int> &arr, vector<vector<int>> &dp)
// {
//     if (idx == 0)
//     {
//         if (safe)
//             return arr[0];
//         return 0;
//     }
//     if (dp[idx][safe] != -1)
//         return dp[idx][safe];
//     int dontTake = maximize(idx - 1, true, arr, dp);
//     int take = INT_MIN;
//     if (safe)
//         take = arr[idx] + maximize(idx - 1, !safe, arr, dp);

//     return dp[idx][safe] = max(dontTake, take);
// }
int maxSum(vector<int> &arr)
{
    int n = arr.size();
    // Just need previous two states that is if the previous element has been picked or not picked yet.
    int prevFalse = 0, prevTrue = 0, currTrue = 0, currFalse = 0;
    // return maximize(arr.size() - 1, true, arr, dp);
    prevTrue = arr[0];

    for (int idx = 1; idx < n; idx++)
    {
        for (int safe = 0; safe <= 1; safe++)
        {
            int dontTake = prevTrue;
            int take = INT_MIN;
            if (safe)
                take = arr[idx] + prevFalse;

            if (safe)
            {
                currTrue = max(dontTake, take);
            }
            else
            {
                currFalse = max(dontTake, take);
            }
        }
        prevFalse = currFalse;
        prevTrue = currTrue;
    }

    return max(prevFalse, prevTrue);
}
int main()
{
    vector<int> arr = {1, -5, 3};
    int ans = maxSum(arr);
    cout << ans << endl;
    return 0;
}