#include <bits/stdc++.h>
#include <gtest/gtest.h>
using namespace std;


//// START
/*
## Add Minimum Number of Rungs

*/

class Solution {
 public:
  int addRungs(vector<int> &rungs, int dist) {
	int count = 0;
	if (rungs[0] > dist) {
	  count = rungs[0] / dist;
	  if (rungs[0] % dist == 0)count--;
	}
	for (int i = 1; i < rungs.size(); i++) {
	  if (rungs[i] - rungs[i - 1] > dist) {
		int del = (rungs[i] - rungs[i - 1]) / dist;
		if ((rungs[i] - rungs[i - 1]) % dist == 0)del--;
		count += del;
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


