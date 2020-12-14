#include <bits/stdc++.h>
#include <gtest/gtest.h>

using namespace std;


class Solution {
public:
    int numTrees(int n) {
        if (n <=2) return n;
        vector<int> dp(n+1);
        dp[0] = 1;
        dp[1] = 1;
        dp[2] = 2;
        for ( int i =3;i<=n;i++ ){
            int sum = 0;
            for (int x = 0;x < i;x++){
                sum += dp[x] * dp[i - 1 - x];
            }
            dp[i] = sum;
        }
        return dp[n];
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


