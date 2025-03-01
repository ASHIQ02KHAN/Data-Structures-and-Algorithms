#include <iostream>
#include <stack>

using namespace std;

class QueueUsingStacks {
private:
    stack<int> s1, s2;

public:
    // Enqueue operation
    void enqueue(int value) {
        s1.push(value);
        cout << value << " enqueued into the queue.\n";
    }

    // Dequeue operation
    void dequeue() {
        if (s1.empty() && s2.empty()) {
            cout << "Queue is empty! Cannot dequeue.\n";
            return;
        }

        // Transfer elements from s1 to s2 if s2 is empty
        if (s2.empty()) {
            while (!s1.empty()) {
                s2.push(s1.top());
                s1.pop();
            }
        }

        cout << s2.top() << " dequeued from the queue.\n";
        s2.pop();
    }

    // Peek at front element
    void peek() {
        if (s1.empty() && s2.empty()) {
            cout << "Queue is empty! No front element.\n";
            return;
        }

        if (s2.empty()) {
            while (!s1.empty()) {
                s2.push(s1.top());
                s1.pop();
            }
        }
        cout << "Front element: " << s2.top() << "\n";
    }
};

int main() {
    QueueUsingStacks q;
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.dequeue();
    q.peek();
    return 0;
}
