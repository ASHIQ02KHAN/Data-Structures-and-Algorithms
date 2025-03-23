#include <iostream>
using namespace std;

// Recursive function to reverse a string
void reverseString(string &str, int left, int right) {
    if (left >= right) return; // Base case
    swap(str[left], str[right]); // Swap characters
    reverseString(str, left + 1, right - 1); // Recursive call
}

int main() {
    string str = "hello";
    reverseString(str, 0, str.length() - 1);
    cout << "Reversed String: " << str << endl;
    return 0;
}
