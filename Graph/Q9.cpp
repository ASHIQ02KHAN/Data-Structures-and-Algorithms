#include <iostream>
#include <sstream>
using namespace std;

void countPostfixParts(string expr) {
    stringstream ss(expr);
    string token;
    int operands = 0, operators = 0;

    while (ss >> token) {
        if (isdigit(token[0]))
            operands++;
        else
            operators++;
    }

    cout << "Operands: " << operands << "\nOperators: " << operators << endl;
}

int main() {
    string expr = "5 6 + 3 *";
    countPostfixParts(expr);
    return 0;
}
