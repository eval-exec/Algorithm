
#include <bits/stdc++.h>
#include <gtest/gtest.h>

using namespace std;


class Solution {
public:
    int pivotIndex(vector<int> &nums) {
        int sum = 0;
        for (int &n : nums) {

            sum += n;
        }
        int len = nums.size();
        int left = 0;
        int right = sum;
        for (int i = 0; i < len; i++) {
            if (left == right - nums[i]) {
                return i;
            }
            left += nums[i];
            right -= nums[i];
        }
        return -1;
    }
};

int main() {
    testing::InitGoogleTest();

    return RUN_ALL_TESTS();
}


