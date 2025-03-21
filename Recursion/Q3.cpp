#include <iostream>
using namespace std;

// Recursive function to find nth Fibonacci number
int fibonacci(int n) {
    if (n == 0) return 0; // Base case
    if (n == 1) return 1; // Base case
    return fibonacci(n - 1) + fibonacci(n - 2);
}

int main() {
    int n = 6;
    cout << "Fibonacci number at position " << n << " is: " << fibonacci(n) << endl;
    return 0;
}
