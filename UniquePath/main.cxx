class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m,vector<int>(n));
        dp[0][0]=1;
        for (int i = 1;i< n;i++){
            dp[0][i] = 1;
        }
        for (int i = 1;i< m;i++){
            dp[i][0] = 1;
        }
        for (int i = 1;i< m;i++){
            for (int j=1;j< n;j++){
                dp[i][j] = dp[i-1][j] +dp[i][j-1];
            }
        }
        return dp[m-1][n-1];
    }
};
class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<int> dp(n,1);
        for (int i = 1;i< m;i++){
            vector<int> tmp(n);
            tmp[0] = 1;
            for (int j=1;j< n;j++){
                tmp[j] = tmp[j-1] + dp[j];
            }
            dp = tmp;
        }
        return dp[n-1];
    }
};
