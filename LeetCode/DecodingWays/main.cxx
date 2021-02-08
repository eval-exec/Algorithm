#include <bits/stdc++.h>
#include <gtest/gtest.h>

using namespace std;

class Solution {
public:
    int numDecodings(string s) {
        vector<int> dp(s.size()+2);
        dp[s.size()] = 1;
        dp[s.size()+1] = 0;
        for (int i = s.size()-1;i>=0;i--){
            int n = s[i] - '0';
            if (n == 0 ){
                if (i == 0 || (s[i-1] != '1' && s[i-1] != '2') ) return 0;
                dp[i] = 0;
                dp[i-1] = dp[i+1];
                i--;
            }else{
                if (n >=3 || (n == 2 && i < s.size()-1 && s[i+1] - '0' > 6 ) ){
                    dp[i] = dp[i+1];
                }else{
                    dp[i] = dp[i+1] + dp[i+2];
                }
            }
        }
        
        return dp[0];
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


