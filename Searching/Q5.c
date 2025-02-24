#include <stdio.h>

// Function to find the smallest missing number using binary search
int findMissingNumber(int arr[], int n) {
    int left = 0, right = n - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (arr[mid] == mid) {
            left = mid + 1;  // The missing number is in the right half
        } else {
            right = mid - 1;  // The missing number is in the left half
        }
    }

    return left;  // The missing number is at index 'left'
}

int main() {
    int n;
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter %d sorted elements starting from 0:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    int missingNumber = findMissingNumber(arr, n);
    printf("The smallest missing number is: %d\n", missingNumber);

    return 0;
}
