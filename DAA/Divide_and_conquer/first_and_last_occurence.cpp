// Given a sorted integer array, find the index of a given number’s first or last occurrence. If the
// element is not present in the array, report that as well.
// For example,
// Input:
// nums = [2, 5, 5, 5, 6, 6, 8, 9, 9, 9]
// target = 5
// Output:
// The first occurrence of element 5 is located at index 1
// The last occurrence of element 5 is located at index 3
// Input:
// nums = [2, 5, 5, 5, 6, 6, 8, 9, 9, 9]
// target = 4

#include <bits/stdc++.h>
using namespace std;
int binarySearch(vector<int> &nums, int k, bool findFirst)
{
    int st = 0, end = nums.size() - 1;
    int result = -1;

    while (st <= end)
    {
        int mid = st + (end - st) / 2;

        if (nums[mid] == k)
        {
            result = mid;
            if (findFirst)
            {
                end = mid - 1;
            }
            else
            {
                st = mid + 1;
            }
        }
        else if (nums[mid] < k)
        {
            st = mid + 1;
        }
        else
        {
            end = mid - 1;
        }
    }

    return result;
}

int main()
{
    vector<int> nums = {};
    int k = 0;
    int first = binarySearch(nums, k, true);
    int last = binarySearch(nums, k, false);
    cout << "First occurence of " << k << " is at index " << first << endl;
    cout << "Last occurence of " << k << " is at index " << last << endl;
    return 0;
}