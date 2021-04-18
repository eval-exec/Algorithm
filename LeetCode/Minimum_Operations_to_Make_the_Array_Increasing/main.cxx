#include <bits/stdc++.h>
#include <gtest/gtest.h>
using namespace std;


//// START ## Minimum Operations to Make the Array Increasing


/*
 * 1 <= nums.length <= 5000
1 <= nums[i] <= 104
 */
class Solution {
  public:
    int minOperations(vector<int> &nums) {
        int ret = 0;
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] > nums[i - 1]) continue;
            int d = nums[i - 1] - nums[i];
            ret += d + 1;
            nums[i] += d + 1;
        }
        return ret;
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


