#include <stdio.h> // Include the standard input/output library for printf and scanf functions

// Function to swap two elements
void swap(int* xp, int* yp) {
    int temp = *xp;  // Store the value of the first element in a temporary variable
    *xp = *yp;       // Assign the value of the second element to the first element
    *yp = temp;      // Assign the value of the temporary variable (original first element) to the second element
}

// Bubble Sort with a flag for optimization
void bubbleSort(int arr[], int n) {
    int i, j, flag; // Declare variables for the loops and a flag to detect swaps

    for (i = 0; i < n - 1; i++) { // Outer loop runs for each pass of the array (n-1 passes)
        flag = 0; // Reset the flag to 0 at the start of each pass

        for (j = 0; j < n - 1 - i; j++) { // Inner loop for comparing adjacent elements
            if (arr[j] < arr[j + 1]) { // Compare current element with the next (descending order) ascending(>)
                swap(&arr[j], &arr[j + 1]); // Swap the elements if they are out of order
                flag = 1; // Mark that a swap occurred
            }
        }

        if (flag == 0) // If no swaps occurred during the pass
            break;     // Exit the loop early as the array is already sorted
    }
}

int main() {
    int n; // Variable to store the number of elements in the array

    printf("Enter the number of elements: "); // Prompt the user to input the number of elements
    scanf("%d", &n); // Read the number of elements from the user

    int arr[n]; // Declare an array of size 'n'

    printf("Enter %d elements:\n", n); // Prompt the user to input the elements
    for (int i = 0; i < n; i++) { // Loop through the array
        scanf("%d", &arr[i]); // Read each element from the user
    }

    printf("Before sorting:\n"); // Print message before displaying the unsorted array
    for (int i = 0; i < n; i++) { // Loop through the array
        printf("%d ", arr[i]); // Print each element of the unsorted array
    }

    bubbleSort(arr, n); // Call the bubble sort function to sort the array

    printf("\nSorted array:\n"); // Print message before displaying the sorted array
    for (int i = 0; i < n; i++) { // Loop through the sorted array
        printf("%d ", arr[i]); // Print each element of the sorted array
    }

    return 0; // Return 0 to indicate successful execution
}
