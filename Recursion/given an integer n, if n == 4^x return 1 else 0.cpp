
#include <iostream>
using namespace std;

int isPowerOfFour(int n) {
    // Base case: 1 is 4^0
    if (n == 1) return 1;
    // If n is less than 4 or not divisible by 4, it can't be a power of 4
    if (n < 4 || n % 4 != 0) return 0;
    // Recursive step: check n / 4
    return isPowerOfFour(n / 4);
}
int main() {
    int n;
    cout << "Enter an integer: ";
    cin >> n;

    if (isPowerOfFour(n))
        cout << n << " is a power of 4." << endl;
    else
        cout << n << " is not a power of 4." << endl;

    return 0;
}
