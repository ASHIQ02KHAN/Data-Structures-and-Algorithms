#include <stdio.h>
// Includes the standard input-output header file, allowing us to use functions like `printf` and `scanf`.

int main() {
    int n, s_data, found = 0;
    // Declares three variables:
    // `n` - the number of elements in the array.
    // `s_data` - the element to search for.
    // `found` - a flag variable initialized to 0, which will indicate whether the element was found.

    // Input the number of elements
    printf("Enter the number of elements: ");
    // Prompts the user to enter the size of the array.
    scanf("%d", &n);
    // Reads the integer input from the user and stores it in `n`.

    int a[n];
    // Declares an array `a` of size `n` to hold the elements.

    // Input the array elements
    printf("Enter %d elements:\n", n);
    // Prompts the user to enter `n` elements to populate the array.
    for (int i = 0; i < n; i++) {
        // Loops from 0 to `n-1` to take inputs for all array elements.
        scanf("%d", &a[i]);
        // Reads each element entered by the user and stores it in `a[i]`.
    }

    // Input the element to search for
    printf("Enter the element to search: ");
    // Prompts the user to enter the value they want to search for in the array.
    scanf("%d", &s_data);
    // Reads the target value and stores it in `s_data`.

    // Linear search algorithm
    for (int i = 0; i < n; i++) {
        // Loops through the array from the first element (`i = 0`) to the last (`i = n-1`).
        if (a[i] == s_data) {
            // Compares the current array element (`a[i]`) with the target value (`s_data`).
            printf("Data found at index %d\n", i);
            // If a match is found, prints the index of the matched element.
            found = 1;
            // Sets the `found` flag to 1, indicating that the element was found.
            break;
            // Exits the loop early since the target element has been found.
        }
    }

    // If the element is not found
    if (found == 0) {
        // Checks if the `found` flag is still 0 after the loop.
        printf("Data not found.\n");
        // If `found` is 0, it means the target element was not in the array. Prints a message accordingly.
    }

    return 0;
    // Returns 0 to indicate that the program executed successfully.
}
