// Given an array, find the total number of inversions of it. If (i < j) and (A[i] >
// A[j]), then pair (i, j) is called an inversion of an array A. We need to count all such
// pairs in the array. For example,
// Input: A[] = [1, 9, 6, 4, 5]
// Output: The inversion count is 5
// There are 5 inversions in the array: (9, 6), (9, 4), (9, 5), (6, 4), (6, 5)

#include <bits/stdc++.h>
using namespace std;

int merge(vector<int> &arr, int st, int mid, int end)
{
    vector<int> temp = arr;
    int cnt = 0;
    int i = st, j = mid + 1;
    while (i <= mid && j <= end)
    {
        if (arr[i] > arr[j])
        {
            cnt += mid - i + 1;
            swap(temp[i], temp[j++]);
        }
        else
        {
            i++;
        }
    }
    arr = temp;
    return cnt;
}

int inversionCnt(vector<int> &arr, int st, int end)
{
    if (st == end)
        return 0;
    int mid = (st + end) / 2;
    int cnt1 = inversionCnt(arr, st, mid);
    int cnt2 = inversionCnt(arr, mid + 1, end);
    int mergeCnt = merge(arr, st, mid, end);

    return cnt1 + cnt2 + mergeCnt;
}
int main()
{
    vector<int> arr = {1, 2, 3, 4, 5, 6, 7};
    int cnt = inversionCnt(arr, 0, arr.size() - 1);
    cout << cnt << endl;
    return 0;
}