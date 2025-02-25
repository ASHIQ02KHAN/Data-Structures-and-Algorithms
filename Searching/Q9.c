#include <stdio.h>

// Function to find max and min using linear search
void findMaxMin(int arr[], int n, int *max, int *min) {
    *max = arr[0];
    *min = arr[0];

    for (int i = 1; i < n; i++) {
        if (arr[i] > *max) {
            *max = arr[i];
        }
        if (arr[i] < *min) {
            *min = arr[i];
        }
    }
}

int main() {
    int n, max, min;

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter %d elements:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    findMaxMin(arr, n, &max, &min);

    printf("Maximum value: %d\nMinimum value: %d\n", max, min);

    return 0;
}
