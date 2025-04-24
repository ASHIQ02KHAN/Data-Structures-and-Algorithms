#include <iostream>
#include <unordered_set>
#include <queue>
using namespace std;

int wordLadder(string begin, string end, vector<string>& wordList) {
    unordered_set<string> dict(wordList.begin(), wordList.end());
    if (!dict.count(end)) return 0;

    queue<pair<string, int>> q;
    q.push({begin, 1});

    while (!q.empty()) {
        auto [word, steps] = q.front(); q.pop();

        if (word == end) return steps;

        for (int i = 0; i < word.size(); i++) {
            char original = word[i];
            for (char c = 'a'; c <= 'z'; c++) {
                word[i] = c;
                if (dict.count(word)) {
                    q.push({word, steps + 1});
                    dict.erase(word);
                }
            }
            word[i] = original;
        }
    }

    return 0; // No transformation path
}

int main() {
    vector<string> wordList = {"hot","dot","dog","lot","log","cog"};
    string begin = "hit", end = "cog";

    cout << "Shortest Transformation Steps: " << wordLadder(begin, end, wordList) << endl;
    return 0;
}
