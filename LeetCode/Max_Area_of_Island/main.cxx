#include <bits/stdc++.h>
#include <gtest/gtest.h>
using namespace std;


//// START
/*
## Max Area of Island

*/

class Solution {
 public:
  int maxAreaOfIsland(vector<vector<int>> &grid) {
	R = grid.size();
	C = grid[0].size();
	vector<vector<bool>> visited(R, vector<bool>(C));
	int maxAre= 0;
	for (int r = 0; r < R; r++) {
	  for (int c = 0; c < C; c++) {
		if (grid[r][c] == 0) continue;
		if (visited[r][c]) continue;
		int area = 0;
		visit(visited, grid,area,r, c);
		maxAre = max(maxAre,area);
	  }
	}
	return maxAre;
  }
 private:
  int R = 0, C = 0;
  void visit(vector<vector<bool>> &visited,vector<vector<int>> &grid,int &area, int r, int c) {
	if (r < 0 || r >= R) return;
	if (c < 0 || c >= C) return;
	if (grid[r][c] != 1) return;
	if (visited[r][c]) return;
	area++;
	visited[r][c] = true;
	visit(visited, grid,area,r + 1, c);
	visit(visited, grid,area,r - 1, c);
	visit(visited,grid, area,r, c + 1);
	visit(visited,grid, area,r, c - 1);
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


