#include <bits/stdc++.h>
#include <gtest/gtest.h>

using namespace std;


class Solution {
public:
    int countSquares(vector<vector<int>> &matrix) {
        int rows = matrix.size();
        if (rows == 0) return 0;
        int cols = matrix[0].size();
        if (cols == 0) return 0;
        vector<int> dp(cols);
        int count = 0;
        for (int c = 0; c < cols; c++) {
            if (matrix[0][c] == 1) {
                dp[0] = 1;
                count++;
            }
        }
        for (int r = 1; r < rows; r++) {
            vector<int> tmp(cols);
            if (matrix[r][0] == 1) {
                tmp[0] = 1;
                count++;
            }
            for (int c = 1; c < cols; c++) {
                if (matrix[r][c] == 0) continue;
                int len = min(tmp[c - 1], dp[c]);
                if (matrix[r - len][c - len] == 1) tmp[c] = len + 1;
                else tmp[c] = len;
                count += tmp[c];
            }
            dp = tmp;
        }
        return count;
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


