#include <iostream>
#include <vector>
using namespace std;

void transitiveClosure(int V, vector<vector<int>>& adj) {
    vector<vector<bool>> reach(V, vector<bool>(V, false));

    for (int i = 0; i < V; i++)
        for (int j : adj[i])
            reach[i][j] = true;

    for (int i = 0; i < V; i++)
        reach[i][i] = true;

    for (int k = 0; k < V; k++)
        for (int i = 0; i < V; i++)
            for (int j = 0; j < V; j++)
                reach[i][j] = reach[i][j] || (reach[i][k] && reach[k][j]);

    cout << "Transitive Closure Matrix:\n";
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++)
            cout << reach[i][j] << " ";
        cout << endl;
    }
}

int main() {
    int V = 4;
    vector<vector<int>> adj(V);
    adj[0] = {1};
    adj[1] = {2};
    adj[2] = {3};

    transitiveClosure(V, adj);
    return 0;
}
