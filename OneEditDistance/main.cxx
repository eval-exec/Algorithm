#include <bits/stdc++.h>
#include <gtest/gtest.h>

using namespace std;

class Solution {
public:
    bool isOneEditDistance(string s, string t) {
        vector<vector<int>> dp(s.size(),vector<int>(t.size()));
        if (s.empty()) return 1 == t.size();
        if (t.empty()) return 1 == s.size();
        {
            int diff = int(s.size())- int(t.size());
            if (diff > 1 || diff < -1){
                return false;
            }
        }
        if (s.size() == t.size()){
            int diff = 0;
            for (int i = 0;i < s.size();i++){
                if (s[i] != t[i]) diff++;
                if (diff > 1) return false;
            }
            if (diff == 0) return false;
        }else{
            if (s.size() > t.size()){
                swap(s,t);
            }
            int down = 0;
            for (int up = 0; up < s.size();up++,down++){
                if (s[up] == t[down]){
                    continue;
                }else{
                    if (up != down) return false;
                    up--;
                }
            }
        }
        return true;
    }
};




struct T{
    string s;
    string t;
    bool e;

};

TEST(Solution,test){
    T ts[] = {
        {
            "ab",
            "acd",
           false 
        },
        {
            "aa",
            "aa",
           false 
        },
        {
            "cabc",
            "cac",
          true 
        },
        {
            "cabc",
            "abc",
          true 
        },
        {
            "abc",
            "cabc",
          true 
        },
        {
            "ab",
            "ac",
          true 
        },

        {
            "a",
            "a",
           false 
        },
        {
            "a",
            "b",
            true
        },

    };


    for (T t : ts){
        Solution solution;
        EXPECT_EQ(solution.isOneEditDistance(t.s,t.t),t.e);

    }
}

int main() {
    testing::InitGoogleTest();

    return RUN_ALL_TESTS();
}


