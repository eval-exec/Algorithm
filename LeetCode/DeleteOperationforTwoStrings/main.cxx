#include <bits/stdc++.h>
#include <gtest/gtest.h>

using namespace std;

class Solution {
  public:
    int minDistance(string word1, string word2) {
        int len1 = word1.size(), len2 = word2.size();
        if (len1 * len2 == 0) return len1 + len2;
        vector<vector<int>> dp(len1, vector<int>(len2));
        if (word1[0] == word2[0]) {
            dp[0][0] = 0;
        } else {
            dp[0][0] = 2;
        }

        for (int i = 1; i < len1; i++) {
            if (word1[i] == word2[0]) {
                dp[i][0] = i;
            } else {
                dp[i][0] = 1 + dp[i - 1][0];
            }

        }
        for (int i = 1; i < len2; i++) {
            if (word1[0] == word2[i]) {
                dp[0][i] = i;
            } else {
                dp[0][i] = 1 + dp[0][i - 1];
            }
        }
        for (int i = 1; i < len1; i++) {
            for (int j = 1; j < len2; j++) {
                if (word1[i] == word2[j]) {
                    dp[i][j] = dp[i - 1][j - 1];
                } else {
                    dp[i][j] = min(1 + min(dp[i - 1][j], dp[i][j - 1]), 2 + dp[i - 1][j - 1]);
                }
            }
        }
        return dp[len1 - 1][len2 - 1];
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


