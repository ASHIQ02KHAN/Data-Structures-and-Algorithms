#include <iostream>
#include <queue>

using namespace std;

// Recursive function to reverse a queue
void reverseQueue(queue<int> &q) {
    if (q.empty()) return;

    int front = q.front();
    q.pop();
    reverseQueue(q);
    q.push(front);
}

int main() {
    queue<int> q;
    q.push(10);
    q.push(20);
    q.push(30);
    q.push(40);

    cout << "Original Queue: ";
    queue<int> temp = q;
    while (!temp.empty()) {
        cout << temp.front() << " ";
        temp.pop();
    }
    cout << "\n";

    reverseQueue(q);

    cout << "Reversed Queue: ";
    while (!q.empty()) {
        cout << q.front() << " ";
        q.pop();
    }
    cout << "\n";

    return 0;
}
