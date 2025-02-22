#include <stdio.h>

// Recursive binary search function
int recursiveBinarySearch(int arr[], int left, int right, int target) {
    if (left > right)
        return -1; // Base case: target not found

    int mid = left + (right - left) / 2;

    if (arr[mid] == target)
        return mid; // Target found
    else if (arr[mid] < target)
        return recursiveBinarySearch(arr, mid + 1, right, target); // Search right half
    else
        return recursiveBinarySearch(arr, left, mid - 1, target); // Search left half
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

    int result = recursiveBinarySearch(arr, 0, n - 1, target);

    if (result != -1)
        printf("Element found at index %d\n", result);
    else
        printf("Element not found.\n");

    return 0;
}
