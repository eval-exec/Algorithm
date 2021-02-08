#include <bits/stdc++.h>
#include <gtest/gtest.h>

using namespace std;

class Solution {
public:
    int largestSubmatrix(vector<vector<int>>& matrix) {
        int R = matrix.size();
        int C = matrix[0].size();
        vector<int> dp(C);
        int max_area = 0;
        for (int c = 0;c < C;c++){
            dp[c] = matrix[0][c];
            if (dp[c]) max_area++;
        }
        for (int r = 1 ;r < R;r++){
            for (int c = 0;c < C;c++){
                if (matrix[r][c]) dp[c]++;
                else dp[c] = 0;
            }
            vector<int> tmp(dp);
            sort(tmp.begin(),tmp.end());
            for (int c = C-1 ;c >=0;c--){
                max_area = max(max_area,(C -c)* tmp[c]);
            }
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


