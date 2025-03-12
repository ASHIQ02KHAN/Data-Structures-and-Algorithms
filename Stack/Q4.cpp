#include <iostream>
#include <stack>

using namespace std;

class MinStack {
private:
    stack<int> s, minStack;

public:
    void push(int value) {
        s.push(value);
        if (minStack.empty() || value <= minStack.top()) {
            minStack.push(value);
        }
    }

    void pop() {
        if (s.empty()) return;
        if (s.top() == minStack.top()) {
            minStack.pop();
        }
        s.pop();
    }

    int top() {
        return s.empty() ? -1 : s.top();
    }

    int getMin() {
        return minStack.empty() ? -1 : minStack.top();
    }
};

int main() {
    MinStack ms;
    ms.push(5);
    ms.push(2);
    ms.push(8);
    cout << "Min element: " << ms.getMin() << endl;
    ms.pop();
    cout << "Min element after pop: " << ms.getMin() << endl;
    return 0;
}
