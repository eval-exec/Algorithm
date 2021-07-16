#include <bits/stdc++.h>
#include <gtest/gtest.h>
using namespace std;


//// START
/*
## Range Addition
*/

class Solution {
 public:
  vector<int> getModifiedArray(int length, vector<vector<int>> &updates) {
	vector<int> cmds(length + 1);
	for (const auto &update:updates) {
	  cmds[update[0]] += update[2];
	  cmds[update[1] + 1] -= update[2];
	}
	vector<int> rets(length);
	int value = 0;
	for (int i = 0; i < length; i++) {
	  value += cmds[i];
	  rets[i] = value;
	}
	return rets;
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


