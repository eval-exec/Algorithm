
#include <bits/stdc++.h>
#include <gtest/gtest.h>

using namespace std;


class Solution {
public:
    int dominantIndex(vector<int> &nums) {

        int len = nums.size();
        if (len <= 2) {
            return -1;
        }
        for (int i = 0; i < len; i++) {
            if (bigger == -1) {
                bigger = i;
                continue;
            }
            if (nums[i] > nums[bigger]) {
                big = bigger;
                bigger = i;
                continue;
            }
            if (big == -1) {
                big = i;
                continue;
            }
            if (nums[i] > nums[big]) {
                big = i;
            }
        }

        if (nums[bigger] >= 2 * nums[big]) {
            return bigger;
        }
        return -1;
    }

    int big = -1, bigger = -1;
};

int main() {
    testing::InitGoogleTest();

    return RUN_ALL_TESTS();
}


