#include <bits/stdc++.h>
#include <gtest/gtest.h>
using namespace std;


//// START
/*
## JumpGameII

*/
class Solution {
  public:
    int jump(vector<int> &nums) {
        vector<int> dp(nums.size(), nums.size() + 1);
        dp[nums.size() - 1] = 0;
        for (int i = nums.size() - 2; i >= 0; i--) {
            for (int step = 1; step <= nums[i] && i + step < nums.size(); step++) {
                dp[i] = min(dp[i], 1 + dp[i + step]);
            }
        }
        return dp[0];
    }
};

//// END
struct T {

};

TEST(Solution, test) {
    T ts[] = {
        {

        },
        {

        },

    };

    for (T t : ts) {
        Solution solution;

    }
}

int main() {
    testing::InitGoogleTest();

    return RUN_ALL_TESTS();
}


