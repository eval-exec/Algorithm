#include <bits/stdc++.h>
#include <gtest/gtest.h>
using namespace std;


//// START
/*
## Find K Closest Elements

*/

class Solution {
 public:
  vector<int> findClosestElements(vector<int> &arr, int k, int x) {
	sort(arr.begin(), arr.end(), [&x](const int &a, const int &b) -> bool {
	  if (abs(a - x) < abs(b - x)) {
		return true;
	  } else if (abs(a - x) == abs(b - x)) {
		return a < b;
	  }
	  return false;
	});
	sort(arr.begin(), arr.begin() + k);
	return vector<int>(arr.begin(), arr.begin() + k);
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


