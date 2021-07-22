#include <bits/stdc++.h>
#include <gtest/gtest.h>
using namespace std;


//// START
/*
## Partition Array into Disjoint Intervals

*/

class Solution {
 public:
  int partitionDisjoint(vector<int> &nums) {
	map<int, int> left, right;
	left[nums[0]] = 1;
	for (int i = 1; i < nums.size(); i++) right[nums[i]] += 1;
	int i = 1;
	for (; i <= nums.size() - 1; i++) {
	  if (left.rbegin()->first <= right.begin()->first) return i;
	  left[nums[i]] += 1;
	  right[nums[i]] -= 1;
	  if (right[nums[i]] == 0)right.erase(nums[i]);
	}
	return -1;
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


