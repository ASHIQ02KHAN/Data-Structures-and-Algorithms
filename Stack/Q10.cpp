#include <iostream>
#include <stack>
using namespace std;

#define N 4

// Function to check if person A knows person B
bool knows(int M[N][N], int A, int B) {
    return M[A][B] == 1;
}

// Function to find the celebrity
int findCelebrity(int M[N][N], int n) {
    stack<int> s;

    // Push everyone onto the stack
    for (int i = 0; i < n; i++) {
        s.push(i);
    }

    // Compare two people and eliminate non-celebrities
    while (s.size() > 1) {
        int A = s.top(); s.pop();
        int B = s.top(); s.pop();

        if (knows(M, A, B)) {
            s.push(B);  // A knows B, so A is not a celebrity
        } else {
            s.push(A);  // B knows A, so B is not a celebrity
        }
    }

    int C = s.top();  // Possible celebrity

    // Verify if C is actually a celebrity
    for (int i = 0; i < n; i++) {
        if (i != C && (knows(M, C, i) || !knows(M, i, C))) {
            return -1;  // C is not a celebrity
        }
    }

    return C;
}

int main() {
    int M[N][N] = {{0, 1, 0, 0},
                   {0, 0, 0, 0},
                   {0, 1, 0, 0},
                   {0, 1, 0, 0}};

    int celebrity = findCelebrity(M, N);
    if (celebrity == -1)
        cout << "No Celebrity Found\n";
    else
        cout << "Celebrity is person " << celebrity << "\n";

    return 0;
}
