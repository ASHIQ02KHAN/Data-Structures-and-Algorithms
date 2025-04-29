#include <iostream>
#include <map>
#include <vector>
#include <stack>
using namespace std;

class Graph {
    map<int, vector<int>> adj;

public:
    void addEdge(int u, int v) {
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    void removeEdge(int u, int v) {
        auto it = find(adj[u].begin(), adj[u].end(), v);
        if (it != adj[u].end()) adj[u].erase(it);
        it = find(adj[v].begin(), adj[v].end(), u);
        if (it != adj[v].end()) adj[v].erase(it);
    }

    void printEulerPath() {
        int start = -1, oddCount = 0;
        for (auto [node, neighbors] : adj) {
            if (neighbors.size() % 2 == 1) {
                start = node;
                oddCount++;
            }
        }
        if (oddCount != 0 && oddCount != 2) {
            cout << "No Euler Path exists\n";
            return;
        }
        if (start == -1) start = adj.begin()->first;

        stack<int> s;
        vector<int> path;
        s.push(start);

        while (!s.empty()) {
            int u = s.top();
            if (!adj[u].empty()) {
                int v = adj[u].back();
                adj[u].pop_back();
                removeEdge(u, v);
                s.push(v);
            } else {
                path.push_back(u);
                s.pop();
            }
        }

        cout << "Euler Path: ";
        for (int v : path) cout << v << " ";
        cout << endl;
    }
};

int main() {
    Graph g;
    g.addEdge(0, 1);
    g.addEdge(1, 2);
    g.addEdge(2, 0);
    g.addEdge(1, 3);
    g.addEdge(3, 4);
    g.printEulerPath();
    return 0;
}

