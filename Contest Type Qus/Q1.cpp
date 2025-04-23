#include <iostream>
#include <vector>
using namespace std;

void dfs(vector<vector<char>>& grid, int i, int j) {
    int m = grid.size(), n = grid[0].size();
    if (i < 0 || i >= m || j < 0 || j >= n || grid[i][j] == '0') return;

    grid[i][j] = '0'; // Mark as visited

    dfs(grid, i + 1, j); // Down
    dfs(grid, i - 1, j); // Up
    dfs(grid, i, j + 1); // Right
    dfs(grid, i, j - 1); // Left
}

int numIslands(vector<vector<char>>& grid) {
    if (grid.empty()) return 0;
    int count = 0;
    for (int i = 0; i < grid.size(); i++)
        for (int j = 0; j < grid[0].size(); j++)
            if (grid[i][j] == '1') {
                count++;
                dfs(grid, i, j);
            }
    return count;
}

int main() {
    vector<vector<char>> grid = {
        {'1','1','0','0'},
        {'1','0','0','1'},
        {'0','0','1','1'},
        {'0','0','0','1'}
    };
    cout << "Number of Islands: " << numIslands(grid) << endl;
    return 0;
}
