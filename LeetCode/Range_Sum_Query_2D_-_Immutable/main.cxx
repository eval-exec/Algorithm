#include <bits/stdc++.h>
#include <gtest/gtest.h>
using namespace std;


//// START
/*
## Range Sum Query 2D - Immutable

*/

class NumMatrix {
  private:
    vector<vector<int>> pm;
  public:
    NumMatrix(vector<vector<int>> &matrix) {
        pm.resize(matrix.size(), vector<int>(matrix[0].size()));
        for (int r = 0; r < matrix.size(); r++) {
            int csum = 0;
            for (int c = 0; c < matrix[0].size(); c++) {
                csum += matrix[r][c];
                int up = 0;
                if (r > 0) {
                    up = pm[r - 1][c];
                }
                pm[r][c] = up + csum;
            }
        }
    }

    int sumRegion(int row1, int col1, int row2, int col2) {

        /*
         *   a1 | a2
         * ----------
         *   a3 | a4
         */
        int a1 = 0, a2 = 0, a3 = 0, a4 = 0;
        a4 = pm[row2][col2];
        if (row1 > 0) {
            a2 = pm[row1 - 1][col2];
        }
        if (col1 > 0) {
            a3 = pm[row2][col1 - 1];
        }
        if (row1 > 0 && col1 > 0) {
            a1 = pm[row1 - 1][col1 - 1];
        }

        return a4 - a2 - a3 + a1;
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */


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


