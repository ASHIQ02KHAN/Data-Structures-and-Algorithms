#include <iostream>
#include <vector>
using namespace std;

struct Edge {
    int u, v, weight;
};

bool hasNegativeCycle(int V, vector<Edge>& edges) {
    vector<int> dist(V, 1e9);
    dist[0] = 0; // Source

    for (int i = 1; i < V; i++) {
        for (auto e : edges) {
            if (dist[e.u] != 1e9 && dist[e.u] + e.weight < dist[e.v]) {
                dist[e.v] = dist[e.u] + e.weight;
            }
        }
    }

    // Extra pass to detect negative cycle
    for (auto e : edges) {
        if (dist[e.u] != 1e9 && dist[e.u] + e.weight < dist[e.v]) {
            return true; // Negative cycle detected
        }
    }

    return false;
}

int main() {
    int V = 4;
    vector<Edge> edges = {
        {0, 1, 1}, {1, 2, -1}, {2, 3, -1}, {3, 0, -1}
    };

    cout << (hasNegativeCycle(V, edges) ? "Negative cycle exists" : "No negative cycle") << endl;
    return 0;
}
