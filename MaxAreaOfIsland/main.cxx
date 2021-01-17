#include <bits/stdc++.h>
#include <gtest/gtest.h>

using namespace std;

class Solution {
  public:
    int maxAreaOfIsland(vector<vector<int>> &grid) {
        R = grid.size();
        C = grid[0].size();
        for (int r = 0; r < R; r++) {
            for (int c = 0; c < C; c++) {
                if (visited[r * C + c] || grid[r][c] == 0) continue;
                visited[r * C + c] = true;
                int area = 1;
                dfs(grid, r, c, area);
                max_area = max(max_area, area);
            }
        }
        return max_area;
    }
  private:
    int R = 0, C = 0;
    unordered_map<int, bool> visited;
    vector<pair<int, int>> directions = {
        {0, 1},
        {0, -1},
        {-1, 0},
        {1, 0},
    };
    int max_area = 0;
    void dfs(const vector<vector<int>> &grid, int r, int c, int &area) {
        for (const auto &di:directions) {
            int x = r + di.first;
            int y = c + di.second;
            if (x < 0 || x >= R || y < 0 || y >= C || grid[x][y] == 0 || visited[x * C + y]) continue;
            visited[x * C + y] = true;
            area++;
            dfs(grid, x, y, area);
        }
    }
};

struct T {

};

TEST(Solution, test) {
    T ts[] = {
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


