
#include <bits/stdc++.h>
#include <gtest/gtest.h>

using namespace std;


class Solution {
public:
    vector<int> twoSum(vector<int> &nums, int target) {
        unordered_map<int, int> mm;
        for (int i = 0; i < nums.size(); i++) {
            if (mm.count(target - nums[i])) {
                return {mm[target - nums[i]], i};
            }
            mm[nums[i]] = i;
        }
        return {};
    }
};

class Solution {
public:
    vector<int> twoSum(vector<int> &nums, int target) {
        int len = nums.size();
        for (int i = 0; i < len - 1; i++) {
            for (int j = i + 1; j < len; j++) {
                if (nums[i] + nums[j] == target) {
                    return {nums[i], nums[j]};
                }
            }
        }
        return {};
    }
};

int main() {
    testing::InitGoogleTest();

    return RUN_ALL_TESTS();
}


