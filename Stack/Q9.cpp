#include <iostream>
#include <stack>

using namespace std;

class QueueUsingStacks {
private:
    stack<int> s1, s2;

public:
    // Enqueue operation
    void enqueue(int x) {
        s1.push(x);
        cout << x << " enqueued into the queue.\n";
    }

    // Dequeue operation
    void dequeue() {
        if (s1.empty() && s2.empty()) {
            cout << "Queue is empty! Cannot dequeue.\n";
            return;
        }

        // Move elements from s1 to s2 if s2 is empty
        if (s2.empty()) {
            while (!s1.empty()) {
                s2.push(s1.top());
                s1.pop();
            }
        }

        cout << s2.top() << " dequeued from the queue.\n";
        s2.pop();
    }

    // Get front element
    int front() {
        if (s1.empty() && s2.empty()) {
            cout << "Queue is empty!\
