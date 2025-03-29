#include <iostream>
using namespace std;

int countWays(int n) {

    // Base case for 0th stair
    if (n == 0) return 1;

    // For invalid stair, return 0.
    if (n < 0) return 0;

    // Count number of ways to reach (n-1), (n-2),
    // (n-3) stair
    return countWays(n - 1) + countWays(n - 2) + countWays(n - 3);
}

int main() {

    int n;
    cin>>n;
    countWays(n);
    cout << countWays(n) << endl;
    return 0;
}
