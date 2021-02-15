#include <bits/stdc++.h>
#include <gtest/gtest.h>

using namespace std;

class Solution {
  public:
    int maxScoreSightseeingPair(vector<int> &A) {
        int left = INT_MIN;
        int ret = INT_MIN;
        for (int i = 1; i < A.size(); i++) {
            left = max(left, A[i - 1] + i - 1);

            ret = max(ret, left + A[i] - i);
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


