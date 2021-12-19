#include <bits/stdc++.h>
#include <gtest/gtest.h>
using namespace std;


//// START
/*
## 123. Best Time to Buy and Sell Stock III

*/

class Solution {
 public:
  int maxProfit(vector<int> &prices) {
	vector<int> dp(prices.size(), 0);
	dp[0] = 0;
	if (prices.size() <= 1)return 0;

	{
	  int low = prices[0];
	  for (int i = 1; i < prices.size(); i++) {
		dp[i] = prices[i] - low > dp[i - 1] ? prices[i] - low : dp[i - 1];
		low = prices[i] < low ? prices[i] : low;
	  }
	}
	int maxProfit = dp.back();
	dp[prices.size() - 1] = 0;
	{
	  int high = prices[prices.size() - 1];
	  for (int i = prices.size() - 2; i >= 1; i--) {
		dp[i] = high - prices[i] > dp[i + 1] ? high - prices[i] : dp[i + 1];
		high = prices[i] > high ? prices[i] : high;
		maxProfit = max(maxProfit, dp[i - 1] + dp[i]);
	  }
	}
	return maxProfit;
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

  for (T t: ts) {
	Solution solution;

  }
}

int main() {
  testing::InitGoogleTest();

  return RUN_ALL_TESTS();
}


