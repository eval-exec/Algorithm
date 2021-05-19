#include <bits/stdc++.h>
#include <gtest/gtest.h>
using namespace std;


//// START
/*
## Minimum Moves to Equal Array Elements II

*/


class Solution {
  public:
    int minMoves2(vector<int> &nums) {
        sort(nums.begin(), nums.end());
        int mid = nums[nums.size() / 2];
        int ret = 0;
        for (const int &n : nums) {
            ret += abs(n - mid);
        }
        return ret;
    }
};
class Solution2 {
  public:
    int minMoves2(vector<int> &nums) {
        sort(nums.begin(), nums.end());
        long low = nums.front();
        long high = nums.back();
        vector<long> base_low(nums.size());
        vector<long> base_high(nums.size());

        long sum = 0;
        for (int i = 0; i < nums.size(); i++) {
            sum += nums[i] - low;
            base_low[i] = sum;
        }
        sum = 0;
        for (int i = nums.size() - 1; i >= 0; i--) {
            sum += high - nums[i];
            base_high[i] = sum;
        }
        long ret = INT_MAX;
        for (int i = 0; i < nums.size(); i++) {
            long left = (nums[i] - low) * (i + 1) - base_low[i];
            long right = (high - nums[i]) * (nums.size() - i - 1);
            if (i + 1 < nums.size()) right -= base_high[i + 1];
            ret = min(ret, left + right);
        }
        return ret;
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


