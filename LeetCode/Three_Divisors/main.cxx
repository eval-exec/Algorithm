#include <bits/stdc++.h>
#include <gtest/gtest.h>
using namespace std;


//// START
/*
## Three Divisors

*/


class Solution {
 public:
  bool isThree(int n) {
	if (n <= 2) return false;
	int mi = sqrt(n);
	if (mi * mi != n) return false;
	for (int i = 2; i < mi; i++)
	  if (n % i == 0) return false;
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


