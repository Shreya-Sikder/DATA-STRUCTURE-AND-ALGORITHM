#include<bits/stdc++.h>
using namespace std;


    int coinChange(vector<int>& coins, int amount) {
        const int INF = 1e9; // Use a large value as infinity
        vector<int> dp(amount + 1, INF); // dp[i] = min coins to make i
        dp[0] = 0; // Base case: 0 coins to make 0

        for (int coin : coins) {
            for (int i = coin; i <= amount; i++) {
                dp[i] = min(dp[i], dp[i - coin] + 1);
            }
        }

        return dp[amount] == INF ? -1 : dp[amount];
    }


int main() {

    vector<int> coins = {1, 2, 5};
    int amount = 11;

    int result = coinChange(coins, amount);
    cout << "Minimum coins required: " << result << endl;

    return 0;
}
