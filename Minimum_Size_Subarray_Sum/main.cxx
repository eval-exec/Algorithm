
#include <bits/stdc++.h>
#include <gtest/gtest.h>

using namespace std;


class Solution {
public:
    int minSubArrayLen(int s, vector<int> &nums) {
        int i = 0, j = 1, len = nums.size(), count = len + 1;
        if (len == 0) {
            return 0;
        }
        int sum = nums[0];
        while (true) {
            if (sum >= s && i < j) {
                count = min(count, j - i);
                if (i >= len) {
                    return count == len + 1 ? 0 : count;
                }
                sum = sum - nums[i++];
            } else {
                if (j >= len) {
                    return count == len + 1 ? 0 : count;
                }
                sum += nums[j++];
            }
        }
    }
};


int main() {
    testing::InitGoogleTest();

    return RUN_ALL_TESTS();
}


