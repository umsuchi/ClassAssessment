#include <iostream>
#include <vector>
using namespace std;

void dfs(int v, vector<vector<int>> &adj, vector<bool> &vis){
    vis[v] = true;
    for(int u : adj[v]){
        if(!vis[u])
            dfs(u, adj, vis);
    }
}

bool isConnect(int n, vector<vector<int>> &adj){
    vector<bool> vis(n, false);
    dfs(0, adj, vis);
    for(bool v : vis){
        if(!v) return false;
    }
    return true;
}

int main()
{
    int v, e; 
    cout << "Enter number of vertices and edges: ";cin >> v >> e;
    vector<vector<int>> adj(v);

    cout << "Enter edges (u v): " << endl;
    for(int i=0; i<e; i++){
        int u, w; cin >> u >> w;
        adj[u].push_back(w);
        adj[w].push_back(u);
    }

    if(isConnect(v, adj))
        cout << "The graph is connected." << endl;
    else
        cout << "The graph is not connected." << endl;

    return 0;
}