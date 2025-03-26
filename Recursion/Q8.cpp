#include <iostream>
using namespace std;

// Recursive function to generate subsequences
void printSubsequences(string str, string output, int index) {
    if (index == str.length()) { // Base case: End of string
        cout << "\"" << output << "\"\n"; // Print subsequence
        return;
    }

    // Include current character
    printSubsequences(str, output + str[index], index + 1);

    // Exclude current character
    printSubsequences(str, output, index + 1);
}

int main() {
    string str = "abc";
    cout << "Subsequences of \"" << str << "\":\n";
    printSubsequences(str, "", 0);
    return 0;
}
