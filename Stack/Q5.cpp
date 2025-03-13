#include <iostream>
#include <stack>

using namespace std;

// Function to insert an element into a sorted stack
void sortedInsert(stack<int> &s, int element) {
    if (s.empty() || element > s.top()) {
        s.push(element);
        return;
    }

    int top = s.top();
    s.pop();
    sortedInsert(s, element);
    s.push(top);
}

// Recursive function to sort a stack
void sortStack(stack<int> &s) {
    if (!s.empty()) {
        int top = s.top();
        s.pop();
        sortStack(s);
        sortedInsert(s, top);
    }
}

// Function to print stack elements
void printStack(stack<int> s) {
    while (!s.empty()) {
        cout << s.top() << " ";
        s.pop();
    }
    cout << endl;
}

int main() {
    stack<int> s;
    s.push(30);
    s.push(-5);
    s.push(18);
    s.push(14);
    s.push(-3);

    cout << "Original Stack: ";
    printStack(s);

    sortStack(s);

    cout << "Sorted Stack: ";
    printStack(s);
    return 0;
}
