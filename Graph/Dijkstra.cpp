#include <iostream>
#include <vector>
#include <queue>
using namespace std;

#define INF 1e9

void dijkstra(int V, vector<pair<int, int>> adj[], int src) {
    vector<int> dist(V, INF);
    dist[src] = 0;

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
    pq.push({0, src});

    while (!pq.empty()) {
        int u = pq.top().second;
        int d = pq.top().first;
        pq.pop();

        for (auto [v, weight] : adj[u]) {
            if (dist[v] > d + weight) {
                dist[v] = d + weight;
                pq.push({dist[v], v});
            }
        }
    }

    cout << "Shortest distances from source " << src << ":\n";
    for (int i = 0; i < V; i++) cout << "To " << i << ": " << dist[i] << "\n";
}

int main() {
    int V = 5;
    vector<pair<int, int>> adj[V];

    adj[0].push_back({1, 2});
    adj[0].push_back({2, 4});
    adj[1].push_back({2, 1});
    adj[1].push_back({3, 7});
    adj[2].push_back({4, 3});
    adj[3].push_back({4, 1});

    dijkstra(V, adj, 0);

    return 0;
}
