#include <bits/stdc++.h>
#include <gtest/gtest.h>
using namespace std;

class Solution {
  public:
    int coinChange(vector<int> &coins, int amount) {
        vector<int> dp(amount + 1, INT_MAX);
        dp[0] = 0;
        for (int coin : coins) {
            for (int i = coin; i <= amount; i++) {
                if (dp[i - coin] != INT_MAX) {
                    dp[i] = min(1 + dp[i - coin], dp[i]);
                }
            }
        }
        return dp[amount] == INT_MAX ? -1 : dp[amount];
    }
};

class Solution1 {
  public:
    int coinChange(vector<int> &coins, int amount) {
        sort(coins.begin(), coins.end(), greater<int>());
        memo.resize(coins.size());
        int r = change(coins, 0, amount);
        return r == INT_MAX ? -1 : r;
    }
  private:
    vector<unordered_map<int, int>> memo;
    int change(const vector<int> &coin, const int &index, const int &amount) {
        if (amount < 0) return -1;
        if (amount == 0) return 0;
        if (index + 1 == coin.size()) {
            if (amount % coin[coin.size() - 1] == 0) {
                return amount / coin[coin.size() - 1];
            } else {
                return -1;
            }
        }
        const auto &f = memo[index].find(amount);
        if (f != memo[index].end()) {
            return f->second;
        }
        int ret = INT_MAX;
        if (coin[index] <= amount) {
            if (amount % coin[index] == 0) {
                ret = amount / coin[index];
            } else {
                int r = amount / coin[index];
                int next = r * coin[index];
                while (next >= amount) {
                    int ch = change(coin, index + 1, next);
                    if (ch != -1) {
                        ret = min(ret, r + ch);
                        break;
                    }
                    next -= coin[index];
                    r--;
                }
            }
        } else {
            int ch = change(coin, index + 1, amount);
            if (ch != -1) ret = ch;
        }
        int x = ret == INT_MAX ? -1 : ret;
        memo[index][amount] = x;
        return x;
    }
};

struct T {
    vector<int> coins;
    int amount;
};

TEST(Solution, test) {
    T ts[] = {
        {
            .coins= {186, 419, 83, 408},
            .amount = 6249,
        },

    };

    for (T t : ts) {
        Solution solution;
        solution.coinChange(t.coins, t.amount);
    }
}

int main() {
    testing::InitGoogleTest();

    return RUN_ALL_TESTS();
}


