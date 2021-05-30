#include <bits/stdc++.h>
#include <gtest/gtest.h>
using namespace std;


//// START
/*
## Maximum Value after Insertion

*/

class Solution {
 public:
  string maxValue(string n, int x) {
	char inc = '0' + x;
	if (n[0] == '-') {
	  for (int i = 1; i < n.size(); i++) {
		if (n[i] - '0' > x) {
		  n.insert(i, 1, inc);
		  return n;
		}
	  }
	  n.push_back(inc);
	}else{

	  for (int i = 0; i < n.size(); i++) {
		if (n[i] - '0' < x) {
		  n.insert(i, 1, inc);
		  return n;
		}
	  }
	  n.push_back(inc);
	}
	return n;
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


