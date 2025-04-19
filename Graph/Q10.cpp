#include <iostream>
#include <sstream>
#include <stack>
using namespace std;

bool isValidPostfix(string expr) {
    stringstream ss(expr);
    string token;
    int count = 0;

    while (ss >> token) {
        if (isdigit(token[0])) {
            count++;
        } else {
            count -= 2;
            if (count < 0) return false;
            count++; // Push result of operation
        }
    }
    return count == 1;
}

int main() {
    string expr = "5 6 + 3 *"; // valid
    cout << (isValidPostfix(expr) ? "Valid" : "Invalid") << endl;
    return 0;
}
