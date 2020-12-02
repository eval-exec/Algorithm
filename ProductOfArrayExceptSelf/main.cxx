#include <bits/stdc++.h>
#include <gtest/gtest.h>

using namespace std;


class Solution {
public:
    vector<int> productExceptSelf(vector<int> &nums) {
        vector<int> ret(nums.size());
        int pd = 1;
        for (int i = 0; i < nums.size(); i++) {
            pd *= nums[i];
            ret[i] = pd;
        }

        pd = 1;
        for (int i = nums.size() - 1; i >= 0; i--) {
            int left = 1;
            if (i > 0) {
                left = ret[i - 1];
            }
            ret[i] = left * pd;
            pd *= nums[i];
        }

        return ret;
    }
};


class Solution2 {
public:
    vector<int> productExceptSelf(vector<int> &nums) {
        vector<pair<int, int>> dp(nums.size());
        dp[0].first = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            dp[i].first = dp[i - 1].first * nums[i];
        }
        dp[nums.size() - 1].second = nums[nums.size() - 1];
        for (int i = nums.size() - 2; i >= 0; i--) {
            dp[i].second = dp[i + 1].second * nums[i];
        }
        vector<int> ret(nums.size(), 0);
        for (int i = 0; i < nums.size(); i++) {
            int left = 1, right = 1;
            if (i > 0) {
                left = dp[i - 1].first;
            }
            if (i < nums.size() - 1) {
                right = dp[i + 1].second;
            }
            ret[i] = left * right;
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


