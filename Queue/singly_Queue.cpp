//implement (Queue data structure) using a (singly linked list) functions: enqueue, dequeue, isEmpty, isFull, showQueue, peak.
#include <iostream>
using namespace std;


// Define the Node structure
struct Node {
    int data;
    Node* next;
};

class Queue {
private:
    Node* front;  // Pointer to the front of the queue
    Node* rear;   // Pointer to the rear of the queue

public:
    // Constructor
    Queue() {
        front = rear = nullptr;  // Initialize an empty queue
    }

    // Check if the queue is empty
    bool isEmpty() {
        return front == nullptr;
    }

    // Enqueue: Add an element to the rear of the queue
    void enqueue(int value) {
        Node* newNode = new Node;  // Create a new node
        newNode->data = value;
        newNode->next = nullptr;

        if (rear == nullptr) {  // If the queue is empty
            front = rear = newNode;
        } else {  // Add the new node at the rear
            rear->next = newNode;
            rear = newNode;
        }
        cout << value << " is enqueued!" << endl;
    }

    // Dequeue: Remove and return the front element of the queue
    int dequeue() {
        if (isEmpty()) {
            cout << "Queue is empty!" << endl;
            return -1;
        }

        int dequeuedValue = front->data;  // Get the data from the front node
        Node* temp = front;  // Temporary pointer to delete the node
        front = front->next;  // Move the front pointer to the next node

        if (front == nullptr) {  // If the queue becomes empty
            rear = nullptr;
        }

        delete temp;  // Free the memory of the dequeued node
        cout << dequeuedValue << " is dequeued!" << endl;
        return dequeuedValue;
    }

    // Peek: Return the front element without removing it
    int peak() {
        if (isEmpty()) {
            cout << "Queue is empty!" << endl;
            return -1;
        }
        return front->data;
    }

    // Show the elements of the queue
    void showQueue() {
        if (isEmpty()) {
            cout << "Queue is empty!" << endl;
            return;
        }

        Node* temp = front;  // Start from the front
        cout << "Queue: ";
        while (temp != nullptr) {  // Traverse and print all elements
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }

    // Destructor to free memory
    ~Queue() {
        while (front != nullptr) {
            Node* temp = front;
            front = front->next;
            delete temp;
        }
        rear = nullptr;
    }
};

// Main function to test the queue
int main() {
    Queue q;  // Create a queue

    q.enqueue(10);  // Enqueue elements
    q.enqueue(20);
    q.enqueue(30);
    q.showQueue();

    cout << "The peak value is: " << q.peak() << endl;

    q.dequeue();  // Dequeue elements
    q.showQueue();

    q.enqueue(40);  // Enqueue more elements
    q.enqueue(50);
    q.enqueue(60);
    q.showQueue();

    q.dequeue();
    q.showQueue();

    return 0;
}
