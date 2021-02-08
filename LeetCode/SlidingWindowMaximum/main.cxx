#include <bits/stdc++.h>
#include <gtest/gtest.h>

using namespace std;

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int> &nums, int k) {
        map<int, int> mm;
        vector<int> rets(nums.size() - k + 1);
        for (int i = 0; i < k; i++) {
            mm[nums[i]] += 1;
        }
        int max_num = mm.rbegin()->first;
        rets[0] = max_num;

        for (int i = k; i < nums.size(); i++) {
            mm[nums[i]] += 1;
            mm[nums[i - k]] -= 1;
            if (mm[nums[i - k]] == 0) mm.erase(nums[i - k]);
            rets[i - k + 1] = mm.rbegin()->first;
        }
        return rets;
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


