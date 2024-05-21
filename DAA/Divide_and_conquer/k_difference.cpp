// Given an unsorted integer array, find all pairs with a given difference k in it without using
// any extra space.
// For example,
// Input:
// arr = [1, 5, 2, 2, 2, 5, 5, 4]
// k = 3
// Output:
// (2, 5) and (1, 4)

#include <bits/stdc++.h>
using namespace std;

bool bs(vector<int> &arr, int b, int e, int t)
{
    int i = b, j = e;

    while (i <= j)
    {
        int mid = (i + j) / 2;
        if (arr[mid] == t)
            return true;
        else if (arr[mid] > t)
            j = mid - 1;
        else
            i = mid + 1;
    }
    return false;
}

int main()
{
    // TC: nlogn SC: O(1)
    vector<int> arr = {1, 5, 2, 2, 2, 5, 5, 4};
    int k = 1;
    int n = arr.size();
    sort(arr.begin(), arr.end());
    int prev = -1;
    for (int i = 0; i < n; i++)
    {
        int num = arr[i];
        if (num == prev)
            continue;
        prev = num;
        int t = arr[i] + k;
        if (bs(arr, i + 1, n, t))
        {
            cout << num << " " << t << endl;
        }
    }
    return 0;
}