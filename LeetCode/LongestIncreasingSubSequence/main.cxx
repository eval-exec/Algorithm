#include <bits/stdc++.h>
#include <gtest/gtest.h>

using namespace std;

class Solution1 {
public:
    int lengthOfLIS(vector<int> &nums) {
        vector<int> dp(nums.size());
        dp[0] = 1;

        int lenLIS = 1;
        for (int i = 1; i < nums.size(); i++) {
            int max_sub_len = 1;
            for (int j = i - 1; j >= 0; j--) {
                if (nums[j] < nums[i]) {
                    max_sub_len = max(max_sub_len, dp[j] + 1);
                }
                if (nums[j] + 1 == nums[i]) {
                    break;
                }
            }
            dp[i] = max_sub_len;
            lenLIS = max(lenLIS, dp[i]);
        }

        return lenLIS;
    }
};

class Solution {
public:
    int lengthOfLIS(vector<int> &nums) {
        vector<int> rets(nums.size());
        rets[0] = nums[0];
        int len = 1;
        for (const int &n : nums) {
            const auto &l = lower_bound(rets.begin(), rets.begin() + len, n);
            rets[l - rets.begin()] = n;
            if (l == rets.begin() + len) {
                len++;
            }
        }
        return len;
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


