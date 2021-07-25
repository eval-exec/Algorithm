#include <bits/stdc++.h>
#include <gtest/gtest.h>
using namespace std;


//// START
/*
## Largest Number After Mutating Substring

*/

class Solution {
 public:
  string maximumNumber(string num, vector<int> &change) {
	bool muted = false;
	bool lastM = false;
	bool changed = false;
	for (int i = 0; i < num.size(); i++) {
	  int ori = num[i] - '0';
	  int af = change[ori];
	  if ((!muted || lastM || !changed) && af >= ori) {
		num[i] += af - ori;
		if (af != ori) changed = true;
		lastM = true;
		muted = true;
	  } else {
		lastM = false;
	  }
	}
	return num;
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


