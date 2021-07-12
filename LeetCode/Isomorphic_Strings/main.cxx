#include <bits/stdc++.h>
#include <gtest/gtest.h>
using namespace std;


//// START
/*
## Isomorphic Strings

*/



class Solution {
 public:
  bool isIsomorphic(string s, string t) {
	unordered_map<char, int> ms;
	unordered_map<char, int> mt;
	int index = 0;
	for (int i = 0; i < s.size(); i++) {
	  int si = ms[s[i]];
	  int ti = mt[t[i]];
	  if (si != ti) return false;
	  if (si == 0) {
		index++;
		ms[s[i]] = index;
		mt[t[i]] = index;
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


