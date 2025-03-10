#include <iostream>
#include <stack>

using namespace std;

// Function to check balanced parentheses
bool isBalanced(string expr) {
    stack<char> s;

    for (char ch : expr) {
        if (ch == '(' || ch == '{' || ch == '[') {
            s.push(ch); // Push opening bracket
        } else {
            if (s.empty()) return false; // Unmatched closing bracket
            char top = s.top();
            if ((ch == ')' && top == '(') || (ch == '}' && top == '{') || (ch == ']' && top == '[')) {
                s.pop(); // Pop matching opening bracket
            } else {
                return false;
            }
        }
    }

    return s.empty(); // Stack should be empty if balanced
}

int main() {
    string expr = "{[()]}";
    if (isBalanced(expr)) {
        cout << "Balanced Parentheses\n";
    } else {
        cout << "Unbalanced Parentheses\n";
    }
    return 0;
}
