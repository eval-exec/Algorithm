#include <bits/stdc++.h>
#include <gtest/gtest.h>

using namespace std;


class Solution {
public:
    int findNumberOfLIS(vector<int> &nums) {
        vector<int> dp(nums.size());
        vector<int> counts(nums.size());
        dp[0] = 1;
        counts[0] = 1;
        int len = nums.size();
        for (int i = 1; i < len; i++) {
            int max_j = 1;
            for (int j = i - 1; j >= 0; j--) {
                if (nums[i] > nums[j]) {
                    max_j = max(max_j, dp[j] + 1);
                }
            }
            dp[i] = max_j;

            for (int j = i - 1; j >= 0; j--) {
                if (dp[j] + 1 == dp[i]) {
                    counts[i]++;
                }
            }
        }

        int count=0;
        for (int i = 0;i< nums.size();i++){
        }

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


