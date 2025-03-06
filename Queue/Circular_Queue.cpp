//implement ( Circular Queue) using a (singly linked list) functions: enqueue, dequeue, isEmpty, isFull, showQueue, peak.
#include <iostream>
using namespace std;


struct Node {
    int data;
    Node* next;
};


class CircularQueue {
private:
    Node* front;
    Node* rear;
    int size;
    int capacity;

public:
    CircularQueue(int cap) {
        front = nullptr;
        rear = nullptr;
        size = 0;
        capacity = cap;
    }

    // queue empty ?
    bool isEmpty() {
        return size == 0;
    }

    //queue full ?
    bool isFull() {
        return size == capacity;
    }

    // add elements >>
    void enqueue(int value) {
        if (isFull()) {
            cout << "Queue is full!" << endl;
            return;
        }

        Node* newNode = new Node();
        newNode->data = value;

        if (isEmpty()) {
            front = rear = newNode;
            rear->next = front;
        } else {
            rear->next = newNode;
            rear = newNode;
            rear->next = front;
        }

        size++;
        cout << value << " enqueued!" << endl;
    }

    // remove from queue >>
    int dequeue() {
        if (isEmpty()) {
            cout << "Queue is empty!" << endl;
            return -1;
        }

        int dequeuedValue;
        if (front == rear) {
            dequeuedValue = front->data;
            delete front;
            front = rear = nullptr;
        } else {
            Node* temp = front;
            dequeuedValue = front->data;
            front = front->next;
            rear->next = front;
            delete temp;
        }

        size--;
        cout << dequeuedValue << " dequeued!" << endl;
        return dequeuedValue;
    }

    // front element >>
    int peak() {
        if (isEmpty()) {
            cout << "Queue is empty!" << endl;
            return -1;
        }
        return front->data;
    }

    // display the queue >>
    void showQueue() {
        if (isEmpty()) {
            cout << "Queue is empty!" << endl;
            return;
        }

        Node* temp = front;
        cout << "Queue elements: ";
        do {
            cout << temp->data << " ";
            temp = temp->next;
        } while (temp != front);
        cout << endl;
    }

// for clear elements
    ~CircularQueue() {
        while (!isEmpty()) {
            dequeue();
        }
    }
};


int main() {
    CircularQueue cq(5);

    cq.enqueue(10);
    cq.enqueue(20);
    cq.enqueue(30);
    cq.enqueue(40);
    cq.enqueue(50);

    cq.showQueue();

    cout << "The peak element is : " << cq.peak() << endl;

    cq.dequeue();
    cq.dequeue();

    cq.showQueue();

    cq.enqueue(60);
    cq.enqueue(70);
    //cq.enqueue(80);

    cq.showQueue();


    cout << (cq.isFull() ? "The queue is full" : "The queue is not full") << endl;

    return 0;
}
