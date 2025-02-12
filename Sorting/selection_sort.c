#include <stdio.h>

// Function to swap two elements
void swap(int* xp, int* yp) {
    int temp = *xp;  // Store the value of the first element in a temporary variable
    *xp = *yp;       // Assign the value of the second element to the first element
    *yp = temp;      // Assign the value of the temporary variable (original first element) to the second element
}

// Function to perform selection sort
void selectionSort(int arr[], int n) {
    int i, j;

    for (i = 0; i < n - 1; i++) { // Outer loop to iterate through the array
        int min_index = i;        // Assume the current element is the minimum in the unsorted portion

        for (j = i + 1; j < n; j++) { // Inner loop to find the smallest element in the unsorted portion
            if (arr[j] < arr[min_index]) { // Compare current element with the assumed minimum #for descending (>)
                min_index = j;            // Update the index of the minimum element
            }
        }

        swap(&arr[i], &arr[min_index]); // Swap the current element with the smallest element found
    }
}

int main() {
    int n; // Variable to store the number of elements

    printf("Enter the number of elements: "); // Prompt the user to input the size of the array
    scanf("%d", &n); // Read the number of elements

    int arr[n]; // Declare an array of size n

    printf("Enter %d elements:\n", n); // Prompt the user to input the elements
    for (int i = 0; i < n; i++) { // Loop to input each element of the array
        scanf("%d", &arr[i]); // Read each element
    }

    printf("Before sorting:\n"); // Print the array before sorting
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]); // Print each element of the unsorted array
    }

    selectionSort(arr, n); // Call the selection sort function to sort the array

    printf("\nSorted array:\n"); // Print the array after sorting
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]); // Print each element of the sorted array
    }

    return 0; // Return 0 to indicate successful execution
}
