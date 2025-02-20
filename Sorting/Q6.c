#include <stdio.h>

// Function to perform insertion sort while counting comparisons and shifts
void insertionSortWithCounters(int arr[], int n, int *comparisons, int *shifts) {
    *comparisons = 0;
    *shifts = 0;

    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;

        // Compare key with each element in the sorted subarray
        while (j >= 0 && arr[j] > key) {
            (*comparisons)++; // One comparison in the while condition
            arr[j + 1] = arr[j];
            (*shifts)++;      // One shift for moving arr[j] right
            j--;
        }

        // When while loop exits, we have made one more comparison that fails
        if(j >= 0)
            (*comparisons)++;

        arr[j + 1] = key;
        (*shifts)++; // Inserting the key is considered a shift
    }
}

int main() {
    int n;
    int comparisons, shifts;

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter %d elements:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    insertionSortWithCounters(arr, n, &comparisons, &shifts);

    printf("Sorted array (ascending order):\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    printf("Total comparisons: %d\n", comparisons);
    printf("Total shifts: %d\n", shifts);

    return 0;
}
