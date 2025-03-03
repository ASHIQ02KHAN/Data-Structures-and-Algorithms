#include <iostream>
#include <queue>

using namespace std;

void generateBinaryNumbers(int N) {
    queue<string> q;
    q.push("1");

    for (int i = 0; i < N; i++) {
        string front = q.front();
        q.pop();
        cout << front << " ";

        q.push(front + "0");
        q.push(front + "1");
    }
    cout << "\n";
}

int main() {
    int N = 5;
    cout << "Binary numbers from 1 to " << N << ": ";
    generateBinaryNumbers(N);
    return 0;
}
