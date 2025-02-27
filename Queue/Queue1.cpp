#include <iostream>
#define MAX 5 // Maximum size of the queue

using namespace std;

class Queue {
private:
    int arr[MAX];  // Array to store queue elements
    int front, rear; // Front and rear pointers

public:
    // Constructor to initialize the queue
    Queue() {
        front = -1;
        rear = -1;
    }

    // Check if the queue is empty
    bool isEmpty() {
        return (front == -1);
    }

    // Check if the queue is full
    bool isFull() {
        return (rear == MAX - 1);
    }

    // Insert an element into the queue (Enqueue)
    void enqueue(int value) {
        if (isFull()) {
            cout << "Queue is full! Cannot enqueue " << value << ".\n";
            return;
        }
        if (isEmpty()) {
            front = 0; // Set front to 0 when first element is inserted
        }
        arr[++rear] = value;
        cout << value << "  enqueued.\n";
    }

    // Remove an element from the queue (Dequeue)
    void dequeue() {
        if (isEmpty()) {
            cout << "Queue is empty! Cannot dequeue.\n";
            return;
        }
        cout << arr[front] << " dequeued from the queue.\n";
        if (front == rear) {
            front = rear = -1; // Reset queue when last element is removed
        } else {
            front++;
        }
    }

    // Get the front element without removing it (Peek)
    void peek() {
        if (isEmpty()) {
            cout << "Queue is empty! No front element.\n";
            return;
        }
        cout << "Front element: " << arr[front] << "\n";
    }

    // Display the queue elements
    void display() {
        if (isEmpty()) {
            cout << "Queue is empty!\n";
            return;
        }
        cout << "\nFinal Queue Elements: ";
        for (int i = front; i <= rear; i++) {
            cout << arr[i] << " ";
        }
        cout << "\n";
    }
};

// Main function to test the queue operations
int main() {
    Queue q;

    // Enqueue operations
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.enqueue(40);
    q.enqueue(50);

    // Display the queue after insertions
    q.display();

    // Dequeue operations
    q.dequeue();
    q.dequeue();

    // Peek at the front element
    q.peek();

    // Display the final queue state
    q.display();

    return 0;
}
