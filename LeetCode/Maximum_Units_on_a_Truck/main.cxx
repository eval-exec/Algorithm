#include <bits/stdc++.h>
#include <gtest/gtest.h>
using namespace std;


//// START
/*
## Maximum Units on a Truck

*/

class Solution {
 public:
  int maximumUnits(vector<vector<int>> &boxTypes, int truckSize) {
	sort(boxTypes.begin(),
		 boxTypes.end(),
		 [](const vector<int> &b1, const vector<int> &b2) -> bool {
		   return b1[1] > b2[1];
		 });
	int ret = 0;
	for (auto box : boxTypes) {
	  if (truckSize == 0) break;
	  int n = box[0];
	  if (truckSize < box[0]) {
		n = truckSize;
	  }
	  truckSize -= n;
	  ret += n * box[1];
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


