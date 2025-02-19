#include <stdio.h>

// Binary search function to find the insertion index for key in arr[low...high]
int binarySearch(int arr[], int low, int high, int key) {
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (arr[mid] == key)
            return mid + 1; // Insert after any equal elements
        else if (arr[mid] < key)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return low; // The insertion index
}

// Insertion sort using binary search for finding insertion index
void insertionSortBinary(int arr[], int n) {
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        // Find the insertion index in the sorted subarray arr[0...i-1]
        int insertPos = binarySearch(arr, 0, i - 1, key);

        // Shift elements to create space for the key
        int j = i - 1;
        while (j >= insertPos) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[insertPos] = key;
    }
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

    insertionSortBinary(arr, n);

    printf("Sorted array using binary insertion sort (ascending order):\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    return 0;
}
