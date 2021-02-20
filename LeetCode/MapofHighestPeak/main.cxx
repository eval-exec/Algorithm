#include <bits/stdc++.h>
#include <gtest/gtest.h>
using namespace std;
class Solution {
  public:
    vector<vector<int>> highestPeak(vector<vector<int>> &isWater) {
        int R = isWater.size();
        int C = isWater[0].size();
        vector<vector<bool>> visited(R, vector<bool>(C));
        queue<pair<int, int>> qq;
        for (int r = 0; r < R; r++) {
            for (int c = 0; c < C; c++) {
                if (isWater[r][c] == 1) {
                    qq.push(make_pair(r, c));
                    isWater[r][c] = 0;
                    visited[r][c] = true;
                }
            }
        }
        while (!qq.empty()) {
            int qlen = qq.size();
            while (qlen > 0) {
                qlen--;

                auto now = qq.front();
                qq.pop();
                for (auto di : directions) {
                    int nr = now.first + di.first;
                    int nc = now.second + di.second;
                    if (nr < 0 || nr >= R || nc < 0 || nc >= C || visited[nr][nc]) continue;
                    visited[nr][nc] = true;
                    isWater[nr][nc] = isWater[now.first][now.second] + 1;
                    qq.push(make_pair(nr, nc));
                }
            }
        }
        return isWater;
    }
  private:
    vector<pair<int, int>> directions = {
        {0, 1},
        {0, -1},
        {-1, 0},
        {1, 0},
    };
};

struct T {
    vector<vector<int>> isWater;

};

TEST(Solution, test) {
    T ts[] = {
        {
            {{0, 0, 1}, {1, 0, 0}, {0, 0, 0}}
        },

    };

    for (T t : ts) {
        Solution solution;
        auto r = solution.highestPeak(t.isWater);
        for (auto row : r) {
            for (int n : row) {
                printf("%d ", n);
            }
            cout << endl;
        }

    }
}

int main() {
    testing::InitGoogleTest();

    return RUN_ALL_TESTS();
}


