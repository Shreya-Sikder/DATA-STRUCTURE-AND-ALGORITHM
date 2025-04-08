 /*Given an integer array nums, count the
number of smaller elements to the right
of nums[i].
Example 1: Input:nums = [5,2,6,1]  Output:[2,1,1,0]
Explanation: To the right of 5 there are 2 smaller elements (2 and 1). To the right of 2 there is only 1smaller element (1).
 To the right of 6 there is 1 smaller element (1). To the right of 1 there is 0 smaller element.
 Example 2:
Input:nums = [-1] Output:[0]
*/

#include <iostream>
#include <vector>
#include <climits>
using namespace std;

void mergeAndCount(vector<int>& nums, vector<int>& count, int low, int mid, int high) {
    vector<int> temp(nums);
    int j = mid + 1;
    int k = low;

    // Traverse the left and right subarrays and merge them
    for (int i = low; i <= mid; i++) {
        // While merging, count how many elements in the right subarray are smaller thannums[i]
        while (j <= high && nums[i] > nums[j]) {
            j++;
        }
        // Store the count of elements smaller than nums[i]
        count[i] += (j - mid - 1);
    }

    // Merge the subarrays back into temp
    for (int i = low; i <= high; i++) {
        nums[i] = temp[i];
    }
}

void countSmallerRecursive(vector<int>& nums, vector<int>& count, int low, int high) {
    if (low >= high) return;

    int mid = low + (high - low) / 2;

    // Recursively divide the array into two halves
    countSmallerRecursive(nums, count, low, mid);
    countSmallerRecursive(nums, count, mid + 1, high);

    // Merge and count smaller elements
    mergeAndCount(nums, count, low, mid, high);
}

vector<int> countSmaller(vector<int>& nums) {
    int n = nums.size();
    vector<int> count(n, 0);
    if (n == 0) return count;

    countSmallerRecursive(nums, count, 0, n - 1);

    return count;
}

int main() {
    vector<int> nums1 = {5, 2, 6, 1};
    vector<int> result1 = countSmaller(nums1);

    for (int num : result1) {
        cout << num << " ";
    }
    cout << endl;  // Output: [2, 1, 1, 0]

    vector<int> nums2 = {-1};
    vector<int> result2 = countSmaller(nums2);

    for (int num : result2) {
        cout << num << " ";
    }
    cout << endl;  // Output: [0]

    return 0;
}
