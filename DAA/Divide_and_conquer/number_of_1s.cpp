// Given a sorted binary array, efficiently count the total number of 1’s in it.
// For example,
// Input: nums[] = [0, 0, 0, 0, 1, 1, 1]
// Output: The total number of 1’s present is 3
// Input: nums[] = [0, 0, 1, 1, 1, 1, 1]
// Output: The total number of 1’s present is 5

#include <bits/stdc++.h>
using namespace std;

int find(vector<int> &nums, int st, int end)
{
    if (nums[0] == 1)
        return nums.size();
    if (nums[nums.size() - 1] == 0)
        return 0;
    while (st < end)
    {
        int mid = (st + end) / 2;
        if (nums[mid] == 0)
        {
            st = mid + 1;
        }
        else
        {
            end = mid;
        }
    }
    return nums.size() - st;
}

int main()
{
    vector<int> nums = {1};
    int ans = find(nums, 0, nums.size() - 1);
    cout << ans << endl;
    return 0;
}