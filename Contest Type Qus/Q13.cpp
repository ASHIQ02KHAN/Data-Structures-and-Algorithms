#include <iostream>
#include <vector>
#include <queue>
#include <climits>
using namespace std;

int minCostConnectPoints(vector<pair<int, int>>& points) {
    int n = points.size();
    vector<bool> inMST(n, false);
    vector<int> minDist(n, INT_MAX);
    minDist[0] = 0;
    int totalCost = 0;

    for (int count = 0; count < n; ++count) {
        int u = -1;
        for (int i = 0; i < n; ++i)
            if (!inMST[i] && (u == -1 || minDist[i] < minDist[u]))
                u = i;

        inMST[u] = true;
        totalCost += minDist[u];

        for (int v = 0; v < n; ++v) {
            if (!inMST[v]) {
                int dist = abs(points[u].first - points[v].first) + abs(points[u].second - points[v].second);
                minDist[v] = min(minDist[v], dist);
            }
        }
    }

    return totalCost;
}

int main() {
    vector<pair<int, int>> points = {{0, 0}, {2, 2}, {3, 10}, {5, 2}, {7, 0}};
    cout << "Minimum cost to connect all points: " << minCostConnectPoints(points) << endl;
    return 0;
}
