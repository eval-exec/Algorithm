#include <bits/stdc++.h>
#include <gtest/gtest.h>
using namespace std;


//// START
/*
## Non-decreasingArray

*/
class Solution {
  public:
    bool checkPossibility(vector<int> &nums) {
        bool did = false;
        if (nums.size() <= 1) return true;
        if (nums[1] < nums[0]) {
            nums[0] = nums[1]-1;
            did = true;
        }
        if (nums.size() <= 2) return true;
        for (int i = 2; i < nums.size(); i++) {
            if (nums[i] < nums[i - 1]) {
                if (did) {
                    return false;
                }
                if (nums[i] > nums[i - 2]) {
                    nums[i-1] = nums[i - 2];
                    did = true;
                } else if (nums[i] == nums[i - 2]) {
                    nums[i - 1] = nums[i - 2];
                    did = true;
                } else {
                    nums[i] = nums[i-1];
                    did = true;
                }
            }
        }
        return true;
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


