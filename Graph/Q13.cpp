#include <iostream>
#include <stack>
#include <sstream>
#include <vector>
using namespace std;

int evaluatePrefix(string expr) {
    stack<int> s;
    vector<string> tokens;
    string token;
    stringstream ss(expr);

    while (ss >> token) tokens.push_back(token);

    for (int i = tokens.size() - 1; i >= 0; i--) {
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
    string expr = "* + 12 8 3";
    cout << "Prefix Result: " << evaluatePrefix(expr) << endl;
    return 0;
}
