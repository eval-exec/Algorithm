#include <bits/stdc++.h>
#include <gtest/gtest.h>
using namespace std;

class Solution {
public:
    bool isStrobogrammatic(string num) {
        int len = num.size();
        for (int i = 0 ;i < len/2;i++){
            auto f = mm.find(num[i]);
            if (f == mm.end()) return false;
            if (f->second != num[len-1-i]) return false;
        }
        return true;
        
    }
private:
    unordered_map<char,char> mm = {
        {'0','0'},
        {'1','1'},
        {'6','9'},
        {'8','8'},
        {'9','6'},
    };
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


