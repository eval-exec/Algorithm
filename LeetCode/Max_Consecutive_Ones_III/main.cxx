#include <bits/stdc++.h>
#include <gtest/gtest.h>
using namespace std;


//// START
/*
## Max Consecutive Ones III

*/

class Solution {
 public:
  int longestOnes(vector<int> &nums, int k) {
	int lasti = 0;
	int ret = 0;
	for (int i = 0; i < nums.size(); i++) {
	  if (nums[i] == 0) {
		k--;
		if (k < 0) {
		  while (nums[lasti] == 1) {
			lasti++;
		  }
		  lasti++;
		  k++;
		}
	  }
	  ret = max(ret, i - lasti + 1);
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


