
#include <bits/stdc++.h>
#include <gtest/gtest.h>

using namespace std;


class Solution {
public:
    int arrayPairSum(vector<int> &nums) {
        sort(nums.begin(), nums.end());
        int len = nums.size();
        int sum = 0;
        for (int i = 0; i < len; i += 2) {
            sum += nums[i];
        }
        return sum;
    }
};

int main() {
    testing::InitGoogleTest();

    return RUN_ALL_TESTS();
}


