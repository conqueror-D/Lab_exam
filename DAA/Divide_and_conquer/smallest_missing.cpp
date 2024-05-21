// Given a sorted array of non-negative distinct integers, find the smallest missing non-negative
// element in it.
// For example,
// Input: nums[] = [0, 1, 2, 6, 9, 11, 15]
// Output: The smallest missing element is 3
// Input: nums[] = [1, 2, 3, 4, 6, 9, 11, 15]
// Output: The smallest missing element is 0
// Input: nums[] = [0, 1, 2, 3, 4, 5, 6]
// Output: The smallest missing element is 7

#include <bits/stdc++.h>
using namespace std;

int check(vector<int> &nums, int st, int mid, int end)
{
    int i = mid, j = mid + 1;
    if (nums[i] + 1 != nums[j])
        return nums[i] + 1;

    return INT_MAX;
}

int findMissing(vector<int> &nums, int st, int end)
{
    if (st == end)
        return INT_MAX;
    int mid = (st + end) / 2;
    int left = findMissing(nums, st, mid);
    int right = findMissing(nums, mid + 1, end);
    int checkBetween = check(nums, st, mid, end);
    return min(left, min(right, checkBetween));
}

int main()
{
    vector<int> nums = {0, 1, 2, 3, 4, 5, 6};
    if (nums[0] != 0)
    {
        cout << nums[0] - 1 << endl;
        return 0;
    }
    int missing = findMissing(nums, 0, nums.size() - 1);
    int ans = missing == INT_MAX ? nums[nums.size() - 1] + 1 : missing;
    cout << ans << endl;
    return 0;
}