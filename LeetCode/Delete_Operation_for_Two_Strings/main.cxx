#include <bits/stdc++.h>
#include <gtest/gtest.h>
using namespace std;


//// START
/*
## Delete Operation for Two Strings

*/
class Solution {
  public:
    int minDistance(string word1, string word2) {
        vector<int> dp(vector<int>(word2.size()));
        dp[0] = word1[0] == word2[0] ? 0 : 2;
        for (int i = 1; i < word2.size(); i++) {
            dp[i] = word1[0] == word2[i] ? i : dp[i - 1] + 1;
        }
        for (int i = 1; i < word1.size(); i++) {
            vector<int> tmp(dp);
            dp[0] = word1[i] == word2[0] ? i : tmp[0] + 1;
            for (int j = 1; j < word2.size(); j++) {
                if (word1[i] == word2[j]) {
                    dp[j] = tmp[j - 1];
                } else {
                    dp[j] = 1 + min(tmp[j], dp[j - 1]);
                }
            }
        }
        return dp.back();
    }
};

class Solution_1 {
  public:
    int minDistance(string word1, string word2) {
        vector<vector<int>> dp(word1.size(), vector<int>(word2.size()));
        dp[0][0] = word1[0] == word2[0] ? 0 : 2;
        for (int i = 1; i < word2.size(); i++) {
            dp[0][i] = word1[0] == word2[i] ? i : dp[0][i - 1] + 1;
        }
        for (int i = 1; i < word1.size(); i++) {
            dp[i][0] = word2[0] == word1[i] ? i : dp[i - 1][0] + 1;
        }
        for (int i = 1; i < word1.size(); i++) {
            for (int j = 1; j < word2.size(); j++) {
                if (word1[i] == word2[j]) {
                    dp[i][j] = dp[i - 1][j - 1];
                } else {
                    dp[i][j] = 1 + min(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }
        return dp.back().back();
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


