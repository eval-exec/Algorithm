#include <bits/stdc++.h>
#include <gtest/gtest.h>
using namespace std;


//// START
/*
## N-Queens II

*/


class Solution {
 public:
  int totalNQueens(int n) {
	board.resize(n, vector<bool>(n));

	N = n;
	ok(0);
	return count;
  }
 private:
  int count = 0;
  vector<vector<bool>> board;
  int N = 0;
  void ok(int r) {
	if (r == N) {
	  count++;
	  return;
	}
	for (int c = 0; c < N; c++) {
	  int c1 = c, c2 = c;
	  bool valid = true;
	  for (int ri = r - 1; ri >= 0; ri--) {
		c1--;
		c2++;
		if (board[ri][c]) {
		  valid = false;
		  break;
		}
		if (c1 >= 0 && board[ri][c1]) {
		  valid = false;
		  break;
		}
		if (c2 < N && board[ri][c2]) {
		  valid = false;
		  break;
		}
	  }
	  if (valid) {
		board[r][c] = true;
		ok(r + 1);
		board[r][c] = false;
	  }
	}
  }
};

//// END
struct T {

};

TEST(Solution, test) {
  {Solution solution; cout << solution.totalNQueens(1) << endl;}
  {Solution solution; cout << solution.totalNQueens(2) << endl;}
  {Solution solution; cout << solution.totalNQueens(3) << endl;}
  {Solution solution; cout << solution.totalNQueens(4) << endl;}
  {Solution solution; cout << solution.totalNQueens(5) << endl;}
  {Solution solution; cout << solution.totalNQueens(6) << endl;}
  {Solution solution; cout << solution.totalNQueens(7) << endl;}
  {Solution solution; cout << solution.totalNQueens(8) << endl;}
  {Solution solution; cout << solution.totalNQueens(9) << endl;}
}

int main() {
  testing::InitGoogleTest();

  return RUN_ALL_TESTS();
}


