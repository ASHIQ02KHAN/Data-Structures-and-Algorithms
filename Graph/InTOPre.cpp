#include <iostream>
#include <stack>
#include <algorithm>
using namespace std;

int precedence(char ch) {
    if (ch == '^') return 3;
    if (ch == '*' || ch == '/') return 2;
    if (ch == '+' || ch == '-') return 1;
    return -1;
}

string infixToPrefix(string infix) {
    reverse(infix.begin(), infix.end());
    for (char &ch : infix) {
        if (ch == '(') ch = ')';
        else if (ch == ')') ch = '(';
    }

    stack<char> s;
    string result;

    for (char ch : infix) {
        if (isalnum(ch)) {
            result += ch;
        } else if (ch == '(') {
            s.push(ch);
        } else if (ch == ')') {
            while (!s.empty() && s.top() != '(') {
                result += s.top(); s.pop();
            }
            s.pop();
        } else {
            while (!s.empty() && precedence(ch) <= precedence(s.top())) {
                result += s.top(); s.pop();
            }
            s.push(ch);
        }
    }

    while (!s.empty()) {
        result += s.top(); s.pop();
    }

    reverse(result.begin(), result.end());
    return result;
}

int main() {
    string infix = "A+(B*C)";
    cout << "Prefix: " << infixToPrefix(infix) << endl;
    return 0;
}
