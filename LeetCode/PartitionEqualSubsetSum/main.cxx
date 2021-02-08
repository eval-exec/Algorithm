#include <bits/stdc++.h>
#include <gtest/gtest.h>

using namespace std;


class Solution {
public:
    bool canPartition(vector<int> &nums) {
        if (nums.size() <= 1) return false;
        if (nums.size() == 2) return nums[0] == nums[1];

        int sum = 0;
        for (int &n : nums) {
            sum += n;
        }

        if (sum % 2 == 1) return false;

        vector<vector<int>> dp(nums.size(), vector<int>(sum + 1));
        dp[0][0] = true;
        dp[0][nums[0]] = true;
        for (int i = 1; i < nums.size(); i++) {
            for (int j = 0; j <= sum; j++) {
                if (dp[i - 1][j]) {
                    dp[i][j] = true;
                    dp[i][j + nums[i]] = true;
                }
            }
        }
        return dp[nums.size() - 1][sum / 2];
    }
};

class Solution2 {
public:
    bool canPartition(vector<int> &nums) {
        if (nums.size() <= 1) return false;
        if (nums.size() == 2) return nums[0] == nums[1];

        int sum = 0;
        for (int &n : nums) {
            sum += n;
        }
        if (sum % 2 == 1) return false;
        return can(nums, nums.size() - 1, sum / 2);
    }

private:
    map<pair<int, int>, bool> mm;

    bool can(vector<int> &nums, int j, int sum) {
        auto f = mm.find({j, sum});
        if (f != mm.end()) {
            return f->second;
        }
        if (sum <= 0) return false;
        if (j == 0) return sum == nums[0];
        bool ret = can(nums, j - 1, sum - nums[j]) || can(nums, j - 1, sum);

        mm[{j, sum}] = ret;
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


