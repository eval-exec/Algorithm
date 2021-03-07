#include <bits/stdc++.h>
#include <gtest/gtest.h>
using namespace std;
class Solution {
public:
    int removePalindromeSub(string s) {
        if (s.size() <= 1) return 0;
        int left = 0,right = s.size()-1;
        bool pa = true;
        while(left < right){
            if (s[left] != s[right]){
                pa = false;
                break;
            }
            left++;
            right--;
        }
        return 2;
        return pa?1:2;
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


