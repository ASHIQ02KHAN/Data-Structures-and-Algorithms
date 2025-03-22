#include <iostream>
using namespace std;

// Recursive function to find sum of digits
int sumOfDigits(int n) {
    if (n == 0) return 0; // Base case
    return (n % 10) + sumOfDigits(n / 10);
}

int main() {
    int n = 1234;
    cout << "Sum of digits of " << n << " is: " << sumOfDigits(n) << endl;
    return 0;
}
