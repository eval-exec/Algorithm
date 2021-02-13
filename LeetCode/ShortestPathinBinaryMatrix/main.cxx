#include <bits/stdc++.h>
#include <gtest/gtest.h>

using namespace std;

class Solution {
  public:
    int shortestPathBinaryMatrix(vector<vector<int>> &grid) {
        int N = grid.size();
        if (grid[0][0] == 1) return -1;
        vector<vector<bool>> visited(N, vector<bool>(N));

        queue<array<int, 2>> qq;
        qq.push({0, 0});
        visited[0][0] = true;
        int steps = 1;
        while (!qq.empty()) {
            int qlen = qq.size();
            while (qlen > 0) {
                auto now = qq.front();
                qq.pop();
                if (now[0] == N - 1 && now[1] == N - 1) return steps;

                for (const auto &di : directions) {
                    int r = now[0] + di[0];
                    int c = now[1] + di[1];
                    if (r < 0 || r >= N || c < 0 || c >= N || grid[r][c] == 1 || visited[r][c]) continue;
                    visited[r][c] = true;
                    qq.push({r, c});
                }
                qlen--;
            }
            steps++;
        }
        return -1;
    }
  private:
    vector<array<int, 2>> directions = {
        {-1, 0},
        {1, 0},
        {0, -1},
        {0, 1},

        {-1, -1},
        {-1, 1},
        {1, -1},
        {1, 1},
    };
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


