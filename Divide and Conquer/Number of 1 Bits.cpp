#include <iostream>
using namespace std;

// Function to count set bits using divide and conquer
int countSetBits(int n) {
    if (n == 0) return 0;
    return 1 + countSetBits(n & (n - 1)); // Remove the lowest set bit and recurse
}

int main() {
    int num;
    cout << "Enter a number: ";
    cin >> num;

    cout << "Number of 1 bits: " << countSetBits(num) << endl;
    return 0;
}
