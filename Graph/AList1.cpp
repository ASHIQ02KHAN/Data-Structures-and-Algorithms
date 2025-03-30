#include <iostream> // edges(undirected):1↔2,1↔3,2↔4,2↔5,3↔5,4↔6,5↔6
using namespace std;

// Node structure to represent each vertex in the adjacency list
struct Node {
    int data;      // Value of the vertex
    Node* next;    // Pointer to the next vertex in the list
};

// Function to create a new node
Node* createNode(int data) {
    Node* newNode = new Node; // Allocate memory for a new node
    newNode->data = data;     // Assign data to the node
    newNode->next = nullptr; // Initialize next pointer to null
    return newNode;
}

// Function to add an edge to the adjacency list
void addEdge(Node* adjacencyList[], int from, int to) {
    // Add an edge from 'from' to 'to'
    Node* newNode = createNode(to);
    newNode->next = adjacencyList[from];
    adjacencyList[from] = newNode;

    // Since the graph is undirected, also add an edge from 'to' to 'from'
    newNode = createNode(from);
    newNode->next = adjacencyList[to];
    adjacencyList[to] = newNode;
}

// Main function
int main() {
    int numVertices = 6;                // Number of vertices in the graph
    Node* adjacencyList[numVertices] = {nullptr}; // Initialize adjacency list with null pointers

    int numEdges = 7;                  // Number of edges in the graph
    cout << "Enter " << numEdges << " edges (format is: (from destination)):\n";

    // Input edges and add them to the adjacency list
    for (int i = 0; i < numEdges; i++) {
        int from, to;
        cin >> from >> to;             // Read the endpoints of the edge
        from--;                        // Convert to zero-based indexing
        to--;
        addEdge(adjacencyList, from, to);
    }

    // Print the adjacency list
    cout << "\nThe Adjacency List Representation of the Graph:\n";
    for (int i = 0; i < numVertices; i++) {
        cout << "Vertex " << i + 1 << ": "; // Print vertex number (one-based indexing)
        Node* current = adjacencyList[i];
        while (current != nullptr) {
            cout << current->data + 1 << " "; // Print connected vertex (convert back to one-based indexing)
            current = current->next;
        }
        cout << endl;
    }

    return 0;
}
