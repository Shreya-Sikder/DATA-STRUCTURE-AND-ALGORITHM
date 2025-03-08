/*You are given a list of tasks, where each task is represented as (StartTime, FinishTime).
 The goal is to sort the tasks based on their durations (calculated as FinishTime - StartTime) in ascending order.
  Input Output [(2, 5), (1, 2), (4, 6)] [(1, 3), (4, 6), (2, 5)]*/

#include <stdio.h>

int main() {
    int tasks[][2] = {{2, 5}, {1, 3}, {4, 6}};
    int n = sizeof(tasks) / sizeof(tasks[0]);
// Bubble sort based on duration (FinishTime - StartTime)
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            int duration1 = tasks[j][1] - tasks[j][0];       // Duration of task j
            int duration2 = tasks[j + 1][1] - tasks[j + 1][0]; // Duration of task j+1

            if (duration1 > duration2) {
                // Swap tasks[j] and tasks[j+1]
                int tempStart = tasks[j][0];
                int tempFinish = tasks[j][1];
                tasks[j][0] = tasks[j + 1][0];
                tasks[j][1] = tasks[j + 1][1];
                tasks[j + 1][0] = tempStart;
                tasks[j + 1][1] = tempFinish;
            }
        }
    }

    // Print the sorted tasks
    printf("Sorted tasks by duration:\n");
    for (int i = 0; i < n; i++) {
        printf("(%d, %d) ", tasks[i][0], tasks[i][1]);
    }
    printf("\n");

    return 0;
}
