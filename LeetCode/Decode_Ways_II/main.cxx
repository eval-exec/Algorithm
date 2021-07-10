#include <bits/stdc++.h>
#include <gtest/gtest.h>
using namespace std;


//// START
/*
## Decode Ways II

*/

class Solution {
  int M = 1000000007;
 public:
  int numDecodings(string s) {
	vector<long> dp(s.length() + 1);
	dp[0] = 1;
	dp[1] = s[0] == '*' ? 9 : s[0] == '0' ? 0 : 1;
	for (int i = 1; i < s.length(); i++) {
	  if (s[i] == '*') {
		dp[i + 1] = 9 * dp[i] % M;
		if (s[i - 1] == '1')
		  dp[i + 1] = (dp[i + 1] + 9 * dp[i - 1]) % M;
		else if (s[i - 1] == '2')
		  dp[i + 1] = (dp[i + 1] + 6 * dp[i - 1]) % M;
		else if (s[i - 1] == '*')
		  dp[i + 1] = (dp[i + 1] + 15 * dp[i - 1]) % M;
	  } else {
		dp[i + 1] = s[i] != '0' ? dp[i] : 0;
		if (s[i - 1] == '1')
		  dp[i + 1] = (dp[i + 1] + dp[i - 1]) % M;
		else if (s[i - 1] == '2' && s[i] <= '6')
		  dp[i + 1] = (dp[i + 1] + dp[i - 1]) % M;
		else if (s[i - 1] == '*')
		  dp[i + 1] = (dp[i + 1] + (s[i] <= '6' ? 2 : 1) * dp[i - 1]) % M;
	  }
	}
	return (int) dp[s.length()];
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


