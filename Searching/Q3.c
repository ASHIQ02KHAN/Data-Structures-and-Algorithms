#include <stdio.h>

// Function to find the square root using binary search
int squareRoot(int num) {
    if (num == 0 || num == 1)
        return num;  // Base case: sqrt(0) = 0, sqrt(1) = 1

    int left = 1, right = num, ans = 0;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (mid * mid == num)
            return mid; // If mid^2 == num, we found the exact square root

        if (mid * mid < num) {
            left = mid + 1;  // Search in the right half
            ans = mid;  // Store the floor value
        } else {
            right = mid - 1;  // Search in the left half
        }
    }

    return ans; // Return the integer part of the square root
}

int main() {
    int num;
    printf("Enter a number: ");
    scanf("%d", &num);

    printf("Square root (floor value) of %d is: %d\n", num, squareRoot(num));

    return 0;
}
