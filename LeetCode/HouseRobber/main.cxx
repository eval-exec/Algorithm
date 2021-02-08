#include <bits/stdc++.h>
#include <gtest/gtest.h>

using namespace std;

class Solution {
public:
    int rob(vector<int> &nums) {
        int len = nums.size();
        if (len == 0) {
            return 0;
        }
        vector<vector<int>> dp(nums.size(), vector<int>(2));
        // 0 : do not rob
        // 1 : rob
        dp[0][0] = 0;
        dp[0][1] = nums[0];
        if (len == 1) {
            return max(dp[0][0], dp[0][1]);
        }
        dp[1][0] = dp[0][1];
        dp[1][1] = nums[1];
        if (len == 2) {
            return max(dp[1][0], dp[1][1]);
        }

        for (int i = 2; i < nums.size(); i++) {
            dp[i][0] = max(dp[i - 1][0], dp[i - 1][1]);
            dp[i][1] = max(dp[i - 1][0] + nums[i], dp[i - 2][1]);
        }
        return max(dp[nums.size() - 1][0], dp[nums.size() - 1][1]);
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


