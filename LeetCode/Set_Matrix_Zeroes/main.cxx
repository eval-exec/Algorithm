#include <bits/stdc++.h>
#include <gtest/gtest.h>
using namespace std;


//// START
/*
## Set Matrix Zeroes

*/

class Solution {
 public:
  void setZeroes(vector<vector<int>> &matrix) {
	auto memo = make_pair(-1, -1);
	bool notfound = true;
	for (int r = 0; r < matrix.size() && notfound; r++) {
	  for (int c = 0; c < matrix[0].size(); c++) {
		if (matrix[r][c] == 0) {
		  memo = make_pair(r, c);
		  notfound = false;
		  break;
		}
	  }
	}
	if (notfound) return;
	for (int r = 0; r < matrix.size(); r++) {
	  if (matrix[r][memo.second] == 0)continue;
	  for (int c = 0; c < matrix[0].size(); c++) {
		if (matrix[r][c] == 0)matrix[r][memo.second] = 0;
	  }
	}
	for (int c = 0; c < matrix[0].size(); c++) {
	  if (matrix[memo.first][c] == 0)continue;
	  for (int r = 0; r < matrix.size(); r++) {
		if (matrix[r][c] == 0) matrix[memo.first][c] = 0;
	  }
	}
	for (int r = 0; r < matrix.size(); r++) {
	  if (r == memo.first) continue;
	  if (matrix[r][memo.second] != 0)continue;
	  for (int c = 0; c < matrix[0].size(); c++) matrix[r][c] = 0;
	}
	for (int c = 0; c < matrix[0].size(); c++) {
	  if (matrix[memo.first][c] != 0)continue;
	  for (int r = 0; r < matrix.size(); r++) matrix[r][c] = 0;
	}
	for (int c = 0; c < matrix[0].size(); c++) matrix[memo.first][c] = 0;
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


