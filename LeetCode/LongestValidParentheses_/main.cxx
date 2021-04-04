#include <bits/stdc++.h>
#include <gtest/gtest.h>
using namespace std;

class Solution {
  public:
    int longestValidParentheses(string s) {
        if (s.size() <= 1) return 0;
        vector<int> dp(s.size());

        dp[0] = 0;
        int ret = dp[1] = s[0] == '(' && s[1] == ')' ? 2 : 0;
        for (int i = 2; i < s.size(); i++) {
            if (s[i] == ')') {
                if (s[i - 1] == '(') {
                    dp[i] = 2 + dp[i - 2];
                } else if (dp[i - 1] != 0) {
                    int p = i - dp[i - 1] - 1;
                    if (p >= 0 && s[p] == '(') {
                        dp[i] = 2 + dp[i - 1];
                        if (p - 1 >= 0)dp[i] += dp[p - 1];
                    }
                }
                ret = max(ret, dp[i]);
            }
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


