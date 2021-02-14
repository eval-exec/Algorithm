#include <bits/stdc++.h>
#include <gtest/gtest.h>

using namespace std;

class Solution {
  public:
    int maxAbsoluteSum(vector<int> &nums) {
        cal(nums, true);
        cal(nums, false);
        return ret;
    }
  private:
    int ret = 0;
    int cal(const vector<int> &nums, bool positive) {
        int sum = 0;
        for (int n : nums) {
            int now = n;
            if (!positive) now *= -1;
            if (sum + now < 0) {
                sum = 0;
            } else {
                sum += now;
            }
            ret = max(ret, sum);
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

    for (T t : ts) {
        Solution solution;

    }
}

int main() {
    testing::InitGoogleTest();

    return RUN_ALL_TESTS();
}


