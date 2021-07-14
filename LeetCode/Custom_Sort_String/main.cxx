#include <bits/stdc++.h>
#include <gtest/gtest.h>
using namespace std;


//// START
/*
## Custom Sort String

*/


class Solution {
 public:
  string customSortString(string order, string str) {
	unordered_map<char, int> mm;
	for (int i = 0; i < order.size(); i++) {
	  mm[order[i]] = i;
	}
	sort(str.begin(), str.end(), [mm](const char &c1, const char &c2) -> bool{
	  return mm[c1] < mm[c2];
	});
	return str;
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


