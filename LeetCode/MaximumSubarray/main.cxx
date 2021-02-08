#include <bits/stdc++.h>
#include <gtest/gtest.h>

using namespace std;

class Solution {
public:
    int maxSubArray(vector<int> &nums) {
        vector<int> dp(nums.size());
        if (nums.empty()) {
            return 0;
        }

        dp[0] = nums[0];
        int ret = dp[0];
        for (int i = 1; i < nums.size(); i++) {
            dp[i] = max(dp[i - 1] + nums[i], nums[i]);
            ret = max(ret, dp[i]);
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


