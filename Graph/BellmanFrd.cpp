#include <iostream>
#include <vector>
using namespace std;

struct Edge {
    int u, v, weight;
};

void bellmanFord(int V, vector<Edge>& edges, int src) {
    vector<int> dist(V, 1e9);
    dist[src] = 0;

    for (int i = 1; i < V; ++i) {
        for (auto& e : edges) {
            if (dist[e.u] != 1e9 && dist[e.u] + e.weight < dist[e.v])
                dist[e.v] = dist[e.u] + e.weight;
        }
    }

    // Check for negative weight cycle
    for (auto& e : edges) {
        if (dist[e.u] != 1e9 && dist[e.u] + e.weight < dist[e.v]) {
            cout << "Negative weight cycle detected!\n";
            return;
        }
    }

    cout << "Shortest distances from source:\n";
    for (int i = 0; i < V; ++i)
        cout << "To " << i << ": " << dist[i] << "\n";
}

int main() {
    int V = 5;
    vector<Edge> edges = {
        {0, 1, -1}, {0, 2, 4},
        {1, 2, 3}, {1, 3, 2},
        {1, 4, 2}, {3, 2, 5},
        {3, 1, 1}, {4, 3, -3}
    };

    bellmanFord(V, edges, 0);
    return 0;
}
