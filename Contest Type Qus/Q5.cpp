#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> adj;
vector<int> tin, low;
vector<bool> visited;
int timer;

void dfs(int u, int parent) {
    visited[u] = true;
    tin[u] = low[u] = timer++;
    int children = 0;

    for (int v : adj[u]) {
        if (v == parent) continue;
        if (visited[v]) {
            low[u] = min(low[u], tin[v]);
        } else {
            dfs(v, u);
            low[u] = min(low[u], low[v]);
            if (low[v] >= tin[u] && parent != -1) {
                cout << "Articulation Point: " << u << endl;
            }
            ++children;
        }
    }

    if (parent == -1 && children > 1) {
        cout << "Articulation Point: " << u << endl;
    }
}

void findArticulationPoints(int n) {
    timer = 0;
    tin.assign(n, -1);
    low.assign(n, -1);
    visited.assign(n, false);

    for (int i = 0; i < n; i++) {
        if (!visited[i])
            dfs(i, -1);
    }
}

int main() {
    int n = 5;
    adj.resize(n);
    adj[0] = {1, 2};
    adj[1] = {0, 2};
    adj[2] = {0, 1, 3};
    adj[3] = {2, 4};
    adj[4] = {3};

    findArticulationPoints(n);
    return 0;
}
