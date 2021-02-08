#include <bits/stdc++.h>
#include <gtest/gtest.h>

using namespace std;

class Solution {
public:
    int maxSubArrayLen(vector<int> &nums, int k) {
        if (nums.empty()) return 0;
        if (nums.size() == 1) {
            if (nums[0] == k)return 1;
            else return 0;
        }

        vector<long> sums(nums.size());
        sums[0] = nums[0];

        unordered_map<long, int> mm;
        mm[sums[0]] = 0;

        int ret = 0;
        if (k == nums[0]) ret = 1;
        for (int i = 1; i < nums.size(); i++) {
            if (sums[i - 1] + nums[i] == k) {
                ret = max(ret, i + 1);
            } else {
                auto f = mm.find(sums[i - 1] + nums[i] - k);
                if (f != mm.end()) {
                    ret = max(ret, i - f->second);
                }
            }
            sums[i] = sums[i - 1] + nums[i];
            if (mm.count(sums[i]) == 0) mm[sums[i]] = i;
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


