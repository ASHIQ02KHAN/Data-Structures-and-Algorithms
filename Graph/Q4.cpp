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
        adj[v].push_back(u);
    }

    bool isCyclicDFS(int node, int parent) {
        visited[node] = true;
        for (int neighbor : adj[node]) {
            if (!visited[neighbor]) {
                if (isCyclicDFS(neighbor, node)) return true;
            } else if (neighbor != parent) {
                return true; // Cycle found
            }
        }
        return false;
    }

    bool hasCycle() {
        for (int i = 0; i < V; i++)
            if (!visited[i])
                if (isCyclicDFS(i, -1))
                    return true;
        return false;
    }
};

int main() {
    Graph g(5);
    g.addEdge(0, 1);
    g.addEdge(1, 2);
    g.addEdge(2, 0); // Cycle
    g.addEdge(3, 4);

    cout << (g.hasCycle() ? "Cycle detected" : "No cycle found") << endl;
    return 0;
}
