#include <bits/stdc++.h>
#include <gtest/gtest.h>

using namespace std;

class Solution {
  public:
    int longestValidParentheses(string s) {
        stack<char> st;
        vector<int> dp(s.size());
        if (s.size() < 2) return 0;
        dp[0] = 0;
        dp[1] = s[0] == '(' && s[1] == ')' ? 2 : 0;
        int max_len = dp[1];
        for (int i = 2; i < s.size(); i++) {
            if (s[i] == '(') {
                dp[i] = 0;
            } else {
                if (s[i - 1] == '(') {
                    dp[i] = 2 + dp[i - 2];
                } else {
                    int n = dp[i - 1];
                    if (i - n > 0) {
                        if (s[i - n - 1] == '(') {
                            dp[i] = 2 + dp[i - 1];
                            if (i - n - 2 >= 0) {
                                dp[i] += dp[i - n - 2];
                            }
                        }
                    }
                }
            }
            max_len = max(max_len, dp[i]);
        }
        return max_len;
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


