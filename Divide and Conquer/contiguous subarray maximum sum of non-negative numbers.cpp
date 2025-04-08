/* You have an array of integers where some
elements may be negative, zero, or positive.
Your goal is to find the contiguous subarray
(subarray with consecutive elements) with the
maximum sum of non-negative numbers. Note
that, the subarray shouldn’t have any negative
number.*/


#include <bits/stdc++.h>

using namespace std;

// Function to find the maximum sum subarray with only non-negative numbers in a given range
int maxSubarraySumNonNegative(vector<int>& arr, int low, int high) {
    // Base case: If the subarray has only one element
    if (low == high) {
        return (arr[low] >= 0) ? arr[low] : 0;  // Ignore negative numbers
    }

    // Find the middle index of the current subarray
    int mid = low + (high - low) / 2;

    // Recursively find the maximum sum subarray for the left and right halves
    int leftMaxSum = maxSubarraySumNonNegative(arr, low, mid);
    int rightMaxSum = maxSubarraySumNonNegative(arr, mid + 1, high);

    // Combine results:
    // We need to check if there is a subarray that spans across the middle
    int leftCrossSum = 0;
    int currentSum = 0;
    for (int i = mid; i >= low; i--) {
        if (arr[i] >= 0) {
            currentSum += arr[i];
            leftCrossSum = max(leftCrossSum, currentSum);
        } else {
            break;  // Stop if we encounter a negative number
        }
    }

    int rightCrossSum = 0;
    currentSum = 0;
    for (int i = mid + 1; i <= high; i++) {
        if (arr[i] >= 0) {
            currentSum += arr[i];
            rightCrossSum = max(rightCrossSum, currentSum);
        } else {
            break;  // Stop if we encounter a negative number
        }
    }

    // Return the maximum sum among the left half, right half, and the combined subarray
    return max({leftMaxSum, rightMaxSum, leftCrossSum + rightCrossSum});
}

int maxSumNonNegativeSubarray(vector<int>& arr) {
    int n = arr.size();
    return maxSubarraySumNonNegative(arr, 0, n - 1);
}

int main() {
    vector<int> arr = {1, 2, 5, -7, 2, 3};

    cout << "Maximum sum of non-negative subarray: " << maxSumNonNegativeSubarray(arr)
<< endl;

    return 0;
}
