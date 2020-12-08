#include <bits/stdc++.h>
#include <gtest/gtest.h>

using namespace std;

/*

   Given a rows x cols binary matrix filled with 0's and 1's,

   find the largest rectangle containing only 1's and return its area.

*/


class Solution {
    public:
        int maximalRectangle(vector<vector<char>> &matrix) {
            if (matrix.empty()) return 0;
            int rows = matrix.size();
            int cols = matrix[0].size();
            vector<vector<int>> dp(rows,vector<int>(cols,0));
            int max_area=0;
            for (int i = 0; i< rows; i++){
                for (int j = 0; j < cols; j++){
                    if (matrix[i][j]=='1'){
                        if (j >0) dp[i][j]=1+dp[i][j-1];
                        else dp[i][j]=1;

                        int width = dp[i][j];
                        for (int h = i;h >=0 && matrix[h][j] == '1';h--){
                            width = min(width,dp[h][j]);
                            max_area = max(max_area,width*(i-h+1));
                        }
                    }
                }
            }
            return max_area;
        }
};


struct T {
    vector<vector<char>> matrix;
    int result;

};

TEST(Solution, test) {
    T ts[] = {
        {
            {{'1', '0', '1', '0', '0'}, {'1', '0', '1', '1', '1'}, {'1', '1', '1', '1', '1'}, {'1', '0', '0', '1', '0'}},
            6,
        },

    };

    Solution solution;

    for (T t : ts) {
        EXPECT_EQ(solution.maximalRectangle(t.matrix), t.result);
    }
}

int main() {
    testing::InitGoogleTest();

    return RUN_ALL_TESTS();
}


