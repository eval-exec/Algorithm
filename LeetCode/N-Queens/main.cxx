#include <bits/stdc++.h>
#include <gtest/gtest.h>
using namespace std;


//// START
/*
## N-Queens

*/



class Solution {
 public:
  vector<vector<string>> solveNQueens(int n) {
	_n = n;
	vector<string> tops;
	dfs(tops);
	return rets;
  }
 private:
  vector<vector<string>> rets;
  string dots;
  int _n = 0;
  void dfs(vector<string> &tops) {
	if (tops.size() == _n) {
	  rets.push_back(tops);
	  return;
	}
	for (int i = 0; i < _n; i++) {
	  if (peace(tops, i)) {
		string tmp;
		tmp.resize(_n,'.');
		tmp[i] = 'Q';
		tops.push_back(tmp);
		dfs(tops);
		tops.pop_back();
	  }
	}
  }

  bool peace(const vector<string> &tops, int i) {
    if (tops.empty()) return true;
	int l1 = i-1, l2 = i+1;
	for (int r = tops.size()-1; r >= 0; r--) {
	  if (l1 >= 0 && tops[r][l1] == 'Q') return false;
	  if (l2 < _n && tops[r][l2] == 'Q') return false;
	  if (tops[r][i] == 'Q') return false;
	  l1--;
	  l2++;
	}
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

  }
  Solution solution;
  solution.solveNQueens(4);
}

int main() {
  testing::InitGoogleTest();

  return RUN_ALL_TESTS();
}


