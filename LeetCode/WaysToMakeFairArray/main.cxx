#include <bits/stdc++.h>
#include <gtest/gtest.h>

using namespace std;

class Solution {
  public:
    int waysToMakeFair(vector<int> &nums) {
        int es = 0, os = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (i % 2 == 0) {
                es += nums[i];
            } else {
                os += nums[i];
            }
        }
        int esr = 0, osr = 0;
        int count = 0;
        for (int i = nums.size() - 1; i >= 0; i--) {
            if (i % 2 == 0) {
                es -= nums[i];
                if (i < nums.size() - 1) {
                    esr += nums[i + 1];
                }
            } else {
                os -= nums[i];
                if (i < nums.size() - 1) {
                    osr += nums[i + 1];
                }
            }
            if (os + osr == es + esr) count++;
        }
        return count;
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


