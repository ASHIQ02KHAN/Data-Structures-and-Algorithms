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

    void DFS(int node) {
        visited[node] = true;
        for (int neighbor : adj[node])
            if (!visited[neighbor])
                DFS(neighbor);
    }

    int countConnectedComponents() {
        int count = 0;
        for (int i = 0; i < V; i++) {
            if (!visited[i]) {
                DFS(i);
                count++;
            }
        }
        return count;
    }
};

int main() {
    Graph g(6);
    g.addEdge(0, 1);
    g.addEdge(1, 2);
    g.addEdge(3, 4);

    cout << "Number of connected components: " << g.countConnectedComponents() << endl;
    return 0;
}
