#include <bits/stdc++.h>
#include <gtest/gtest.h>
using namespace std;

//// START
/*
## 2140. Solving Questions With Brainpower

*/

class Solution {
public:
  long long mostPoints(vector<vector<int>> &questions) {
    vector<long long> dp(questions.size());
    dp[dp.size() - 1] = questions[questions.size() - 1][0];
    for (int i = dp.size() - 2; i >= 0; i--) {
      long long score = questions[i][0];
      if (i + questions[i][1] + 1 < questions.size()) {
        score += dp[i + questions[i][1] + 1];
      }
      dp[i] = max(dp[i + 1], score);
    }
    return dp[0];
  }
};

//// END
struct T {};

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
