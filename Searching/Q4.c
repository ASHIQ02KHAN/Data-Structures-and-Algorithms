#include <stdio.h>

// Function to find a peak element using binary search
int findPeakElement(int arr[], int n) {
    int left = 0, right = n - 1;

    while (left < right) {
        int mid = left + (right - left) / 2;

        if (arr[mid] > arr[mid + 1]) {
            right = mid;  // Peak is in the left half
        } else {
            left = mid + 1;  // Peak is in the right half
        }
    }

    return left;  // Return the index of a peak element
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

    int peakIndex = findPeakElement(arr, n);
    printf("Peak element found at index: %d (value: %d)\n", peakIndex, arr[peakIndex]);

    return 0;
}
