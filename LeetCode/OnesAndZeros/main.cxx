#include <bits/stdc++.h>
#include <gtest/gtest.h>
using namespace std;

class Solution {
  private:
  public:
    int findMaxForm(vector<string> &strs, int m, int n) {
        vector<vector<int>> dp(vector<vector<int>>(m + 1, vector<int>(n + 1)));
        for (const string &str:strs) {
            auto f = cal(str);
            for (int mi = m; mi >= f.first; mi--) {
                for (int ni = n; ni >= f.second; ni--) {
                    dp[mi][ni] = max(1 + dp[mi - f.first][ni - f.second], dp[mi][ni]);
                }
            }
        }
        return dp[m][n];
    }
    pair<int, int> cal(const string &str) {
        int m = 0, n = 0;
        for (const char &c:str) {
            if (c == '0') m++;
            else n++;
        }
        return make_pair(m, n);
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


