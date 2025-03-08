/*Sort an Array of Strings according to length.
 Input Output a = ["apple", "bat", "carrot", "dog"] ["bat", "dog", "apple", "carrot"]*/

#include <stdio.h>
#include <string.h>

int main() {
    int n;

    // Prompt user for the number of strings
    printf("Enter the number of strings: ");
    scanf("%d", &n);

    // Declare the array to hold strings (maximum 20 characters per string)
    char a[n][20];

    // Input strings from the user
    printf("Enter the strings:\n");
    for (int i = 0; i < n; i++) {
        scanf("%s", a[i]);  // Read each string
    }

    // Bubble sort by length of strings
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (strlen(a[j]) > strlen(a[j + 1])) {
                // Swap strings
                                char temp[20];
                strcpy(temp, a[j]);
                strcpy(a[j], a[j + 1]);
                strcpy(a[j + 1], temp);
            }
        }
    }

    // Print sorted array
    printf("Sorted array: ");
    for (int i = 0; i < n; i++) {
        printf("%s ", a[i]);
    }
    printf("\n");

    return 0;
}

