#include <bits/stdc++.h>
#include <gtest/gtest.h>

using namespace std;

class Solution {
  public:
    int maxResult(vector<int> &nums, int k) {
        if (nums.empty()) return 0;

        int ret = nums[0];

        multiset<int> ms;
        ms.insert(nums[0]);
        unordered_map<int, int> mm;
        mm[0] = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            if (i - k > 0) {
                int v = mm[i - k - 1];
                mm.erase(i - k - 1);
                ms.erase(v);
            }
            int mx = *ms.rbegin();
            int v = mx + nums[i];
            mm[i] = v;
            ms.insert(v);
        }
        ret = mm[nums.size() - 1];
        for (const auto &m : mm) {
            if (m.first == nums.size() - 1)continue;
            ret = max(ret, m.second + nums[nums.size() - 1]);
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


