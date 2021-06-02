#include <bits/stdc++.h>
#include <gtest/gtest.h>
using namespace std;


//// START
/*
## Interleaving String

*/

class Solution {
 public:
  bool isInterleave(string s1, string s2, string s3) {
	if (s1.size() + s2.size() != s3.size()) return false;
	vector<vector<bool>> dp(s1.size() + 1, vector<bool>(s2.size() + 1));
	dp[0][0] = true;
	for (int i = 1; i <= s1.size(); i++) {
	  dp[i][0] = dp[i - 1][0] && (s1[i - 1] == s3[i - 1]);
	}
	for (int j = 1; j <= s2.size(); j++) {
	  dp[0][j] = dp[0][j - 1] && (s2[j - 1] == s3[j - 1]);
	}

	for (int i = 1; i <= s1.size(); i++) {
	  for (int j = 1; j <= s2.size(); j++) {
		int index = i + j - 1;
		dp[i][j] =
			(dp[i - 1][j] && (s1[i - 1] == s3[index])) ||
				(dp[i][j - 1] && (s2[j - 1] == s3[index]));
	  }
	}
	return dp[s1.size()][s2.size()];
  };
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


