#include <iostream>
#include <stack>
using namespace std;

// Function to find the largest rectangular area in a histogram
int largestRectangleArea(int heights[], int n) {
    stack<int> s;
    int maxArea = 0, i = 0;

    while (i < n) {
        if (s.empty() || heights[i] >= heights[s.top()]) {
            s.push(i++);
        } else {
            int h = heights[s.top()];
            s.pop();
            int width = s.empty() ? i : i - s.top() - 1;
            maxArea = max(maxArea, h * width);
        }
    }

    while (!s.empty()) {
        int h = heights[s.top()];
        s.pop();
        int width = s.empty() ? i : i - s.top() - 1;
        maxArea = max(maxArea, h * width);
    }

    return maxArea;
}

int main() {
    int heights[] = {2, 1, 5, 6, 2, 3};
    int n = sizeof(heights) / sizeof(heights[0]);
    cout << "Largest Rectangle Area: " << largestRectangleArea(heights, n) << endl;
    return 0;
}
