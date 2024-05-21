// Given a sorted array containing duplicates, efficiently find each element’s frequency without
// traversing the whole array. For example,
// Input: [2, 2, 2, 4, 4, 4, 5, 5, 6, 8, 8, 9]
// Output: {2: 3, 4: 3, 5: 2, 6: 1, 8: 2, 9: 1}
// Explanation:
// 2 and 4 occurs thrice
// 5 and 8 occurs twice
// 6 and 9 occurs once

#include <bits/stdc++.h>
using namespace std;

void fillFreq(vector<int> &arr, unordered_map<int, int> &mpp, int st, int end)
{
    if (arr[st] == arr[end])
    {
        mpp[arr[st]] = end - st + 1;
        return;
    }
    int mid = (st + end) / 2;

    fillFreq(arr, mpp, st, mid);
    fillFreq(arr, mpp, mid + 1, end);
}

int main()
{
    unordered_map<int, int> mpp;
    vector<int> arr = {2, 2, 2, 4, 4, 4, 5, 5, 6, 8, 8, 9};
    fillFreq(arr, mpp, 0, arr.size() - 1);
    for (auto it = mpp.begin(); it != mpp.end(); ++it)
    {
        cout << it->first << " " << it->second << endl;
    }
    return 0;
}