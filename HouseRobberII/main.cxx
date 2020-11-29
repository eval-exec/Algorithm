#include <bits/stdc++.h>
#include <gtest/gtest.h>

using namespace std;


class Solution {
public:
    int rob(vector<int> &nums) {
        int len = nums.size();
        if (len == 0) return 0;
        if (len == 1) return nums[0];
        if (len == 2) return max(nums[0], nums[1]);

        vector<array<int, 4>> dp(nums.size() / 2 + 1);

        dp[0][0] = 0;
        dp[0][1] = nums[len - 1];
        dp[0][2] = nums[0];
        dp[0][3] = 0;


        // 0 1 2
        // 0 1 2
        // 0 1 2 3 4 5
        // 0 1 2 3 4 5 6
        int end = len / 2 - 1;
        for (int i = 1; i <= end; i++) {
            auto last = dp[i - 1];
            dp[i][0] = max4(last[0], last[1], last[2], last[3]);
            dp[i][1] = nums[len - 1 - i] + max(last[0], last[2]);
            dp[i][2] = nums[i] + max(last[0], last[1]);
            dp[i][3] = nums[i] + nums[len - 1 - i] + last[0];
        }

        if (len % 2 == 0) {
            return max(max(dp[end][0], dp[end][1]), dp[end][2]);
        } else {
            return max(nums[end + 1] + dp[end][0],
                       max4(dp[end][0], dp[end][1], dp[end][2], dp[end][3]));
        }
    }

private:
    int max4(int n1, int n2, int n3, int n4) {
        return max(max(max(n1, n2), n3), n4);
    }
};


class Solution2 {
public:
    int rob(vector<int> &nums) {
        int len = nums.size();
        if (len == 0) return 0;
        if (len == 1) return nums[0];
        if (len == 2) return max(nums[0], nums[1]);

        array<int, 4> memo{0};
        memo[0] = 0;
        memo[1] = nums[len - 1];
        memo[2] = nums[0];
        memo[3] = 0;
        // 0 1 2
        // 0 1 2
        // 0 1 2 3 4 5
        // 0 1 2 3 4 5 6
        int end = len / 2 - 1;
        for (int i = 1; i <= end; i++) {
            array<int, 4> tmp(memo);
            memo[0] = max4(tmp[0], tmp[1], tmp[2], tmp[3]);
            memo[1] = nums[len - 1 - i] + max(tmp[0], tmp[2]);
            memo[2] = nums[i] + max(tmp[0], tmp[1]);
            memo[3] = nums[i] + nums[len - 1 - i] + tmp[0];
        }

        if (len % 2 == 0) {
            return max(max(memo[0], memo[1]), memo[2]);
        } else {
            return max(nums[end + 1] + memo[0],
                       max4(memo[0], memo[1], memo[2], memo[3]));
        }
    }

private:
    int max4(int n1, int n2, int n3, int n4) {
        return max(max(max(n1, n2), n3), n4);
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


