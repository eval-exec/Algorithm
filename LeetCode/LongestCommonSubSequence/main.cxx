#include <bits/stdc++.h>
#include <gtest/gtest.h>

using namespace std;

class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        vector<vector<int>> dp(text1.size(), vector<int>(text2.size()));
        {
            int start = 0;
            for (int i = 0; i < text2.size(); i++) {
                if (text1[0] == text2[i]) {
                    start = 1;
                }
                dp[0][i] = start;
            }
            start = 0;
            for (int i = 0; i < text2.size(); i++) {
                if (text1[i] == text2[0]) {
                    start = 1;
                }
                dp[i][0] = start;
            }
        }
        for (int i = 1; i < text1.size(); i++) {
            for (int j = 1; j < text2.size(); j++) {
                if (text1[i] == text2[j]) {
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                } else {
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }
        return dp[text1.size() - 1][text2.size() - 1];
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


