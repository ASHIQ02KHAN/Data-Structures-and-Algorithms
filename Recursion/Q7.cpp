#include <iostream>
using namespace std;

// Recursive function to solve Tower of Hanoi
void towerOfHanoi(int n, char fromRod, char toRod, char auxRod) {
    if (n == 1) { // Base case: Move a single disk
        cout << "Move disk 1 from " << fromRod << " to " << toRod << endl;
        return;
    }

    // Move N-1 disks from 'fromRod' to 'auxRod' using 'toRod'
    towerOfHanoi(n - 1, fromRod, auxRod, toRod);

    // Move the nth disk from 'fromRod' to 'toRod'
    cout << "Move disk " << n << " from " << fromRod << " to " << toRod << endl;

    // Move N-1 disks from 'auxRod' to 'toRod' using 'fromRod'
    towerOfHanoi(n - 1, auxRod, toRod, fromRod);
}

int main() {
    int n = 3; // Number of disks
    cout << "Tower of Hanoi solution for " << n << " disks:" << endl;
    towerOfHanoi(n, 'A', 'C', 'B');
    return 0;
}

