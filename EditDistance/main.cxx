#include <bits/stdc++.h>
#include <gtest/gtest.h>

using namespace std;

class Solution {
  public:
    int minDistance(string word1, string word2) {
        int len1 = word1.size(), len2 = word2.size();
        if (len1 == 0) return len2;
        if (len2 == 0) return len1;
        vector<vector<int>> dp(len1, vector<int>(len2));
        dp[0][0] = word1[0] == word2[0] ? 0 : 1;
        for (int i = 1; i < len1; i++) {
            dp[i][0] = word1[i] == word2[0] ? i : 1 + dp[i - 1][0];
        }
        for (int j = 1; j < len2; j++) {
            dp[0][j] = word1[0] == word2[j] ? j : 1 + dp[0][j - 1];
        }
        for (int i = 1; i < len1; i++) {
            for (int j = 1; j < len2; j++) {
                if (word1[i] == word2[j]) {
                    dp[i][j] = dp[i - 1][j - 1];
                } else {
                    dp[i][j] = 1 + min(dp[i - 1][j - 1], min(dp[i - 1][j], dp[i][j - 1]));
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


