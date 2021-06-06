#include <bits/stdc++.h>
#include <gtest/gtest.h>
using namespace std;


//// START
/*
## Reduction Operations to Make the Array Elements Equal

*/


class Solution {
 public:
  int reductionOperations(vector<int> &nums) {
	map<int, int> mm;
	int mn = INT_MAX;
	for (int n : nums) {
	  mm[n]++;
	  mn = min(mn, n);
	}

	int ret = 0;
	int lastn = 0;
	for (auto it = mm.rbegin(); it != mm.rend(); it++) {
	  if (it->first == mn) continue;
	  lastn = it->second + lastn;
	  ret += lastn;
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


