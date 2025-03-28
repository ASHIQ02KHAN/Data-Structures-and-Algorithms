#include <iostream>
using namespace std;

// Recursive function to count ways to reach the nth stair
int countWays(int n) {
    if (n == 1) return 1; // Only one way to climb one step
    if (n == 2) return 2; // Two ways: (1+1) or (2)

    return countWays(n - 1) + countWays(n - 2);
}

int main() {
    int N = 5; // Number of stairs
    cout << "Ways to reach the " << N << "th stair: " << countWays(N) << endl;
    return 0;
}
