#include <bits/stdc++.h>
#include <gtest/gtest.h>
using namespace std;


//// START
/*
## Maximum Product of Word Lengths

*/
class Solution {
 public:
  int maxProduct(vector<string> &words) {
    bitset<26> zero;

	vector<bitset<26>> memo(words.size());
	for (int i = 0; i < words.size(); i++) {
	  vector<bool> x(26);
	  for (char c : words[i]) {
		memo[i].set(c - 'a');
	  }
	}
	int ret = 0;
	for (int i = 0; i < words.size(); i++) {
	  for (int j = i + 1; j < words.size(); j++) {
		if ((memo[i] & memo[j]) == zero) {
		  ret = max(ret, int(words[i].size() * words[j].size()));
		}
	  }

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


