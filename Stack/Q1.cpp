#include <iostream>
#include <stack>

using namespace std;

// Function to reverse a string using stack
string reverseString(string str) {
    stack<char> s;

    // Push all characters onto stack
    for (char ch : str) {
        s.push(ch);
    }

    // Pop characters to get reversed string
    string reversed = "";
    while (!s.empty()) {
        reversed += s.top();
        s.pop();
    }

    return reversed;
}

int main() {
    string str = "hello";
    cout << "Original String: " << str << endl;
    cout << "Reversed String: " << reverseString(str) << endl;
    return 0;
}
