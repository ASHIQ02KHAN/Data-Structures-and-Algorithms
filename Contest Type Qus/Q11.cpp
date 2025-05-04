#include <iostream>
#include <vector>
using namespace std;

void dfs(int u, vector<vector<int>>& adj, vector<bool>& visited) {
    visited[u] = true;
    for (int v : adj[u])
        if (!visited[v])
            dfs(v, adj, visited);
}

int findMotherVertex(int V, vector<vector<int>>& adj) {
    int lastFinished = 0;
    vector<bool> visited(V, false);

    for (int i = 0; i < V; i++) {
        if (!visited[i]) {
            dfs(i, adj, visited);
            lastFinished = i;
        }
    }

    fill(visited.begin(), visited.end(), false);
    dfs(lastFinished, adj, visited);
    for (bool v : visited)
        if (!v) return -1;

    return lastFinished;
}

int main() {
    int V = 7;
    vector<vector<int>> adj(V);
    adj[0] = {1, 2};
    adj[1] = {3};
    adj[2] = {1};
    adj[3] = {4};
    adj[4] = {};
    adj[5] = {6};
    adj[6] = {4};

    int mother = findMotherVertex(V, adj);
    if (mother == -1) cout << "No Mother Vertex" << endl;
    else cout << "Mother Vertex: " << mother << endl;
}
