#include <bits/stdc++.h>
#include <gtest/gtest.h>

using namespace std;

class Solution {
public:
    void nextPermutation(vector<int> &nums) {
        int len = nums.size();
        for (int i = len - 2; i >= 0; i--) {
            if (nums[i] < nums[i + 1]) {
                sort(nums.begin() + i + 1, nums.end());
                auto u = upper_bound(nums.begin() + i + 1, nums.end(), nums[i]);
                swap(nums[i], nums[u - nums.begin()]);
                sort(nums.begin() + i + 1, nums.end());
                return;
            }
        }
        sort(nums.begin(), nums.end());
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


