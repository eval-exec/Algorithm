#include <bits/stdc++.h>
#include <gtest/gtest.h>
using namespace std;


//// START
/*
## Array of Doubled Pairs

*/



class Solution {
 public:
  bool canReorderDoubled(vector<int> &arr) {
	map<int, int> negs, poss;
	unordered_map<int, int> all;
	for (int n : arr) {
	  all[n]++;
	  if (n > 0)poss[n]++;
	  else negs[n]++;
	}
	for (auto m : poss) {
	  if (all[m.first] > 0) {
		if (all[m.first] <= all[m.first * 2]) {
		  all[m.first * 2] -= all[m.first];
		  all[m.first] = 0;
		} else {
		  return false;
		}
	  }
	}
	for (auto m = negs.rbegin(); m != negs.rend(); m++) {
	  if (all[m->first] > 0) {
		if (all[m->first * 2] >= all[m->first]) {
		  all[m->first * 2] -= all[m->first];
		  all[m->first] = 0;
		} else {
		  return false;
		}
	  }
	}
	return true;
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


