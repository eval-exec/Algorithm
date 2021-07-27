#include <bits/stdc++.h>
#include <gtest/gtest.h>
using namespace std;


//// START
/*
## 3Sum Closest

*/


class Solution {
 public:
  int threeSumClosest(vector<int> &nums, int target) {
    sort(nums.begin(),nums.end());
	int df = INT_MAX;
	int ret = 0;
	for (int i = 0; i < nums.size(); i++) {
	  int low = i + 1, high = nums.size() - 1;
	  while (low < high) {
		int sum = nums[i] + nums[low] + nums[high];
		int diff = sum - target;
		if (diff == 0) {
		  return target;
		} else if (diff < 0) {
		  low++;
		} else {
		  high--;
		}
		if (abs(diff) < df) {
		  df = abs(diff);
		  ret = sum;
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


