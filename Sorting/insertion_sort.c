#include <stdio.h>

// Function to swap two elements
void swap(int* xp, int* yp) {
    int temp = *xp;  // Store the value of the first element in a temporary variable
    *xp = *yp;       // Assign the value of the second element to the first element
    *yp = temp;      // Assign the value of the temporary variable (original first element) to the second element
}

// Function to perform insertion sort
void insertionSort(int arr[], int n) {
    int i, j, key;
    for (i = 1; i < n; i++) { // Loop through the array starting from the second element
        key = arr[i];         // Select the current element as the "key"
        j = i - 1;            // Start comparing with the previous elements

        // Shift elements of the sorted portion that are greater than the key
        while (j >= 0 && arr[j] > key) { // descending (<)
            arr[j + 1] = arr[j]; // Move the element one position to the right
            j = j - 1;           // Move to the previous element
        }

        arr[j + 1] = key; // Insert the key in its correct position
    }
}

int main() {
    int n;

    // Input the number of elements
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    if (n <= 0) { // Check for invalid input
        printf("Invalid number of elements.\n");
        return 0;
    }

    int arr[n]; // Declare an array of size n

    // Input array elements
    printf("Enter %d elements:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Before sorting:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]); // Print each element of the unsorted array
    }

    insertionSort(arr, n); // Call the insertion sort function to sort the array

    printf("\nSorted array:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]); // Print each element of the sorted array
    }

    return 0; // Return 0 to indicate successful execution
}
