/*You are given two arrays a and b. Merge a and b into a single array sorted in non-decreasing order.
 Input Output a = [1,16,13,14,4] b = [15,12,5,3,7] [1,3,4,5,7,12,13,14,15,16]*/

#include <stdio.h>

int main() {
    int n, m;

    // Input size of first array
    printf("Enter the number of elements in the first array: ");
    scanf("%d", &n);

    int a[n];
    printf("Enter %d elements for the first array:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    // Input size of second array
    printf("Enter the number of elements in the second array: ");
    scanf("%d", &m);

    int b[m];
    printf("Enter %d elements for the second array:\n", m);
    for (int i = 0; i < m; i++) {
        scanf("%d", &b[i]);
    }

    // Merge the two arrays
        int merged[n + m];
    for (int i = 0; i < n; i++) {
        merged[i] = a[i];
    }
    for (int i = 0; i < m; i++) {
        merged[n + i] = b[i];
    }

    // Total size of the merged array
    int size = n + m;

    // Bubble sort the merged array
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (merged[j] > merged[j + 1]) {
                // Swap
                int temp = merged[j];
                merged[j] = merged[j + 1];
                merged[j + 1] = temp;
            }
        }
    }

    // Print the sorted merged array
    printf("Merged and sorted array: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", merged[i]);
    }
    printf("\n");

    return 0;
}

