#include <iostream>
#include <vector>
#include <stack>
#include <set>
using namespace std;

void dfs1(int u, vector<vector<int>>& adj, vector<bool>& visited, stack<int>& finishStack) {
    visited[u] = true;
    for (int v : adj[u])
        if (!visited[v]) dfs1(v, adj, visited, finishStack);
    finishStack.push(u);
}

void dfs2(int u, vector<vector<int>>& rev, vector<bool>& visited, vector<int>& comp, int id) {
    visited[u] = true;
    comp[u] = id;
    for (int v : rev[u])
        if (!visited[v]) dfs2(v, rev, visited, comp, id);
}

int minEdgesToMakeStronglyConnected(int V, vector<vector<int>>& adj) {
    vector<vector<int>> rev(V);
    for (int u = 0; u < V; ++u)
        for (int v : adj[u])
            rev[v].push_back(u);

    vector<bool> visited(V, false);
    stack<int> finishStack;
    for (int i = 0; i < V; ++i)
        if (!visited[i]) dfs1(i, adj, visited, finishStack);

    fill(visited.begin(), visited.end(), false);
    vector<int> component(V);
    int compID = 0;

    while (!finishStack.empty()) {
        int u = finishStack.top(); finishStack.pop();
        if (!visited[u]) dfs2(u, rev, visited, component, compID++);
    }

    if (compID == 1) return 0;

    vector<int> inDeg(compID, 0), outDeg(compID, 0);
    for (int u = 0; u < V; ++u) {
        for (int v : adj[u]) {
            if (component[u] != component[v]) {
                outDeg[component[u]]++;
                inDeg[component[v]]++;
            }
        }
    }

    int sources = 0, sinks = 0;
    for (int i = 0; i < compID; ++i) {
        if (inDeg[i] == 0) sources++;
        if (outDeg[i] == 0) sinks++;
    }

    return max(sources, sinks);
}

int main() {
    int V = 5;
    vector<vector<int>> adj(V);
    adj[0] = {1};
    adj[1] = {2};
    adj[2] = {};
    adj[3] = {4};
    adj[4] = {};

    cout << "Minimum edges to make strongly connected: "
         << minEdgesToMakeStronglyConnected(V, adj) << endl;
}
