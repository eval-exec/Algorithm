#include <bits/stdc++.h>
#include <gtest/gtest.h>

using namespace std;

class Solution {
public:
    bool isAnagram(string s, string t) {
        array<int,26> aa={0};
        for (const char c : s){
            aa[c-'a']++;
        }
        for (const char c : t){
            aa[c-'a']--;
        }
        for (int n : aa){
            if (n != 0 ) return false;
        }
        return true;
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


