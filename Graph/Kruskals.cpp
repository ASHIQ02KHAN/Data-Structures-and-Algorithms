#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Edge {
    int u, v, weight;
};

bool compare(Edge a, Edge b) {
    return a.weight < b.weight;
}

int find(int u, vector<int>& parent) {
    return parent[u] == u ? u : parent[u] = find(parent[u], parent);
}

void unionSets(int u, int v, vector<int>& parent) {
    parent[find(u, parent)] = find(v, parent);
}

void kruskalMST(int V, vector<Edge>& edges) {
    vector<int> parent(V);
    for (int i = 0; i < V; ++i) parent[i] = i;

    sort(edges.begin(), edges.end(), compare);

    cout << "Edges in MST:\n";
    for (auto& edge : edges) {
        if (find(edge.u, parent) != find(edge.v, parent)) {
            cout << edge.u << " - " << edge.v << " (Weight: " << edge.weight << ")\n";
            unionSets(edge.u, edge.v, parent);
        }
    }
}

int main() {
    vector<Edge> edges = {
        {0, 1, 2}, {0, 3, 6}, {1, 2, 3}, {1, 3, 8}, {1, 4, 5}, {2, 4, 7}
    };
    kruskalMST(5, edges);
    return 0;
}
