#include <bits/stdc++.h>
#include <gtest/gtest.h>

using namespace std;

class Solution {
  public:
    int maximumUniqueSubarray(vector<int> &nums) {
        if (nums.empty()) return 0;

        unordered_map<int, int> mm;
        mm[nums[0]] = 0;
        int ret = nums[0];
        int left = 0;
        vector<int> sums(nums.size());
        sums[0] = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            sums[i] = sums[i - 1] + nums[i];
            auto f = mm.find(nums[i]);
            if (f != mm.end() && f->second >= left) left = f->second + 1;
            mm[nums[i]] = i;
            if (left == 0) {
                ret = sums[i];
            } else {
                ret = max(ret, sums[i] - sums[left - 1]);
            }
        }
        return ret;
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


