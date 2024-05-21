// Given a sorted integer array, find the k closest elements to target in the array where k and
// target are given positive integers.
// The target may or may not be present in the input array. If target is less than or equal to
// the first element in the input array, return first k elements. Similarly, if target is more than
// or equal to the last element in the input array, return the last k elements. The returned
// elements should be in the same order as present in the input array. For example,
// Input: [10, 12, 15, 17, 18, 20, 25], k = 4, target = 16
// Output: [12, 15, 17, 18]
// Input: [2, 3, 4, 5, 6, 7], k = 3, target = 1
// Output: [2, 3, 4]
// Input: [2, 3, 4, 5, 6, 7], k = 2, target = 8
// Output: [6, 7]

#include <bits/stdc++.h>
using namespace std;

vector<int> findKClosest(vector<int> &nums, int k, int target, int st, int end)
{

    int left = st, right = end;

    while (right - left >= k)
    {
        if (abs(nums[left] - target) > abs(nums[right] - target))
            left++;
        else
            right--;
    }
    vector<int> ans;
    while (left <= right)
    {
        ans.push_back(nums[left++]);
    }
    return ans;
}

int main()
{
    vector<int> arr = {2, 3, 4, 5, 6, 7};
    int k = 3;
    int target = 8;
    vector<int> ans = findKClosest(arr, k, target, 0, arr.size() - 1);
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }
    return 0;
}