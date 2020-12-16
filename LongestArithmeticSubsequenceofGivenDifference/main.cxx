#include <bits/stdc++.h>
#include <gtest/gtest.h>

using namespace std;

class Solution {
public:
    int longestSubsequence(vector<int>& arr, int difference) {
        unordered_map<int,int> mm;
        vector<int> dp(arr.size());
        int count = 0;
        for (int i = 0;i < arr.size();i++){
            {
                auto f = mm.find(arr[i] - difference);
                if (f != mm.end()){
                    dp[i] = dp[f->second] +1;
                }else{
                    dp[i] = 1;
                }
            }
            mm[arr[i]] = i;
            count = max(count, dp[i]);
        }
        return count;
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


