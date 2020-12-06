#include <bits/stdc++.h>
#include <gtest/gtest.h>

using namespace std;

class Solution {
  public:
    int maxSumAfterPartitioning(vector<int> &arr, int k) {
        vector<int> dp(arr.size());
        {
            int max_n = arr[0];
            for (int i = 0; i < k; i++) {
                max_n = max(max_n, arr[i]);
                dp[i] = max_n * (i + 1);
            }
        }
        for (int i = k; i < arr.size(); i++) {
            int max_now = INT_MIN;
            for (int j = i - k + 1; j <= i; j++) {
                max_now = max(max_now,
                              dp[j - 1] +
                                  *max_element(arr.begin() + j, arr.begin() + i + 1) * (i - j + 1));
            }
            dp[i] = max_now;
        }
        return dp[arr.size() - 1];
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


