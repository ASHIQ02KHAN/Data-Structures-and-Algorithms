#include <iostream>
#define MAX 5

using namespace std;

class CircularQueue {
private:
    int arr[MAX];
    int front, rear, size;

public:
    CircularQueue() {
        front = rear = -1;
        size = 0;
    }

    bool isFull() {
        return size == MAX;
    }

    bool isEmpty() {
        return size == 0;
    }

    void enqueue(int value) {
        if (isFull()) {
            cout << "Queue is full! Cannot enqueue " << value << ".\n";
            return;
        }

        if (isEmpty()) {
            front = rear = 0;
        } else {
            rear = (rear + 1) % MAX;
        }
        arr[rear] = value;
        size++;
        cout << value << " enqueued into the queue.\n";
    }

    void dequeue() {
        if (isEmpty()) {
            cout << "Queue is empty! Cannot dequeue.\n";
            return;
        }

        cout << arr[front] << " dequeued from the queue.\n";
        front = (front + 1) % MAX;
        size--;

        if (isEmpty()) {
            front = rear = -1; // Reset when last element is removed
        }
    }

    void display() {
        if (isEmpty()) {
            cout << "Queue is empty!\n";
            return;
        }

        cout << "Queue elements: ";
        for (int i = 0, idx = front; i < size; i++) {
            cout << arr[idx] << " ";
            idx = (idx + 1) % MAX;
        }
        cout << "\n";
    }
};

int main() {
    CircularQueue q;
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.enqueue(40);
    q.enqueue(50);
    q.dequeue();
    q.enqueue(60);
    q.display();
    return 0;
}
