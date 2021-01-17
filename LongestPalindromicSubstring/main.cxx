#include <bits/stdc++.h>
#include <gtest/gtest.h>

using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        if (s.empty()) return "";
        int len = s.size();
        int start = 0;
        int length= 1;
        for (int i = 0;i < len; i++){
            int left = i-1, right = i+1;
            while(left >= 0 && right < len){
                if (s[left] == s[right]) {
                    left--;
                    right++;
                }else{
                    break;
                }
            }
            if (right - left - 1 > length){
                start = left+1;
                length = right - left -1;
            }
        }
        for (int i = 1;i < len; i++){
            int left = i-1, right = i;
            while(left >= 0 && right < len){
                if (s[left] == s[right]) {
                    left--;
                    right++;
                }else{
                    break;
                }
            }
            if (right - left - 1 > length){
                start = left+1;
                length = right - left -1;
            }
        }
        return s.substr(start,length);
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


