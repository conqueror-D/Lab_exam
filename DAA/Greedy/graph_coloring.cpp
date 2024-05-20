// Graph coloring (also called vertex coloring) is a way of coloring a graph’s vertices such that
// no two adjacent vertices share the same color. Implement a greedy algorithm for graph
// coloring and minimize the total number of colors used.

#include <bits/stdc++.h>
using namespace std;

bool isSafe(int color, int curr, vector<int> &colors, vector<vector<int>> &adj, vector<bool> &vis, int prevColor)
{
    if (prevColor == -1)
        return true;
    for (int next : adj[curr])
    {
        if (vis[next] && colors[next] == color)
            return false;
    }
    return true;
}
void color(int curr, int prevColor, vector<int> &colors, vector<vector<int>> &adj, vector<bool> &vis, int n)
{
    vis[curr] = true;
    // Assiging the color to the current node
    for (int i = 1; i <= n; i++)
    {
        if (isSafe(i, curr, colors, adj, vis, prevColor))
        {
            colors[curr] = i;
            prevColor = i;
            break;
        }
    }

    for (int next : adj[curr])
    {
        if (!vis[next])
        {
            color(next, prevColor, colors, adj, vis, n);
        }
    }
}

int colorGraph(vector<vector<int>> &graph, int n)
{

    vector<vector<int>> adj(n, vector<int>());
    // creating a adjacency list
    for (vector<int> curr : graph)
    {
        adj[curr[0]].push_back(curr[1]);
        adj[curr[1]].push_back(curr[0]);
    }
    vector<bool> vis(n, false);
    vector<int> colors(n, -1);
    color(0, -1, colors, adj, vis, n);
    return *max_element(colors.begin(), colors.end());
}

int main()
{
    vector<vector<int>> graph = {{0, 1}, {1, 2}, {2, 3}, {3, 0}, {0, 2}, {1, 3}};
    int n = 6;
    int min = colorGraph(graph, n);
    cout << min << endl;
    return 0;
    // {{0, 1}, {0, 4}, {0, 5}, {5, 4}, {1, 4}, {1, 3}, {4, 2}, {2, 3}}
}