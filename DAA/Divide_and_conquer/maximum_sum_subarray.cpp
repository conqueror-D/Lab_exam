// Given an integer array, find the maximum sum among all subarrays possible.
// The problem differs from the problem of finding the maximum subsequence sum. Unlike
// subsequences, subarrays are required to occupy consecutive positions within the original
// array. For example,
// Input: nums[] = [2, -4, 1, 9, -6, 7, -3]
// Output: The maximum sum of the subarray is 11 (Marked in Green)

#include <bits/stdc++.h>
using namespace std;

int findCross(vector<int> &arr, int st, int mid, int end)
{

    int sum = 0;
    int leftSum = INT_MIN;
    for (int i = mid; i >= st; i--)
    {
        sum += arr[i];
        if (sum > leftSum)
            leftSum = sum;
    }

    sum = 0;
    int rightSum = INT_MIN;
    for (int i = mid + 1; i <= end; i++)
    {
        sum += arr[i];
        if (sum > rightSum)
            rightSum = sum;
    }
    return max(leftSum, max(rightSum, leftSum + rightSum));
}

int find(vector<int> &arr, int st, int end)
{
    if (st == end)
        return arr[st];
    int mid = (st + end) / 2;

    int left = find(arr, st, mid);
    int right = find(arr, mid + 1, end);
    int cross = findCross(arr, st, mid, end);

    return max(left, max(right, cross));
}
int main()
{
    vector<int> arr = {5, 4, -1, 7, 8};
    int sum = find(arr, 0, arr.size() - 1);
    cout << sum << endl;
    return 0;
}