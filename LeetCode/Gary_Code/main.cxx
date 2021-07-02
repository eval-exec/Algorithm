#include <bits/stdc++.h>
#include <gtest/gtest.h>
using namespace std;


//// START
/*
## Gary Code

*/

/*
 000
 001
 011
 010

 110
 111
 101
 100

 */



class Solution {
 public:
  vector<int> grayCode(int n) {
	vector<int> rets;
	vector<int> base(n);
	for (int i = 0; i < (1 << n); i++) {
	  int x = 0;
	  for (int ni = 1; ni <= n; ni++) {
		int b = pow(2, ni);
		int bit = 0;
		if (((i + b / 2) / b) % 2 != 0) {
		  bit = 1;
		}
		x |= (bit << (ni - 1));
	  }
	  rets.push_back(x);
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


