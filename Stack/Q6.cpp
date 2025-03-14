#include <iostream>
#include <stack>
#include <sstream>

using namespace std;

// Function to evaluate a postfix expression
int evaluatePostfix(string expression) {
    stack<int> s;
    stringstream ss(expression);
    string token;

    while (ss >> token) {
        // If token is a number, push it onto the stack
        if (isdigit(token[0])) {
            s.push(stoi(token));
        }
        // If token is an operator, pop two elements, perform operation, push result
        else {
            int b = s.top(); s.pop();
            int a = s.top(); s.pop();

            if (token == "+") s.push(a + b);
            else if (token == "-") s.push(a - b);
            else if (token == "*") s.push(a * b);
            else if (token == "/") s.push(a / b);
        }
    }

    return s.top(); // Final result
}

int main() {
    string expression = "5 3 + 8 *";  // Equivalent to ((5 + 3) * 8)
    cout << "Postfix Expression: " << expression << endl;
    cout << "Evaluated Result: " << evaluatePostfix(expression) << endl;
    return 0;
}
