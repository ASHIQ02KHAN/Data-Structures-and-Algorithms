#include <stdio.h>
// Include the standard input-output header file for functions like `printf` and `scanf`.

int binarySearch(int a[], int n, int data) {
    // Function to perform binary search.
    // Parameters:
    // `a[]` - the array of integers (assumed to be sorted).
    // `n` - the size of the array.
    // `data` - the element to search for.

    int l, r, mid;
    // `l` (left) - the starting index of the search range.
    // `r` (right) - the ending index of the search range.
    // `mid` - the middle index of the current search range.

    l = 0;
    // Initialize `l` to 0 (start of the array).
    r = n - 1;
    // Initialize `r` to `n-1` (end of the array).

    while (l <= r) {
        // Loop continues as long as the search range is valid (`l` <= `r`).
        mid = (l + r) / 2;
        // Calculate the middle index of the current search range.

        if (data == a[mid]) {
            // If the element at the middle index matches the target:
            return mid;
            // Return the index of the target element.
        } else if (data > a[mid]) {
            // If the target element is greater than the middle element:
            l = mid + 1;
            // Narrow the search range to the right half (`l` becomes `mid + 1`).
        } else {
            // If the target element is less than the middle element:
            r = mid - 1;
            // Narrow the search range to the left half (`r` becomes `mid - 1`).
        }
    }

    return -1;
    // If the loop exits without finding the target, return -1 (element not found).
}

int main() {
    int n, data;
    // `n` - the number of elements in the array.
    // `data` - the element to search for.

    printf("Enter the number of elements: ");
    // Prompt the user to enter the size of the array.
    scanf("%d", &n);
    // Read the size of the array.

    int a[n];
    // Declare an array `a` of size `n`.

    printf("Enter %d sorted elements:\n", n);
    // Prompt the user to enter the sorted array elements.
    for (int i = 0; i < n; i++) {
        // Loop to input all elements into the array.
        scanf("%d", &a[i]);
        // Read each element and store it in `a[i]`.
    }

    printf("Enter the element to search: ");
    // Prompt the user to input the element to search for.
    scanf("%d", &data);
    // Read the target element.

    int result = binarySearch(a, n, data);
    // Call the `binarySearch` function and store the result (index or -1) in `result`.

    if (result != -1) {
        // If the result is not -1, the element was found:
        printf("Element found at index %d\n", result);
        // Print the index of the found element.
    } else {
        // If the result is -1, the element was not found:
        printf("Element not found.\n");
        // Print a message indicating the element was not found.
    }

    return 0;
    // Return 0 to indicate successful program execution.
}
