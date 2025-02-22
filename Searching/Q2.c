#include <stdio.h>

// Function to find the first occurrence of target using binary search
int firstOccurrence(int arr[], int n, int target) {
    int left = 0, right = n - 1, result = -1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (arr[mid] == target) {
            result = mid;  // Store the index
            right = mid - 1; // Search the left half for earlier occurrences
        } else if (arr[mid] < target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    return result;
}

// Function to find the last occurrence of target using binary search
int lastOccurrence(int arr[], int n, int target) {
    int left = 0, right = n - 1, result = -1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (arr[mid] == target) {
            result = mid;  // Store the index
            left = mid + 1; // Search the right half for later occurrences
        } else if (arr[mid] < target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    return result;
}

int main() {
    int n, target;

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter %d sorted elements:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Enter the element to search: ");
    scanf("%d", &target);

    int first = firstOccurrence(arr, n, target);
    int last = lastOccurrence(arr, n, target);

    if (first != -1)
        printf("First occurrence at index %d\n", first);
    else
        printf("Element not found.\n");

    if (last != -1)
        printf("Last occurrence at index %d\n", last);

    return 0;
}
