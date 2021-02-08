#include <bits/stdc++.h>
#include <gtest/gtest.h>

using namespace std;


class Solution {
public:
    int findMaxLength(vector<int> &nums) {
        unordered_map<int, int> mm;
        int count = 0;
        int ret = 0;
        mm[0] = -1;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == 0) {
                count += -1;
            } else {
                count += 1;
            }
            if (mm.count(count) > 0) {
                ret = max(ret, i - mm[count]);
            } else {
                mm[count] = i;
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


