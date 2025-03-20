#include <iostream>
using namespace std;

// Recursive function to find factorial
int factorial(int n) {
    if (n == 0) return 1; // Base case: 0! = 1
    return n * factorial(n - 1);
}

int main() {
    int n = 5;
    cout << "Factorial of " << n << " is: " << factorial(n) << endl;
    return 0;
}
