#include <bits/stdc++.h>
#include <gtest/gtest.h>
using namespace std;

class Solution {
  public:
    int countNicePairs(vector<int> &nums) {

/*
 * nums[i] + rev(nums[j]) == nums[j] + rev(nums[i])
 * nums[i] - rev(nums[i]) == nums[j] - rev(nums[j])
 */
        unordered_map<int, int> memo;
        long count = 0;
        const int mod = 1e9+7;
        int v = 0;
        for (int n : nums) {
            v = n - rev(n);
            count += memo[v]++;
        }
        return count % mod;
    }
  private:
    int rev(int n) {
        int ret = 0;
        while (n > 0) {
            ret = ret * 10 + n % 10;
            n /= 10;
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


