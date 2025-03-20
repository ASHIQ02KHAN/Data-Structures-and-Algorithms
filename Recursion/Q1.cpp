#include <iostream>
using namespace std;

// Recursive function to print numbers from N to 1
void printNumbers(int n) {
    if (n == 0) return; // Base case
    cout << n << " ";   // Print current number
    printNumbers(n - 1); // Recursive call with (n-1)
}

int main() {
    int n = 5;
    cout << "Numbers from " << n << " to 1: ";
    printNumbers(n);
    return 0;
}
