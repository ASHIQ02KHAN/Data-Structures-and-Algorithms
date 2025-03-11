#include <iostream>
#include <stack>
#include <vector>

using namespace std;

// Function to find the next greater element for each element
vector<int> nextGreaterElement(vector<int> arr) {
    int n = arr.size();
    vector<int> result(n, -1);
    stack<int> s;

    for (int i = n - 1; i >= 0; i--) {
        while (!s.empty() && s.top() <= arr[i]) {
            s.pop(); // Remove smaller elements
        }
        if (!s.empty()) {
            result[i] = s.top(); // Next greater element
        }
        s.push(arr[i]);
    }

    return result;
}

int main() {
    vector<int> arr = {4, 5, 2, 25};
    vector<int> result = nextGreaterElement(arr);

    cout << "Next Greater Elements: ";
    for (int i = 0; i < arr.size(); i++) {
        cout << arr[i] << " -> " << result[i] << ", ";
    }
    cout << endl;
    return 0;
}
