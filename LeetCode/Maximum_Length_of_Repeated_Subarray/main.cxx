#include <bits/stdc++.h>
#include <gtest/gtest.h>
using namespace std;


//// START
/*
## Maximum Length of Repeated Subarray

*/



class Solution {
 public:
  int findLength(vector<int> &nums1, vector<int> &nums2) {
	vector<int> dp(nums2.size());
	int ret = dp[0];
	for (int i = 0; i < nums2.size(); i++) {
	  dp[i] = nums1[0] == nums2[i] ? 1 : 0;
	  ret = max(ret, dp[i]);
	}
	for (int i = 1; i < nums1.size(); i++) {
	  vector<int> tmp(dp);
	  dp[0] = nums1[i] == nums2[0] ? 1 : 0;
	  for (int j = 1; j < nums2.size(); j++) {
		if (nums1[i] == nums2[j]) {
		  dp[j] = 1 + tmp[j - 1];
		  ret = max(ret, dp[j]);
		} else {
		  dp[j] = 0;
		}
	  }
	}
	return ret;
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


