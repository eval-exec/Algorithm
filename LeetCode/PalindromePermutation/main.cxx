#include <bits/stdc++.h>
#include <gtest/gtest.h>

using namespace std;


class Solution {
public:
    bool canPermutePalindrome(string s) {
        int len = s.size();
        unordered_set<char> ss;
        for (const char &c : s){
            if (ss.count(c) == 1){
                ss.erase(c);
            }else{
                ss.insert(c);
            }
        }
        if (ss.empty()) return true;
        return ss.size() == 1 && len %2 == 1;
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


