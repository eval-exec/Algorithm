#include <bits/stdc++.h>
#include <gtest/gtest.h>

using namespace std;

class Solution {
public:
    vector<vector<int>> matrixBlockSum(vector<vector<int>> &mat, int K) {
        rows = mat.size();
        if (rows == 0) return {};

        cols = mat[0].size();
        if (cols == 0) return {};
        dp = vector<vector<int>>(rows, vector<int>(cols));

        {
            int sum = 0;
            for (int c = 0; c < cols; c++) {
                sum += mat[0][c];
                dp[0][c] = sum;
            }
        }
        {
            int sum = 0;
            for (int r = 0; r < rows; r++) {
                sum += mat[r][0];
                dp[r][0] = sum;
            }
        }

        for (int r = 1; r < rows; r++) {
            int sum = mat[r][0];
            for (int c = 1; c < cols; c++) {
                sum += mat[r][c];
                dp[r][c] = dp[r - 1][c] + sum;
            }
        }

        vector<vector<int> > rets(rows, vector<int>(cols));
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                rets[i][j] = cal(i, j, K);
            }
        }
        return rets;
    }

private:
    vector<vector<int> > dp;
    int rows;
    int cols;

    int cal(int r, int c, int K) {
        return trive(r + K, c + K) - trive(r - K - 1, c + K) - trive(r + K, c - K - 1) + trive(r - K - 1, c - K - 1);
    }

private:
    int trive(int r, int c) {
        if (r < 0 || c < 0) return 0;
        if (r >= rows) r = rows - 1;
        if (c >= cols) c = cols - 1;
        return dp[r][c];
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


