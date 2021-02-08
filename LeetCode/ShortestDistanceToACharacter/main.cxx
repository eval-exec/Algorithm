#include <bits/stdc++.h>
#include <gtest/gtest.h>

using namespace std;

class Solution {
public:
    vector<int> shortestToChar(string s, char c) {
        vector<int> ans(s.size(),INT_MAX);
        int last = -1;
        int len = s.size();
        for (int i = 0 ;i < len;i++){
            if (s[i] == c){
                last = i;
            }
            if (last == -1) continue;
            ans[i] = i-last;
        }
        last = -1;
        for (int i = len-1 ;i >= 0;i--){
            if (s[i] == c){
                last = i;
            }
            if (last == -1) continue;
            ans[i] = min(last-i,ans[i]);
        }
        return ans;
    }
};




struct T{

};

TEST(Solution,test){
    T ts[] = {
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


