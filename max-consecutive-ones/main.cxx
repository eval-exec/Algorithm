#include <bits/stdc++.h>
#include <gtest/gtest.h>

using namespace std;

class Solution {
public:
    int findMaxConsecutiveOnes(vector<int> &nums) {
        int max = 0;
        int count = 0;
        for (int v:nums) {
            if (v == 1) {
                count++;
                max = std::max(max,count);
                continue;
            } else {
                count = 0;

            }
        }
        return max;
    }
};

TEST(Solution, maxConsecutiveOnes) {
    Solution solution;
    vector<int> nums = {1, 2, 1, 1, 1};

    int count = solution.findMaxConsecutiveOnes(nums);
    ASSERT_EQ(count, 3);


    nums= {};
    count = solution.findMaxConsecutiveOnes(nums);
    ASSERT_EQ(count, 0);


    nums= {0};
    count = solution.findMaxConsecutiveOnes(nums);
    ASSERT_EQ(count, 0);

    nums= {1};
    count = solution.findMaxConsecutiveOnes(nums);
    ASSERT_EQ(count, 1);


}

int main() {
    testing::InitGoogleTest();

    return RUN_ALL_TESTS();
}


