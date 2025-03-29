#include <iostream>
using namespace std;
//write code of Adjacency Matrix(Directed and Weighted graph): 1->2,1->3,2->4,2->5,3->4,4->5(from destination weight)
int main() {
    int matrix[5][5]; // Adjacency matrix for 5 vertices

    // Initialize the adjacency matrix with zeros
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            matrix[i][j] = 0;
        }
    }

    int numberOfEdges;
    cout << "Enter the number of edges: ";
    cin >> numberOfEdges;

    cout << "Enter edges in the format (from destination weight):" << endl;
    for (int i = 0; i < numberOfEdges; i++) {
        int u, v, w;
        cin >> u >> v >> w; // Input edge from vertex u to v with weight w
        u--; // Convert to zero-based indexing
        v--;
        matrix[u][v] = w; // Set weight in adjacency matrix (only one direction)
    }

    // Print the adjacency matrix
    cout << "\nThe Adjacency Matrix Representation:" << endl;
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
