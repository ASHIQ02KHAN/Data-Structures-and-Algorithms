#include <iostream>
#include <vector>
#include <queue>

using namespace std;

bool isBipartite(vector<vector<int>> &graph, int V) {
    vector<int> color(V, -1); // -1 means unvisited

    for (int start = 0; start < V; start++) {
        if (color[start] == -1) {
            queue<int> q;
            q.push(start);
            color[start] = 0;

            while (!q.empty()) {
                int node = q.front();
                q.pop();

                for (int neighbor : graph[node]) {
                    if (color[neighbor] == -1) {
                        color[neighbor] = 1 - color[node];
                        q.push(neighbor);
                    } else if (color[neighbor] == color[node]) {
                        return false; // Conflict
                    }
                }
            }
        }
    }

    return true;
}

int main() {
    int V = 4;
    vector<vector<int>> graph(V);

    graph[0] = {1, 3};
    graph[1] = {0, 2};
    graph[2] = {1, 3};
    graph[3] = {0, 2};

    if (isBipartite(graph, V))
        cout << "Graph is Bipartite" << endl;
    else
        cout << "Graph is Not Bipartite" << endl;

    return 0;
}
