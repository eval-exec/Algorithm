#include <bits/stdc++.h>
#include <gtest/gtest.h>
using namespace std;


//// START
/*
## Paint House

*/
class Solution {
 public:
  int minCost(vector<vector<int>> &costs) {
	array<int, 3> dp;
	dp[0] = costs[0][0];
	dp[1] = costs[0][1];
	dp[2] = costs[0][2];
	for (int i = 1; i < costs.size(); i++) {
	  array<int, 3> tmp(dp);
	  dp[0] = costs[i][0] + min(tmp[1], tmp[2]);
	  dp[1] = costs[i][1] + min(tmp[0], tmp[2]);
	  dp[2] = costs[i][2] + min(tmp[0], tmp[1]);
	}
	return min(dp[0],min(dp[1],dp[2]));
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


