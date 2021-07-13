#include <bits/stdc++.h>
#include <gtest/gtest.h>
using namespace std;


//// START
/*
## Find Peak Element

*/
class Solution {
 public:
  int findPeakElement(vector<int> &nums) {
	int left = 0, right = nums.size() - 1;
	while (left < right) {
	  int mid = left + (right - left) / 2;
	  if (nums[mid] > nums[mid + 1]) {
		right = mid;
	  } else {
		left = mid + 1;
	  }
	}
	return left;
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


