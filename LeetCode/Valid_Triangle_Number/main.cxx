#include <bits/stdc++.h>
#include <gtest/gtest.h>
using namespace std;


//// START
/*
## Valid Triangle Number

*/


class Solution {
 public:
  int triangleNumber(vector<int> &nums) {
	sort(nums.begin(), nums.end());

	map<int, int> mm;
	mm[nums[0]] = 0;
	for (int i = 1; i < nums.size(); i++)
	  if (nums[i] != nums[i - 1])
		mm[nums[i]] = i;

	int count = 0;
	for (int i = 0; i < nums.size(); i++) {
	  for (int j = i + 1; j < nums.size(); j++) {
		int maxL = nums[i] + nums[j];
		const auto &l = mm.lower_bound(maxL);
		int r = nums.size() - 1;
		if (l != mm.end()) {
		  r = l->second;
		  if (l->first >= maxL) r--;
		}
		if (r > j) count += r - j;
	  }
	}
	return count;
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


