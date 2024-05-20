// This algorithm always starts with a single node and moves through several adjacent nodes,
// in order to explore all of the connected edges along the way.
// The algorithm starts with an empty spanning tree. The idea is to maintain two sets of vertices.
// The first set contains the vertices already included in the MST, and the other set contains the
// vertices not yet included. At every step, it considers all the edges that connect the two sets and
// picks the minimum weight edge from these edges. After picking the edge, it moves the other endpoint of
// the edge to the set containing MST.

#include <bits/stdc++.h>
using namespace std;

struct compare
{
    bool operator()(const pair<int, int> p1, const pair<int, int> p2) const
    {
        return p1.second > p2.second;
    }
};

int prims(vector<vector<int>> &graph, int v)
{
    vector<vector<pair<int, int>>> adj(v, vector<pair<int, int>>());
    // Constructing the adjacency list
    for (vector<int> edge : graph)
    {
        adj[edge[0]].push_back(make_pair(edge[1], edge[2]));
        adj[edge[1]].push_back(make_pair(edge[0], edge[2]));
    }

    int mst = 0;
    vector<bool> taken(v);
    priority_queue<pair<int, int>, vector<pair<int, int>>, compare> pq;
    pq.push(make_pair(0, 0));

    while (!pq.empty())
    {
        pair curr = pq.top();
        pq.pop();

        int vertex = curr.first;
        if (taken[vertex])
            continue;
        mst += curr.second;
        taken[vertex] = true;

        for (pair<int, int> p : adj[vertex])
        {
            if (!taken[p.first])
            {
                pq.push(make_pair(p.first, p.second));
            }
        }
    }
    return mst;
}
int main()
{
    //{0, 1, 4}, {0, 7, 6}, {1, 7, 11}, {1, 2, 8}, {2, 8, 2}, {8, 7, 7}, {8, 6, 6}, {7, 6, 1}, {6, 5, 2}, {2, 5, 4}, {2, 3, 7}, {3, 5, 14}, {3, 4, 9}, {4, 5, 10}
    vector<vector<int>> graph = {{0, 1, 4}, {0, 7, 6}, {1, 7, 11}, {1, 2, 8}, {2, 8, 2}, {8, 7, 7}, {8, 6, 6}, {7, 6, 1}, {6, 5, 2}, {2, 5, 4}, {2, 3, 7}, {3, 5, 14}, {3, 4, 9}, {4, 5, 10}};
    int v = 9;

    int MST = prims(graph, v);
    cout << MST << endl;
    return 0;
}