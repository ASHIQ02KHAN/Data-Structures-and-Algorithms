#include <iostream>
#include <queue>

using namespace std;

class StackUsingQueues {
private:
    queue<int> q1, q2;

public:
    // Push element onto stack
    void push(int x) {
        q2.push(x);

        // Move all elements from q1 to q2
        while (!q1.empty()) {
            q2.push(q1.front());
            q1.pop();
        }

        // Swap q1 and q2
        swap(q1, q2);
        cout << x << " pushed into the stack.\n";
    }

    // Remove the top element
    void pop() {
        if (q1.empty()) {
            cout << "Stack is empty! Cannot pop.\n";
            return;
        }
        cout << q1.front() << " popped from the stack.\n";
        q1.pop();
    }

    // Get the top element
    int top() {
        if (q1.empty()) {
            cout << "Stack is empty!\n";
            return -1;
        }
        return q1.front();
    }

    // Check if stack is empty
    bool isEmpty() {
        return q1.empty();
    }
};

int main() {
    StackUsingQueues s;
    s.push(10);
    s.push(20);
    s.push(30);

    cout << "Top element: " << s.top() << endl;
    s.pop();
    cout << "Top element after pop: " << s.top() << endl;

    return 0;
}
