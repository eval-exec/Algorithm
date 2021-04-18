#include <bits/stdc++.h>
#include <gtest/gtest.h>
using namespace std;


//// START ## Maximum XOR for Each Query


class Solution {
  public:
    vector<int> getMaximumXor(vector<int> &nums, int maximumBit) {
        vector<int> rets(nums.size());
        int ones = 1;
        {

            int n = maximumBit;
            while (n > 1) {
                ones = (ones << 1) + 1;
                n--;
            }
        }
        int X = 0;
        for (int i = 0; i < nums.size(); i++) {
            X ^= nums[i];
            rets[nums.size() - 1 - i] = ones ^ X;
        }
        return rets;
    }
};


//// END




struct T {

};

TEST(Solution, test) {
    T ts[] = {
        {

        },
        {

        },

    };

    for (T t : ts) {
        Solution solution;

    }
}

int main() {
    testing::InitGoogleTest();

    return RUN_ALL_TESTS();
}


