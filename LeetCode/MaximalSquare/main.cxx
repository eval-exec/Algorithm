#include <bits/stdc++.h>
#include <gtest/gtest.h>

using namespace std;

class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        if (matrix.empty()) return 0;
        int rows = matrix.size();
        int cols = matrix[0].size();
        vector<vector<int>> dp(rows,vector<int>(cols,0));

        int max_area=0;
        for (int i = 0; i< rows;i++){
            for (int j = 0; j< cols;j++){
                if (matrix[i][j] == '1'){
                    int len = 1;
                    if (i > 0 && j > 0){
                        len = 1+min(dp[i][j-1],dp[i-1][j]);
                    }
                    if (matrix[i-len+1][j-len+1] == '1'){
                        dp[i][j] = len;
                    }else{
                        dp[i][j] = len-1;
                    }
                    max_area = max(max_area,dp[i][j]*dp[i][j]);
                }
            }
        }
        return max_area;
    }
};



class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        if (matrix.empty()) return 0;
        int rows = matrix.size();
        int cols = matrix[0].size();
        vector<int> dp(cols,0);
        int max_area=0;
        for (int i = 0;i < cols;i++){
            dp[i] = matrix[0][i] == '1'?1:0;
            if (dp[i]==1) max_area = 1;
        }
        for (int i = 1; i< rows;i++){
            vector<int> tmp(cols,0);
            for (int j = 0; j< cols;j++){
                if (matrix[i][j] == '1'){
                    int len = 1;
                    if (j > 0){
                        len = 1+min(tmp[j-1],dp[j]);
                    }
                    tmp[j] = matrix[i-len+1][j-len+1] == '1'? len:len-1;
                    max_area = max(max_area,tmp[j]*tmp[j]);
                }
            }
            dp = tmp;
        }
        return max_area;
    }
};

struct T{

};

TEST(Solution,test){
    T ts[] = {
        {

        },

    };

    Solution solution;

    for (T t : ts){

    }
}

int main() {
    testing::InitGoogleTest();

    return RUN_ALL_TESTS();
}


