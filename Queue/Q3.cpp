#include <iostream>
#include <queue>
#include <unordered_map>

using namespace std;

void findFirstNonRepeating(string str) {
    queue<char> q;
    unordered_map<char, int> freq;

    for (char ch : str) {
        freq[ch]++;
        q.push(ch);

        while (!q.empty() && freq[q.front()] > 1) {
            q.pop();
        }

        if (!q.empty()) {
            cout << q.front() << " ";
        } else {
            cout << "-1 ";
        }
    }
    cout << "\n";
}

int main() {
    string stream = "aabcabb";
    cout << "Stream: " << stream << "\n";
    cout << "First non-repeating characters: ";
    findFirstNonRepeating(stream);
    return 0;
}
