#include <bits/stdc++.h>
using namespace std;
class disjoint_set
{
public:
    vector<int> rank, ult_parent;
    disjoint_set(int n)
    {
        rank.resize(n + 1, 0);
        ult_parent.resize(n + 1);
        for (int i = 1; i <= n; i++)
            ult_parent[i] = i;
    }
    int findUParent(int node)
    {
        if (ult_parent[node] == node)
            return node;
        return ult_parent[node] = findUParent(ult_parent[node]);
    }

    void UnionByRank(int u, int v)
    {
        int upu = findUParent(u);
        int upv = findUParent(v);
        if (upu == upv)
            return;
        if (rank[upu] < rank[upv]) // v ka rank zayada h, to usko baap banao
        {
            ult_parent[upu] = upv;
        }
        else if (rank[upu] > rank[upv])
        {
            ult_parent[upv] = upu;
        }
        else
        {
            ult_parent[upv] = upu;
            rank[upu]++;
        }
    }
};
vector<pair<int, pair<int, int>>> kruskalMinTree(int n, vector<pair<int, pair<int, int>>> adj)
{
    // vector<pair<int, pair<int, int>>>
    //             w         u     v
    vector<pair<int, pair<int, int>>> result;
    disjoint_set ds(n);
    sort(adj.begin(), adj.end()); // sorting on basis of weight
    for (auto it : adj)
    {
        int w = it.first;
        int u = it.second.first;
        int v = it.second.second;
        if (ds.findUParent(u) != ds.findUParent(v))
        {
            result.push_back({w, {u, v}});
            ds.UnionByRank(u, v);
        }
    }
    return result;
}
int main()
{
    cout << "E: ";
    int e;
    cin >> e;
    cout << "V: ";
    int n;
    cin >> n;
    int u, v, w;
    vector<pair<int, pair<int, int>>> adj; // adjacency list
    for (int i = 0; i < e; i++)
    {
        cin >> u >> v >> w;
        adj.push_back({w, {u, v}});
    }
    vector<pair<int, pair<int, int>>> ans = kruskalMinTree(n, adj);
    int weight = 0;
    cout << "Edges in the min spanning tree: \n";
    for (auto it : ans)
    {
        weight += it.first;
        cout << it.second.first << " " << it.second.second << " " << it.first << endl;
    }
    cout << "Sum of weights : " << weight;
}