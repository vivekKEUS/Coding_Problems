#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
  int greedyApproach(vector<int> &coins, int a) {
    // this greedy approach wont work
    sort(coins.rbegin(), coins.rend());
    int count = 0;
    int i = 0;
    while (i < coins.size() and a) {
      count += a / coins[i];
      a = a % coins[i];
      i++;
    }
    if (a != 0)
      return -1;
    return count;
  }
  int coinChange(vector<int> &coins, int amount) {
    vector<int> dp(amount + 1, amount + 1);
    dp[0] = 0;
    for (int i = 1; i <= amount; ++i) {
      for (int coin : coins) {
        if (i >= coin) {
          dp[i] = min(dp[i], dp[i - coin] + 1);
        }
      }
    }
    return dp[amount] > amount ? -1 : dp[amount];
  }
};
  int main() {
    Solution solution;
    vector<int> coins = {186, 419, 83, 408};
    int amount = 6249;

    int result = solution.coinChange(coins, amount);

    cout << "Minimum number of coins needed: " << result << endl;

    return 0;
  }
