#include <bits/stdc++.h>
#include <gtest/gtest.h>
using namespace std;

class Solution {
  public:
    int longestIncreasingPath(vector<vector<int>> &matrix) {
        if (matrix.empty()) return 0;
        R = matrix.size();
        C = matrix[0].size();
        dp.resize(R, vector<int>(C, 0));
        int ret = 0;
        for (int r = 0; r < R; r++) {
            for (int c = 0; c < C; c++) {
                ret = max(ret, longest(matrix, r, c));
            }
        }
        return ret;
    }
  private:
    vector<vector<int>> dp;
    int longest(const vector<vector<int>> &matrix, int r, int c) {
        if (dp[r][c] != 0) return dp[r][c];
        int ret = 1;
        for (auto di : directions) {
            int nr = r + di[0];
            int nc = c + di[1];
            if (nr >= 0 && nr < R && nc >= 0 && nc < C && matrix[nr][nc] > matrix[r][c]) {
                ret = max(ret, 1 + longest(matrix, nr, nc));
            }
        }

        dp[r][c] = ret;
        return ret;

    }
    int R = 0;
    int C = 0;
    vector<vector<int> > directions = {
        {0, 1},
        {0, -1},
        {1, 0},
        {-1, 0},
    };
};

struct T {
    vector<vector<int>> matrix;

};

TEST(Solution, test) {
    T ts[] = {
        {
            .matrix={
                {0},
                {1},
                {5},
                {5},
            }
        },
    };

    for (T t : ts) {
        Solution solution;
        cout << solution.longestIncreasingPath(t.matrix) << endl;

    }
}

int main() {
    testing::InitGoogleTest();

    return RUN_ALL_TESTS();
}


