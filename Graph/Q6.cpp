#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class Graph {
    int V;
    vector<int> *adj;
    vector<bool> visited;
    stack<int> topoStack;

public:
    Graph(int V) {
        this->V = V;
        adj = new vector<int>[V];
        visited.resize(V, false);
    }

    void addEdge(int u, int v) {
        adj[u].push_back(v);
    }

    void DFS(int node) {
        visited[node] = true;
        for (int neighbor : adj[node])
            if (!visited[neighbor])
                DFS(neighbor);
        topoStack.push(node);
    }

    void topologicalSort() {
        for (int i = 0; i < V; i++)
            if (!visited[i])
                DFS(i);

        cout << "Topological Order: ";
        while (!topoStack.empty()) {
            cout << topoStack.top() << " ";
            topoStack.pop();
        }
        cout << endl;
    }
};

int main() {
    Graph g(6);
    g.addEdge(5, 2);
    g.addEdge(5, 0);
    g.addEdge(4, 0);
    g.addEdge(4, 1);
    g.addEdge(2, 3);
    g.addEdge(3, 1);

    g.topologicalSort();
    return 0;
}
