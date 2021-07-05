#include <bits/stdc++.h>
#include <gtest/gtest.h>
using namespace std;


//// START
/*
## Reshape the Matrix

*/




class Solution {
 public:
  vector<vector<int>> matrixReshape(vector<vector<int>> &mat, int r, int c) {
	R = mat.size();
	C = mat[0].size();
	if (R * C % r != 0 || r * c < R * C) {
	  return mat;
	}
	c = R * C / r;
	vector<vector<int>> rets(r, vector<int>(c));
	for (int ri = 0; ri < r; ri++) {
	  for (int ci = 0; ci < c; ci++) {
		int len = c * ri + ci;
		rets[ri][ci] = mat[len / C][len % C];
	  }
	}
	return rets;
  }
 private:
  int R, C;

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

  Solution solution;
  vector<vector<int>> mat = {{1, 2}, {3, 4}};
  auto ret = solution.matrixReshape(mat, 1, 4);
  for (auto row : ret) {
	for (int n : row) {
	  printf("%d ", n);
	}
	cout << endl;
  }
  cout << endl;

}

int main() {
  testing::InitGoogleTest();

  return RUN_ALL_TESTS();
}


