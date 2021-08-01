#include <bits/stdc++.h>
#include <gtest/gtest.h>
using namespace std;


//// START
/*
## Making A Large Island

*/


class Solution {
 public:
  int largestIsland(vector<vector<int>> &grid) {
	unordered_map<int, bool> globalVisited;
	unordered_map<int, int> position2index, islandArea;
	R = grid.size(), C = grid[0].size();
	int islandIndex = 0;
	for (int r = 0; r < R; r++) {
	  for (int c = 0; c < C; c++) {
		if (grid[r][c] == 0)continue;
		if (globalVisited[position(r, c)]) continue;
		islandIndex++;

		globalVisited[position(r, c)] = true;
		position2index[position(r, c)] = islandIndex;

		queue<pair<int, int>> qq;
		qq.push(make_pair(r, c));
		while (!qq.empty()) {
		  auto now = qq.front();
		  qq.pop();

		  islandArea[islandIndex]++;

		  for (auto di : directions) {
			int x = now.first + di[0];
			int y = now.second + di[1];
			if (x >= 0 && x < R && y >= 0 && y < C && grid[x][y] == 1
				&& !globalVisited[position(x, y)]) {
			  globalVisited[position(x, y)] = true;
			  position2index[position(x, y)] = islandIndex;
			  qq.push(make_pair(x, y));
			}
		  }
		}
	  }
	}
	int maxArea = 0;
	for (auto m : islandArea) maxArea = max(maxArea, m.second);
	for (int r = 0; r < R; r++) {
	  for (int c = 0; c < C; c++) {
		if (grid[r][c] == 0) {
		  unordered_map<int, int> area;
		  for (auto di: directions) {
			int x = di[0] + r,y = di[1] + c;
			if (x >= 0 && x < R && y >= 0 && y < C && grid[x][y] == 1) {
			  int island = position2index[position(x, y)];
			  area[island] = islandArea[island];
			}
		  }
		  int s = 0;
		  for (auto ar : area) s += ar.second;
		  maxArea = max(maxArea, s + 1);
		}
	  }
	}
	return maxArea;
  }
 private:
  vector<vector<int>> directions = {{1, 0}, {-1, 0}, {0, 1}, {0, -1},};
  int R = 0, C = 0;
  int position(int x, int y) {
	return x * 500 + y;
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


