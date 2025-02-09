#include <stdio.h>

// Counting Sort function
void countingSort(int arr[], int n) {
    // Step 1: Find the maximum element in the array
    int maxElement = arr[0];  // Assume the first element is the largest
    for (int i = 1; i < n; i++) {  // Loop through the rest of the array
        if (arr[i] > maxElement) {  // If a larger element is found
            maxElement = arr[i];  // Update maxElement
        }
    }

    // Step 2: Create and initialize the count array
    int count[maxElement + 1];  // Create a count array of size (maxElement + 1)
    for (int i = 0; i <= maxElement; i++) {  // Initialize all elements of the count array to 0
        count[i] = 0;
    }

    // Step 3: Count the frequency of each element
    for (int i = 0; i < n; i++) {  // Loop through the input array
        count[arr[i]]++;  // Increment the count at the index corresponding to the element
    }

    // Step 4: Update the count array to hold cumulative sums
    for (int i = 1; i <= maxElement; i++) {  // Loop through the count array
        count[i] += count[i - 1];  // Add the previous count to the current count
    }

    // Step 5: Create the output array
    int output[n];  // Create an array to store the sorted output
    for (int i = n - 1; i >= 0; i--) {  // Traverse the input array in reverse order
        output[count[arr[i]] - 1] = arr[i];  // Place the element at its sorted position
        count[arr[i]]--;  // Decrease the count for the element
    }

    // Step 6: Copy the sorted output array back into the original array
    for (int i = 0; i < n; i++) {  // Loop through the output array
        arr[i] = output[i];  // Copy each element back into the original array
    }
}

int main() {
    int n;

    // Input the number of elements
    printf("Enter the number of elements: ");
    scanf("%d", &n);  // Read the number of elements from the user

    int arr[n];  // Declare an array of size n

    // Input the array elements
    printf("Enter %d elements:\n", n);
    for (int i = 0; i < n; i++) {  // Loop to read n elements
        scanf("%d", &arr[i]);  // Read each element into the array
    }

    // Display the array before sorting
    printf("Before sorting:\n");
    for (int i = 0; i < n; i++) {  // Loop through the array
        printf("%d ", arr[i]);  // Print each element followed by a space
    }

    // Call the countingSort function to sort the array
    countingSort(arr, n);  // Pass the array and its size to the sorting function

    // Display the array after sorting
    printf("\nSorted array:\n");
    for (int i = 0; i < n; i++) {  // Loop through the sorted array
        printf("%d ", arr[i]);  // Print each sorted element followed by a space
    }

    return 0;
}
