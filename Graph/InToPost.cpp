#include <iostream>
#include <stack>
#include <string>
using namespace std;

int precedence(char op) {
    if (op == '^') return 3;
    if (op == '*' || op == '/') return 2;
    if (op == '+' || op == '-') return 1;
    return 0;
}

bool isOperator(char ch) {
    return ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^';
}

string infixToPostfix(string infix) {
    stack<char> s;
    string postfix;

    for (char ch : infix) {
        if (isalnum(ch)) {
            postfix += ch;
        } else if (ch == '(') {
            s.push(ch);
        } else if (ch == ')') {
            while (!s.empty() && s.top() != '(') {
                postfix += s.top(); s.pop();
            }
            s.pop(); // pop '('
        } else if (isOperator(ch)) {
            while (!s.empty() && precedence(ch) <= precedence(s.top())) {
                postfix += s.top(); s.pop();
            }
            s.push(ch);
        }
    }

    while (!s.empty()) {
        postfix += s.top(); s.pop();
    }

    return postfix;
}

int main() {
    string infix = "A+(B*C)";
    cout << "Postfix: " << infixToPostfix(infix) << endl;
    return 0;
}
