#include <iostream>
#include <vector>
#include <queue>
using namespace std;

bool isUniqueTopoSort(int V, vector<vector<int>>& adj) {
    vector<int> indegree(V, 0);
    for (int u = 0; u < V; u++)
        for (int v : adj[u])
            indegree[v]++;

    queue<int> q;
    for (int i = 0; i < V; i++)
        if (indegree[i] == 0)
            q.push(i);

    int count = 0;
    while (!q.empty()) {
        if (q.size() > 1) return false; // More than one choice

        int u = q.front(); q.pop();
        count++;

        for (int v : adj[u]) {
            if (--indegree[v] == 0)
                q.push(v);
        }
    }

    return count == V;
}

int main() {
    int V = 4;
    vector<vector<int>> adj(V);
    adj[0] = {1};
    adj[1] = {2};
    adj[2] = {3};
    // adj[0] = {2}; // Uncomment to make it not unique

    cout << (isUniqueTopoSort(V, adj) ? "Unique Topo Order" : "Not Unique") << endl;
    return 0;
}
