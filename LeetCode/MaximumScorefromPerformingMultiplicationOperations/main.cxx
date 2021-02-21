#include <bits/stdc++.h>
#include <gtest/gtest.h>
using namespace std;


class Solution {
public:
    int maximumScore(vector<int>& nums, vector<int>& multipliers) {
        int n = nums.size(),m = multipliers.size();
        vector<int> dp(m+1);
        dp[0] = multipliers[0] * nums[n-1];
        dp[1] = multipliers[0] * nums[0];
        for (int mi = 2 ;mi <= m;mi++){
            vector<int> tmp(m+1);
            tmp[0] = dp[0] + multipliers[mi -1] * nums[n - mi];
            tmp[mi] = dp[mi-1] + multipliers[mi-1] * nums[mi-1];
            for (int ni = 1;ni < mi;ni++){
                // left + right = mi;
                tmp[ni] = max(dp[ni-1] + multipliers[mi-1] * nums[ni-1], dp[ni] + multipliers[mi - 1] * nums[n -( mi - ni )] );
            }
            dp = tmp;
        }

        int ret = INT_MIN;
        for (auto x : dp){
            ret = max(ret,x);
        }
        return ret;
    }
};



struct T{

};

TEST(Solution,test){
    T ts[] = {
        {

        },
        {

        },

    };


    for (T t : ts){
        Solution solution;

    }
}

int main() {
    testing::InitGoogleTest();

    return RUN_ALL_TESTS();
}


