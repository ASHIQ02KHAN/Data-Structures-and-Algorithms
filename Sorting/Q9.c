#include <stdio.h>

// Function to perform counting sort and display element frequencies
void countingSortWithFrequencies(int arr[], int n) {
    int max = arr[0];

    // Find the maximum element
    for (int i = 1; i < n; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }

    int count[max + 1]; // Count array

    // Initialize count array to 0
    for (int i = 0; i <= max; i++) {
        count[i] = 0;
    }

    // Count the frequency of each element
    for (int i = 0; i < n; i++) {
        count[arr[i]]++;
    }

    // Display frequencies
    printf("Element frequencies:\n");
    for (int i = 0; i <= max; i++) {
        if (count[i] > 0) {
            printf("Element %d: %d times\n", i, count[i]);
        }
    }

    // Write sorted elements back to the array
    int index = 0;
    for (int i = 0; i <= max; i++) {
        while (count[i] > 0) {
            arr[index++] = i;
            count[i]--;
        }
    }
}

int main() {
    int n;
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter %d non-negative elements:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    countingSortWithFrequencies(arr, n);

    printf("Sorted array (ascending order):\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    return 0;
}
