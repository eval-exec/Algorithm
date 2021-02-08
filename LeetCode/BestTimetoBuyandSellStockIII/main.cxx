#include <bits/stdc++.h>
#include <gtest/gtest.h>

using namespace std;

class Solution {
  public:
    int maxProfit(vector<int> &prices) {
        priority_queue<int> pq;
        if (prices.size() <= 1) return 0;
        int ret = 0;
        vector<int> dp(prices.size());
        {
            int mv = prices[0];
            for (int i = 1; i < prices.size(); i++) {
                mv = min(mv, prices[i - 1]);
                dp[i] = max(dp[i - 1], prices[i] - mv);
                ret = max(ret, dp[i]);
            }
        }
        {
            int mx = prices[prices.size() - 1];
            for (int i = prices.size() - 1; i >= 2; i--) {
                mx = max(mx, prices[i + 1]);
                ret = max(ret, dp[i - 1] + mx - prices[i]);
            }
        }
        return ret;
    }
};

struct T {

};

TEST(Solution, test) {
    T ts[] = {
        {

        },

    };

    Solution solution;

    for (T t : ts) {

    }
}

int main() {
    testing::InitGoogleTest();

    return RUN_ALL_TESTS();
}


