#include <iostream>
#include <stack>
#include <sstream>
using namespace std;

int evaluatePrefix(string expr) {
    stack<int> s;
    string token;
    vector<string> tokens;
    stringstream ss(expr);

    while (ss >> token) tokens.push_back(token);

    for (int i = tokens.size() - 1; i >= 0; --i) {
        if (isdigit(tokens[i][0])) {
            s.push(stoi(tokens[i]));
        } else {
            int a = s.top(); s.pop();
            int b = s.top(); s.pop();

            if (tokens[i] == "+") s.push(a + b);
            else if (tokens[i] == "-") s.push(a - b);
            else if (tokens[i] == "*") s.push(a * b);
            else if (tokens[i] == "/") s.push(a / b);
        }
    }

    return s.top();
}

int main() {
    string expr = "* + 5 3 2"; // (5 + 3) * 2
    cout << "Result of Prefix: " << evaluatePrefix(expr) << endl;
    return 0;
}
