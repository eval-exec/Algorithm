#include <bits/stdc++.h>
#include <gtest/gtest.h>

using namespace std;

class Solution {
public:
    bool canJump(vector<int> &nums) {
        vector<int> dp;
        int len = nums.size();
        if (len <= 1){
            return true;
        }
        int left = 0, right = 0;
        while (true) {
            int maxR = maxArrive(nums, left, right);
            if (maxR <= right) {
                break;
            }
            left = right + 1;
            right = maxR;
            if (maxR >= len - 1) {
                return true;
            }
        }
        return false;
    }

private:
    int maxArrive(vector<int> &nums, int i, int j) {
        int r = 0;
        for (int x = i; x <= j && x < nums.size(); x++) {
            r = max(r, x + nums[x]);
        }
        return r;
    }

    bool can(vector<int> &nums, int i, int j) {
        return nums[i] - nums[j] >= j - i;
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


