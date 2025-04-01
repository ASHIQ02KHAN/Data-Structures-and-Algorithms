#include <iostream> //write code of Adjacency List(Directed and Weighted graph): 1->2,1->3,2->4,2->5,3->5,4->6,5->6 (from destination weight)
#include <vector>
using namespace std;

// Structure to represent a weighted edge
struct Edge {
    int vertex;    // Destination vertex
    int weight;    // Weight of the edge
};

// Function to add an edge to the adjacency list
void addEdge(vector<vector<Edge>>& adjacencyList, int from, int to, int weight) {
    // Add edge from 'from' to 'to'
    adjacencyList[from].push_back({to, weight});
}

// Main function
int main() {
    int numVertices = 6; // Number of vertices in the graph
    vector<vector<Edge>> adjacencyList(numVertices); // Adjacency list initialized with empty vectors

    int numEdges = 7; // Number of edges in the graph
    cout << "Enter " << numEdges << " edges (format: from destination weight):\n";

    // Input edges and add them to the adjacency list
    for (int i = 0; i < numEdges; i++) {
        int from, to, weight;
        cin >> from >> to >> weight; // Read the endpoints and weight of the edge
        from--;                      // Convert to zero-based indexing
        to--;
        addEdge(adjacencyList, from, to, weight);
    }

    // Print the adjacency list
    cout << "\nThe Adjacency List Representation of the Directed Graph:\n";
    for (int i = 0; i < numVertices; i++) {
        cout << "Vertex " << i + 1 << ": "; // Print vertex number (one-based indexing)
        for (const Edge& edge : adjacencyList[i]) {
            cout << "(" << edge.vertex + 1 << ", " << edge.weight << ") "; // Print connected vertex and weight
        }
        cout << endl;
    }

    return 0;
}
