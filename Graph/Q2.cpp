#include <iostream>
#include <vector>

using namespace std;

class Graph {
    int V;
    vector<int> *adj;
    vector<bool> visited;

public:
    Graph(int V) {
        this->V = V;
        adj = new vector<int>[V];
        visited.resize(V, false);
    }

    void addEdge(int u, int v) {
        adj[u].push_back(v);
        adj[v].push_back(u); // Undirected Graph
    }

    void DFS(int node) {
        visited[node] = true;
        cout << node << " ";

        for (int neighbor : adj[node]) {
            if (!visited[neighbor])
                DFS(neighbor);
        }
    }

    void startDFS(int start) {
        cout << "DFS Traversal: ";
        DFS(start);
        cout << endl;
    }
};

int main() {
    Graph g(6);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 3);
    g.addEdge(1, 4);
    g.addEdge(2, 5);

    g.startDFS(0);
    return 0;
}
