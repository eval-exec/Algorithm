#include <bits/stdc++.h>
#include <gtest/gtest.h>
using namespace std;


//// START ## Triangle

class Solution {
  public:
    int minimumTotal(vector<vector<int>> &triangle) {
        int height = triangle.size();
        vector<int> dp(triangle[height - 1]);
        for (int h = height - 2; h >= 0; h--) {
            vector<int> tmp(dp);
            for (int i = 0; i <= h; i++) {
                dp[i] = triangle[h][i] + min(tmp[i], tmp[i + 1]);
            }
        }
        return dp[0];
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


