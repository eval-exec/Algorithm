#include <bits/stdc++.h>
#include <gtest/gtest.h>
using namespace std;


class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        int len1 = word1.size();
        int len2 = word2.size();
        string ret;
        int i = 0;
        for (i = 0 ;i < min(len1,len2);i++){
            ret.push_back(word1[i]);
            ret.push_back(word2[i]);
        }
        if (len1 < len2){
            ret += word2.substr(i,len2 - i);
        }elseif (len1 > len2){
            ret += word1.substr(i,len1 - i);
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


