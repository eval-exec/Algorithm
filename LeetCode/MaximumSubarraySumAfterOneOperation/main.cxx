#include <bits/stdc++.h>
#include <gtest/gtest.h>

using namespace std;
class Solution {
  public:
    int maxSumAfterOperation(vector<int> &nums) {
        int len = nums.size();
        vector<int> left(len);
        left[0] = max(0, nums[0]);
        for (int i = 1; i < len; i++) {
            left[i] = max(nums[i], nums[i] + left[i - 1]);
        }

        vector<int> right(len);
        right[len - 1] = nums[len - 1];
        for (int i = len - 2; i >= 0; i--) {
            right[i] = max(nums[i], nums[i] + right[i + 1]);
        }
        int ret = 0;
        for (int i = 0; i < len; i++) {
            int l = 0;
            if (i - 1 >= 0) {
                l = max(0, left[i - 1]);
            }
            int r = 0;
            if (i + 1 < len) {
                r = max(0, right[i + 1]);
            }
            ret = max(ret, l + nums[i] * nums[i] + r);
        }
        return ret;
    }
};

struct T {
    vector<int> nums;
    int e;

};

TEST(Solution, test) {
    T ts[] = {
        {
            .nums={1, -1, 1, 1, -1, -1, 1},
            .e=4,
        },
        {
            .nums={2, -1, -4, -3},
            .e=17,
        }
    };
    for (T t : ts) {
        Solution solution;
        EXPECT_EQ(solution.maxSumAfterOperation(t.nums), t.e);

    }
}

int main() {
    testing::InitGoogleTest();

    return RUN_ALL_TESTS();
}


