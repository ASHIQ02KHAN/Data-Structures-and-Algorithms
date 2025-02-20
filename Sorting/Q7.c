#include <stdio.h>
#include <limits.h>

// Function to perform counting sort for both positive and negative integers
void countingSortWithNegatives(int arr[], int n) {
    int min = INT_MAX, max = INT_MIN;

    // Find the minimum and maximum elements
    for (int i = 0; i < n; i++) {
        if (arr[i] < min) min = arr[i];
        if (arr[i] > max) max = arr[i];
    }

    int range = max - min + 1; // Range of elements
    int count[range];

    // Initialize the count array
    for (int i = 0; i < range; i++) {
        count[i] = 0;
    }

    // Count the frequency of each element
    for (int i = 0; i < n; i++) {
        count[arr[i] - min]++;
    }

    // Write sorted elements back to the original array
    int index = 0;
    for (int i = 0; i < range; i++) {
        while (count[i] > 0) {
            arr[index++] = i + min;
            count[i]--;
        }
    }
}

int main() {
    int n;
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter %d elements (can include negatives):\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    countingSortWithNegatives(arr, n);

    printf("Sorted array (ascending order):\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    return 0;
}
