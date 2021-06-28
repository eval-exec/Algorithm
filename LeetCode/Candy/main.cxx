#include <bits/stdc++.h>
#include <gtest/gtest.h>
using namespace std;


//// START
/*
## Candy

*/


class Solution {
 public:
  int candy(vector<int> &ratings) {
	vector<int> tmp(ratings.size());
	tmp[0] = 1;
	for (int i = 1; i < ratings.size(); i++) {
	  if (ratings[i] > ratings[i - 1]) {
		tmp[i] = tmp[i - 1] + 1;
	  } else {
		tmp[i] = 1;
	  }
	}
	int ret = tmp.back();
	for (int i = ratings.size() - 2; i >= 0; i--) {
	  if (ratings[i] > ratings[i + 1]) {
		tmp[i] = max(tmp[i], tmp[i + 1] + 1);
	  }
	  ret += tmp[i];
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


