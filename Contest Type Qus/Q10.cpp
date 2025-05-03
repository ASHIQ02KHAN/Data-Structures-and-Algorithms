#include <iostream>
#include <vector>
using namespace std;

bool hamiltonianDFS(int node, vector<vector<int>>& adj, vector<bool>& visited, int count) {
    if (count == visited.size()) return true;

    visited[node] = true;
    for (int neighbor : adj[node]) {
        if (!visited[neighbor]) {
            if (hamiltonianDFS(neighbor, adj, visited, count + 1)) return true;
        }
    }
    visited[node] = false;
    return false;
}

bool hasHamiltonianPath(int V, vector<vector<int>>& adj) {
    for (int i = 0; i < V; i++) {
        vector<bool> visited(V, false);
        if (hamiltonianDFS(i, adj, visited, 1))
            return true;
    }
    return false;
}

int main() {
    int V = 4;
    vector<vector<int>> adj(V);
    adj[0] = {1, 2};
    adj[1] = {0, 2};
    adj[2] = {0, 1, 3};
    adj[3] = {2};

    cout << (hasHamiltonianPath(V, adj) ? "Hamiltonian Path exists" : "No Hamiltonian Path") << endl;
    return 0;
}
