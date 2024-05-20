// Knowledge of Disjoint set(Union find) data structure is necessary for understanding this shit.
#include <bits/stdc++.h>
using namespace std;

class Disjointset
{
public:
    vector<int> parent;
    Disjointset(int _v)
    {
        parent.resize(_v);
        for (int i = 0; i < _v; i++)
        {
            parent[i] = i;
        }
    }

    int findParent(int u)
    {
        if (parent[u] == u)
            return u;
        return parent[u] = findParent(parent[u]);
    }

    void insert(int pu, int pv)
    {
        if (pu > pv)
        {
            parent[pv] = pu;
        }
        else
        {
            parent[pu] = pv;
        }
    }
};
struct compare
{
    bool operator()(const pair<int, pair<int, int>> p1, const pair<int, pair<int, int>> p2) const
    {
        return p1.first > p2.first;
    }
};

int kruskals(vector<vector<int>> &graph, int v)
{
    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, compare> pq;
    Disjointset ds(v);
    for (int i = 0; i < graph.size(); i++)
        pq.push(make_pair(graph[i][2], make_pair(graph[i][0], graph[i][1])));

    int mst = 0;
    while (!pq.empty())
    {
        pair curr = pq.top();
        pq.pop();

        int u = curr.second.first;
        int v = curr.second.second;

        int pu = ds.findParent(u);
        int pv = ds.findParent(v);
        if (pu == pv)
            continue;
        mst += curr.first;
        ds.insert(pu, pv);
    }
    return mst;
}

int main()
{
    //{0, 1, 4}, {0, 7, 6}, {1, 7, 11}, {1, 2, 8}, {2, 8, 2}, {8, 7, 7}, {8, 6, 6}, {7, 6, 1}, {6, 5, 2}, {2, 5, 4}, {2, 3, 7}, {3, 5, 14}, {3, 4, 9}, {4, 5, 10}
    vector<vector<int>> graph = {{0, 1, 5}, {1, 2, 3}, {0, 2, 1}};
    int v = 9;

    int MST = kruskals(graph, v);
    cout << MST << endl;
    return 0;
}