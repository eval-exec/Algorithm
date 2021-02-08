#include <bits/stdc++.h>
#include <gtest/gtest.h>

using namespace std;
class Solution {
  public:
    bool increasingTriplet(vector<int> &nums) {
        int first = INT_MAX, second = INT_MAX;
        for (int n : nums) {
            if (n <= first) {
                first = n;
            } else if (n <= second) {
                second = n;
            } else {
                if (n > second) return true;
            }
        }
        return false;

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


