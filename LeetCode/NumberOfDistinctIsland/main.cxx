#include <bits/stdc++.h>
#include <gtest/gtest.h>

using namespace std;

class Solution {
  public:
    int numDistinctIslands(vector<vector<int>> &grid) {
        int R = grid.size();
        int C = grid[0].size();
        vector<vector<bool>> visited(R, vector<bool>(C));
        vector<vector<pair<int, int>>> islands;
        for (int r = 0; r < R; r++) {
            for (int c = 0; c < C; c++) {
                if (grid[r][c] == 0 || visited[r][c]) continue;

                queue<pair<int, int>> qq;

                qq.push(make_pair(r, c));
                visited[r][c] = true;

                vector<pair<int, int>> island;
                while (!qq.empty()) {
                    int qlen = qq.size();
                    while (qlen > 0) {
                        auto now = qq.front();
                        qq.pop();
                        island.push_back(now);
                        for (auto direction : directions) {
                            int rn = now.first + direction.first;
                            int cn = now.second + direction.second;
                            if (rn < 0 || rn >= R || cn < 0 || cn >= C || visited[rn][cn] || grid[rn][cn] == 0)
                                continue;
                            qq.push(make_pair(rn, cn));
                            visited[rn][cn] = true;
                        }
                        qlen--;
                    }
                }
                islands.push_back(island);
            }
        }
        unordered_set<bitset<50 * 50>> st;

        for (auto island : islands) {

            int minr = INT_MAX;
            int minc = INT_MAX;
            for (auto point: island) {
                minr = min(minr, point.first);
                minc = min(minc, point.second);
            }

            bitset<50 * 50> bs;
            for (int i = 0; i < island.size(); i++) {
                auto point = island[i];
                bs.set((point.first - minr) * 50 + (point.second - minc));
            }
            st.insert(bs);
        }
        return st.size();
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
    vector<vector<int>> grid;

};

TEST(Solution, test) {
    T ts[] = {
        {
            {{1, 1, 0, 0, 0}, {1, 1, 0, 0, 0}, {0, 0, 0, 1, 1}, {0, 0, 0, 1, 1}},
        },

    };

    for (T t : ts) {
        Solution solution;
        EXPECT_EQ(solution.numDistinctIslands(t.grid), 1);
    }
}

int main() {
    testing::InitGoogleTest();

    return RUN_ALL_TESTS();
}


