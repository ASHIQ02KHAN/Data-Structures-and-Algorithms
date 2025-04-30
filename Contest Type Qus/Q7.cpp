#include <iostream>
#include <vector>
#include <stack>
using namespace std;

void topoSort(int node, vector<vector<pair<int, int>>>& adj, vector<bool>& visited, stack<int>& st) {
    visited[node] = true;
    for (auto [v, w] : adj[node])
        if (!visited[v])
            topoSort(v, adj, visited, st);
    st.push(node);
}

void longestPath(int V, vector<vector<pair<int, int>>>& adj, int src) {
    vector<bool> visited(V, false);
    stack<int> st;

    for (int i = 0; i < V; i++)
        if (!visited[i])
            topoSort(i, adj, visited, st);

    vector<int> dist(V, INT_MIN);
    dist[src] = 0;

    while (!st.empty()) {
        int u = st.top(); st.pop();
        if (dist[u] != INT_MIN) {
            for (auto [v, w] : adj[u]) {
                if (dist[v] < dist[u] + w)
                    dist[v] = dist[u] + w;
            }
        }
    }

    cout << "Longest distances from node " << src << ":\n";
    for (int i = 0; i < V; i++)
        cout << "To " << i << ": " << (dist[i] == INT_MIN ? "Unreachable" : to_string(dist[i])) << endl;
}

int main() {
    int V = 6;
    vector<vector<pair<int, int>>> adj(V);

    adj[0] = {{1, 5}, {2, 3}};
    adj[1] = {{3, 6}, {2, 2}};
    adj[2] = {{4, 4}, {5, 2}};
    adj[3] = {{4, -1}, {5, 1}};
    adj[4] = {{5, -2}};

    longestPath(V, adj, 1);
    return 0;
}
