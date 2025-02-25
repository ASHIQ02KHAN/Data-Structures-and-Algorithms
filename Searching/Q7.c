#include <stdio.h>

// Function to count occurrences of a number using linear search
int countOccurrences(int arr[], int n, int target) {
    int count = 0;
    for (int i = 0; i < n; i++) {
        if (arr[i] == target) {
            count++; // Increment count when target is found
        }
    }
    return count;
}

int main() {
    int n, target;

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter %d elements:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Enter the element to count: ");
    scanf("%d", &target);

    int occurrences = countOccurrences(arr, n, target);
    printf("Element %d appears %d times.\n", target, occurrences);

    return 0;
}
