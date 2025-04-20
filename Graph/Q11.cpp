#include <iostream>
#include <stack>
#include <sstream>
#include <cmath>
using namespace std;

int evaluate(string expr) {
    stack<int> s;
    stringstream ss(expr);
    string token;

    while (ss >> token) {
        if (isdigit(token[0])) {
            s.push(stoi(token));
        } else {
            int b = s.top(); s.pop();
            int a = s.top(); s.pop();

            if (token == "+") s.push(a + b);
            else if (token == "-") s.push(a - b);
            else if (token == "*") s.push(a * b);
            else if (token == "/") s.push(a / b);
            else if (token == "^") s.push(pow(a, b));
        }
    }

    return s.top();
}

int main() {
    string expr = "2 3 ^ 4 *";
    cout << "Result: " << evaluate(expr) << endl;
    return 0;
}
