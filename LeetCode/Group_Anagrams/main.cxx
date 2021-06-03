#include <bits/stdc++.h>
#include <gtest/gtest.h>
using namespace std;


//// START
/*
## Group Anagrams

*/

class Solution {
 public:
  vector<vector<string>> groupAnagrams(vector<string> &strs) {

	map<string, int> mm;

	vector<vector<string>> rets;
	for (const string &str: strs) {
	  string tmp(str);
	  sort(tmp.begin(), tmp.end());
	  if (mm.find(tmp) == mm.end()) {
		rets.push_back({str});
		mm[tmp] = rets.size() - 1;
	  } else {
		rets[mm[tmp]].push_back(str);
	  }
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


