#include <bits/stdc++.h>
#include <gtest/gtest.h>

using namespace std;

class Solution {
  public:
    int cherryPickup(vector<vector<int>> &grid) {
        int H = grid.size();
        int W = grid[0].size();
        vector<vector<vector<int>>> dp(H, vector<vector<int>>(W, vector<int>(W, -1)));
        for (int i = 0; i < W - 1; i++) {
            for (int j = 1; j < W; j++) {
                dp[H - 1][i][j] = grid[H - 1][i] + grid[H - 1][j];
            }
        }
        for (int r = H - 2; r >= 0; r--) {
            for (int i = 0; i < W - 1; i++) {
                for (int j = i + 1; j < W; j++) {
                    int childs = 0;
                    for (int ll = i - 1; ll <= i + 1; ll++) {
                        if (ll < 0 || ll == W - 1) continue;
                        for (int rr = j - 1; rr <= j + 1; rr++) {
                            if (rr == 0 || rr >= W || rr <= ll) continue;
                            childs = max(childs, dp[r + 1][ll][rr]);
                        }
                    }
                    dp[r][i][j] = grid[r][i] + grid[r][j] + childs;
                }
            }
        }
        return dp[0][0][W - 1];
    }
};

class Solution1 {
  public:
    int cherryPickup(vector<vector<int>> &grid) {
        int H = grid.size();
        int W = grid[0].size();
        vector<vector<vector<int>>> dp(H, vector<vector<int>>(W, vector<int>(W, -1)));
        dp[0][0][W - 1] = grid[0][0] + grid[0][W - 1];
        for (int r = 1; r < H; r++) {
            for (int i = 0; i < W - 1; i++) {
                for (int j = i + 1; j < W; j++) {
                    int parents = 0;
                    for (int ll = i - 1; ll <= i + 1; ll++) {
                        if (ll < 0 || ll == W - 1) continue;
                        for (int rr = j - 1; rr <= j + 1; rr++) {
                            if (rr == 0 || rr >= W) continue;
                            parents = max(parents, dp[r - 1][ll][rr]);
                        }
                    }
                    dp[r][i][j] = grid[r][i] + grid[r][j] + parents;
                }
            }
        }
        int ret = 0;
        for (int i = 0; i < W - 1; i++) {
            for (int j = 1; j < W; j++) {
                ret = max(ret, dp[H - 1][i][j]);
            }
        }
        return ret;
    }
};

struct T {

};

TEST(Solution, test) {
    T ts[] = {
        {

        },

    };

    Solution solution;

    for (T t : ts) {

    }
}

int main() {
    testing::InitGoogleTest();

    return RUN_ALL_TESTS();
}


