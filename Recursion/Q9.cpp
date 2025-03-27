#include <iostream>
using namespace std;

// Recursive function to solve Josephus problem
int josephus(int n, int k) {
    if (n == 1) // Base case: Only one person left
        return 0;
    return (josephus(n - 1, k) + k) % n; // Recursive elimination
}

int main() {
    int N = 7, K = 3;
    int survivor = josephus(N, K) + 1; // Convert 0-based index to 1-based
    cout << "The survivor's position: " << survivor << endl;
    return 0;
}
