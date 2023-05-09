#include <bits/stdc++.h>
using namespace std;
vector<int> dijkstra(int n, map<int, vector<pair<int, int>>> adj, int s)
{
    set<pair<int, int>> st;
    //        w  node
    vector<bool> vis(n + 1, false);
    vector<int> dist(n + 1, INT_MAX);
    vector<int> parent(n + 1, -1);

    dist[s] = 0;
    st.insert({0, s});
    while (st.size() > 0)
    {
        auto node = *st.begin();
        st.erase(st.begin()); // remove from set and unpack pair
        int v = node.second;
        int w = node.first;
        // skip already visited nodes
        if (vis[v])
            continue;
        // set visited
        vis[v] = true;
        // for all adj nodes of v
        for (auto it : adj[v])
        {
            // unpack adjacent node u
            int child_v = it.first;
            int wt = it.second;
            //    dist[u]     > dist[v] + weight[u,v]
            // agar yaha se jaake weight kam mila toh overwrite
            if (dist[child_v] > dist[v] + wt)
            {

                dist[child_v] = dist[v] + wt;
                parent[child_v] = v;
                st.insert({dist[child_v], child_v});
            }
        }
    }
    return parent;
}
void print_sp(int v, vector<int> parent)
{
    if (parent[v] == -1) // source
        return;
    print_sp(parent[v], parent);
    cout << "->" << v;
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
    map<int, vector<pair<int, int>>> adj; // adjacency list
    for (int i = 0; i < e; i++)
    {
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }
    vector<int> ans = dijkstra(n, adj, 1);
    for (int i = 1; i < n + 1; i++)
    {
        // cout << "Distance from " << i << " = " << ans[i] << endl;
        cout << 1;
        print_sp(i, ans);
        cout << endl;
        // cout << ans[i];
    }
}