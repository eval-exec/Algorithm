#include <bits/stdc++.h>
#include <gtest/gtest.h>

using namespace std;

class Solution {
  public:
    int threeSumClosest(vector<int> &nums, int target) {
        int ret = nums[0] + nums[1] + nums[2];
        set<int> ss;
        for (int i = 2; i < nums.size(); i++) {
            for (int j = i - 2; j >= 0; j--)
                ss.insert(nums[i - 1] + nums[j]);
            const auto &f = ss.lower_bound(target - nums[i]);
            if (f != ss.end()) {
                if (abs(nums[i] + *f - target) < abs(ret - target)) ret = nums[i] + *f;
                if (f != ss.begin()) {
                    if (abs(nums[i] + *prev(f) - target) < abs(ret - target)) ret = nums[i] + *prev(f);
                }
            } else {
                if (abs(nums[i] + *ss.rbegin() - target) < abs(ret - target)) ret = nums[i] + *ss.rbegin();
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


