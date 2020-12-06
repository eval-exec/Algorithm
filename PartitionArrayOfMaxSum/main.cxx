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

// optimized:
/*
 * ger current max :
 * from O(K) -> O(1)
 *
 * total O(N*k*k) -> O(n*K)
 */
class Solution_Optimized {
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
            int max_cur = arr[i];
            for (int j = i; j >= i - k + 1; j--) {
                max_cur = max(max_cur, arr[j]);
                dp[i] = max(dp[i], dp[j - 1] + max_cur * (i - j + 1));
            }
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


