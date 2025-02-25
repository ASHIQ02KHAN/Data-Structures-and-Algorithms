#include <stdio.h>

// Function to find first and last occurrences using linear search
void findFirstLastOccurrence(int arr[], int n, int target, int *first, int *last) {
    *first = -1;
    *last = -1;

    for (int i = 0; i < n; i++) {
        if (arr[i] == target) {
            if (*first == -1) {
                *first = i; // Store first occurrence
            }
            *last = i; // Update last occurrence
        }
    }
}

int main() {
    int n, target, first, last;

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter %d elements:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Enter the element to search: ");
    scanf("%d", &target);

    findFirstLastOccurrence(arr, n, target, &first, &last);

    if (first != -1)
        printf("First occurrence at index %d\nLast occurrence at index %d\n", first, last);
    else
        printf("Element not found.\n");

    return 0;
}
