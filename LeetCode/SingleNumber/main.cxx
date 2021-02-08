
#include <bits/stdc++.h>
#include <gtest/gtest.h>

using namespace std;

class Solution {
public:
    int singleNumber(vector<int> &nums) {
        int len = nums.size();
        if (len == 1) {
            return nums[0];
        }

        int xxx = nums[0];
        for (int i = 1; i < len; i++) {
            xxx ^= nums[i];
        }
        return xxx;
    }
};

int main() {
    testing::InitGoogleTest();

    return RUN_ALL_TESTS();
}


