#include <bits/stdc++.h>
#include <gtest/gtest.h>

using namespace std;

class Solution {
public:
    char findTheDifference(string s, string t) {
        array<int,26> vv = {0};
        for (const char &c: s){
            vv[c-'a']+=1;
        }
        for (const char &c: t){
            vv[c-'a']-=1;
        }
        for (int i = 0;i < 26;i++){
            if (vv[i] != 0 ) return char('a'+i);
        }
        return char(1);
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


