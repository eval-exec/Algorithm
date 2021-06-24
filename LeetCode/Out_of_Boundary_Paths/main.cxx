#include <bits/stdc++.h>
#include <gtest/gtest.h>
using namespace std;


//// START
/*
## Out of Boundary Paths

*/


class Solution {
 public:
  int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
	vector<vector<long>> dp(m, vector<long>(n));
	for (int move = 1; move <= maxMove; move++) {
	  vector<vector<long>> tmp(m, vector<long>(n));
	  for (int mi = 0; mi < m; mi++) {
		for (int ni = 0; ni < n; ni++) {
		  for (auto dir : dirs) {
			auto now = vector<int>{mi, ni};
			now[0] += dir[0];
			now[1] += dir[1];
			bool valid = true;
			if (now[0] < 0 || now[0] >= m || now[1] < 0 || now[1] >= n) valid = false;
			if (valid) {
			  tmp[mi][ni] += dp[now[0]][now[1]];
			} else {
			  tmp[mi][ni] += 1;
			}
			tmp[mi][ni] %= mod;
		  }
		}
	  }
	  dp = tmp;
	}
	return dp[startRow][startColumn] % mod;
  }
 private:
  const long mod = 1e9+7;
  vector<vector<int>> dirs = {
	  {1, 0},
	  {-1, 0},
	  {0, 1},
	  {0, -1},
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


