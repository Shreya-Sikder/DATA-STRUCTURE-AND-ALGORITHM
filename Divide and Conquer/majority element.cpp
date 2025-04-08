/*Given an array of size n, return the
majority element.The majority element is the
element that appears more than ⌊n/2⌋ times.
You may assume that the majority element
always exists in the array.*/


#include <bits/stdc++.h>
using namespace std;

// Function to find the majority element in the array from index 'low' to 'high'
int majorityElementRecursive(vector<int>& arr, int low, int high) {
    // Base case: If the subarray has only one element
    if (low == high) {
        return arr[low];
    }

    // Find the mid point of the array
    int mid = low + (high - low) / 2;

    // Recursively find the majority element in the left and right halves
    int leftMajority = majorityElementRecursive(arr, low, mid);
    int rightMajority = majorityElementRecursive(arr, mid + 1, high);

    // If both halves have the same majority element, return it
    if (leftMajority == rightMajority) {
        return leftMajority;
    }

    // Count occurrences of leftMajority and rightMajority in the current subarray
    int leftCount = count(arr.begin() + low, arr.begin() + high + 1, leftMajority);
    int rightCount = count(arr.begin() + low, arr.begin() + high + 1, rightMajority);

    // Return the majority element based on the count
    if (leftCount > rightCount) {
        return leftMajority;
    } else {
        return rightMajority;
    }
}

int majorityElement(vector<int>& arr) {
    return majorityElementRecursive(arr, 0, arr.size() - 1);
}

int main() {
    vector<int> arr = {3, 3, 4, 2, 4, 4, 2, 4, 4};

    // Find and print the majority element
    cout << "Majority element: " << majorityElement(arr) << endl;

    return 0;
}


