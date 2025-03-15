#include <iostream>
#include <stack>

using namespace std;

// Function to sort a stack using another stack
stack<int> sortStack(stack<int> input) {
    stack<int> sorted;

    while (!input.empty()) {
        int temp = input.top();
        input.pop();

        // Move elements from 'sorted' back to 'input' if they are greater than temp
        while (!sorted.empty() && sorted.top() > temp) {
            input.push(sorted.top());
            sorted.pop();
        }

        // Push the element in the correct position in 'sorted' stack
        sorted.push(temp);
    }

    return sorted;  // Sorted stack (smallest element on top)
}

// Function to display stack elements
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

    stack<int> sortedStack = sortStack(s);

    cout << "Sorted Stack: ";
    printStack(sortedStack);

    return 0;
}
