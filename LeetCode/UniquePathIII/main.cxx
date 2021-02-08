#include <bits/stdc++.h>

using namespace  std;
class Solution {
  private:
    int white = 0;
    int count = 0;
  public:
    int uniquePathsIII(vector<vector<int>> &grid) {
        int m = 0, n = 0;
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if (grid[i][j] == 1) {
                    m = i;
                    n = j;
                } else if (grid[i][j] == 0) {
                    white++;
                }
            }
        }
        dfs(grid, m, n, 0);
        return count;
    }
    void dfs(vector<vector<int>> &grid, int r, int c, int steps) {
        if (grid[r][c] == -1) return;
        if (grid[r][c] == 2) {
            if (steps - 1 == white) count++;
            return;
        }
        if (r > 0) {
            grid[r][c] = -1;
            dfs(grid, r - 1, c, steps + 1);
            grid[r][c] = 0;
        }
        if (r < grid.size() - 1) {
            grid[r][c] = -1;
            dfs(grid, r + 1, c, steps + 1);
            grid[r][c] = 0;
        }
        if (c > 0) {
            grid[r][c] = -1;
            dfs(grid, r, c - 1, steps + 1);
            grid[r][c] = 0;
        }
        if (c < grid[0].size() - 1) {
            grid[r][c] = -1;
            dfs(grid, r, c + 1, steps + 1);
            grid[r][c] = 0;
        }
        return;
    }
};
