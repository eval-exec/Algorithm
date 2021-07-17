#include <bits/stdc++.h>
#include <gtest/gtest.h>
using namespace std;


//// START
/*
## Three Equal Parts

*/


class Solution {
 public:
  vector<int> threeEqualParts(vector<int> &arr) {
	int ones = 0;
	for (int i = 0; i < arr.size(); i++) {
	  if (arr[i] == 1)ones++;
	}
	if (ones == 0) return {0, int(arr.size() - 1)};
	if (ones % 3 != 0)return {-1, -1};

	int i1 = -1, j1 = -1, k1 = -1;
	int i2 = -1, j2 = -1, k2 = -1;
	{
	  int n = 0;
	  for (int x = 0; x < arr.size(); x++) {
		if (arr[x] == 1)n++;
		if (n == 1 && i1 == -1) i1 = x;
		if (n == ones / 3 && i2 == -1) i2 = x;

		if (n == ones / 3 + 1 && j1 == -1) j1 = x;
		if (n == 2 * ones / 3 && j2 == -1) j2 = x;

		if (n == 2 * ones / 3 + 1 && k1 == -1) k1 = x;
		if (n == ones) {
		  k2 = x;
		  break;
		}
	  }
	}

	const vector<int> a1 = vector<int>(arr.begin() + i1, arr.begin() + i2);
	const vector<int> a2 = vector<int>(arr.begin() + j1, arr.begin() + j2);
	const vector<int> a3 = vector<int>(arr.begin() + k1, arr.begin() + k2);
	if (a1 != a2 || a1 != a3) return {-1, -1};

	int z = arr.size() - k2 - 1;
	if (j1 - i2 <= z || k1 - j2 <= z) return {-1, -1};
	return {i2 + z, j2 + z + 1};
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


