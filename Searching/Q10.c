#include <stdio.h>

// Function to find the smallest missing positive number
int findSmallestMissingPositive(int arr[], int n) {
    int found[n + 1]; // Array to track presence of numbers (1 to n)

    // Initialize all values to 0 (not found)
    for (int i = 0; i <= n; i++) {
        found[i] = 0;
    }

    // Mark the presence of numbers between 1 and n
    for (int i = 0; i < n; i++) {
        if (arr[i] > 0 && arr[i] <= n) {
            found[arr[i]] = 1;
        }
    }

    // Find the first missing positive number
    for (int i = 1; i <= n; i++) {
        if (found[i] == 0) {
            return i;
        }
    }

    return n + 1; // If no missing number found, return next number after n
}

int main() {
    int n;

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter %d elements:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    int missingNumber = findSmallestMissingPositive(arr, n);
    printf("The smallest missing positive number is: %d\n", missingNumber);

    return 0;
}
