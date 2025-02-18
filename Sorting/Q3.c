#include <stdio.h>

// Bubble sort function with counters for swaps and comparisons
void bubbleSortWithCounters(int arr[], int n) {
    int swapCount = 0;
    int comparisonCount = 0;

    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - 1 - i; j++) {
            comparisonCount++;  // Increment the comparison counter
            if (arr[j] > arr[j + 1]) {
                // Swap elements
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                swapCount++;  // Increment the swap counter
            }
        }
    }

    printf("Total comparisons: %d\n", comparisonCount);
    printf("Total swaps: %d\n", swapCount);
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

    bubbleSortWithCounters(arr, n);

    printf("Sorted array (ascending order):\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    return 0;
}
