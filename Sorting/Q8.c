#include <stdio.h>
#include <string.h>

// Function to perform counting sort on a string
void countingSortString(char str[]) {
    int n = strlen(str);
    int count[26] = {0}; // Count array for 26 lowercase letters

    // Count the frequency of each letter
    for (int i = 0; i < n; i++) {
        count[str[i] - 'a']++;
    }

    // Reconstruct the sorted string
    int index = 0;
    for (int i = 0; i < 26; i++) {
        while (count[i] > 0) {
            str[index++] = 'a' + i;
            count[i]--;
        }
    }
}

int main() {
    char str[100];
    printf("Enter a lowercase string: ");
    scanf("%s", str);

    countingSortString(str);

    printf("Sorted string: %s\n", str);
    return 0;
}
