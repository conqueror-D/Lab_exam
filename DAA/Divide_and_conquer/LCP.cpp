// Write an efficient algorithm to find the longest common prefix (LCP) between a given set of
// strings.
// For example,
// Input: technique, technician, technology, technical
// Output: The longest common prefix is techn
// Input: techie delight, tech, techie, technology, technical
// Output: The longest common prefix is tech
#include <bits/stdc++.h>
using namespace std;

string lcp(string &s1, string &s2)
{
    string ans = "";
    for (int i = 0; i < s1.length(); i++)
    {
        if (s1[i] != s2[i])
            break;
        ans += s1[i];
    }
    return ans;
}

string find(vector<string> &arr, int st, int end)
{
    if (st == end)
        return arr[st];
    int mid = (st + end) / 2;

    string s1 = find(arr, st, mid);
    string s2 = find(arr, mid + 1, end);

    return lcp(s1, s2);
}

int main()
{
    vector<string> arr = {"techie delight", "tech", "techie", "technology", "technical"};
    string pref = find(arr, 0, arr.size() - 1);
    cout << "The longest common prefix is: " << pref << endl;
    return 0;
}