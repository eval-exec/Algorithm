#include <bits/stdc++.h>
#include <gtest/gtest.h>
using namespace std;


//// START
/*
## Trapping Rain Water


*/


class Solution {
 public:
  int trap(vector<int> &height) {
	vector<int> left(height.size());
	int m = 0;
	for (int i = 0; i < height.size(); i++) {
	  left[i] = max(height[i], m);
	  m = left[i];
	}
	m = 0;
	vector<int> right(height.size());
	for (int i = height.size() - 1; i >= 0; i--) {
	  right[i] = max(height[i], m);
	  m = right[i];
	}
	int ret = 0;
	for (int i = 0; i < height.size(); i++) ret += min(left[i], right[i]) - height[i];
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


