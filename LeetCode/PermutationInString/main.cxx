#include <bits/stdc++.h>
#include <gtest/gtest.h>

using namespace std;

class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if (s1.size() > s2.size()) return false;
        array<int,26> a1={0};
        for (char c : s1){
            a1[c-'a']++;
        }
        array<int,26> tmp={0};
        for (int i = 0 ;i < s1.size();i++){
            tmp[s2[i]- 'a']++;
        }
        if (tmp == a1) return true;
        for (int i = 0 ;i + s1.size() < s2.size();i++){
            tmp[s2[i]-'a']--;
            tmp[s2[i+s1.size()] - 'a']++;
            if (tmp == a1) return true;
        }
        return false;
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


