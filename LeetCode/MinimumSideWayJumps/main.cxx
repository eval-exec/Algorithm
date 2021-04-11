#include <bits/stdc++.h>
#include <gtest/gtest.h>
using namespace std;

class Solution {
  public:
    int minSideJumps(vector<int> &obstacles) {
        const int mx = 50002;
        array<int, 3> dp = {0};
        int n = obstacles.size();
        if (obstacles[n - 1] > 0) {
            dp[obstacles[n - 1] - 1] = mx;
        }

        for (int i = n - 2; i >= 0; i--) {
            array<int, 3> tmp(dp);
            int oi = obstacles[i] - 1;
            if (oi >= 0) dp[oi] = mx;
            for (int r = 0; r < 3; r++) {
                if (oi != r) {
                    int a = (r + 1) % 3;
                    int b = (r + 2) % 3;
                    dp[r] = min(dp[r], 1 + dp[b]);
                    dp[r] = min(dp[r], 1 + dp[a]);
                }
            }
        }
        return dp[1];
    }
};

struct T {

};

TEST(Solution, test) {
    T ts[] = {
        },
    };

    for (T t : ts) {
        Solution solution;
        cout << solution.minSideJumps(t.obs) << endl;
    }
}

int main() {
    testing::InitGoogleTest();

    return RUN_ALL_TESTS();
}


