#include <bits/stdc++.h>
#include <gtest/gtest.h>

using namespace std;

class Solution {
  public:
    int maximumScore(int a, int b, int c) {
        vector<int> nums = {a, b, c};
        sort(nums.begin(), nums.end());
        while (nums[2] != 0 && nums[1] != 0) {
            proc(nums);
            sort(nums.begin(), nums.end());
        }
        return scores;
    }
  private:
    int scores = 0;
    void proc(vector<int> &nums) {
        if (nums[0] != 0) {
            if (nums[1] == nums[2]) {
                int n1 = nums[0] / 2;
                int n2 = nums[0] - n1;
                scores += nums[0];
                nums[0] = 0;
                nums[1] -= n2;
                nums[2] -= n1;
            } else {
                int delta = nums[2] - nums[1];
                if (delta >= nums[0]) {
                    scores +=  nums[0];
                    nums[2] -= nums[0];
                    nums[0] = 0;
                } else {
                    scores += delta;
                    nums[0] -= delta;
                    nums[2] -= delta;
                }
            }
        } else if (nums[1] != 0) {
            scores += min(nums[1], nums[2]);
            nums[2] -= nums[1];
            nums[1] = 0;
        } else {
            return;
        }
    }
};

struct T {

};

TEST(Solution, test) {
    T ts[] = {
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


