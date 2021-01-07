#include <bits/stdc++.h>
#include <gtest/gtest.h>

using namespace std;


class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<int,int> mm;
        int left = 0;
        int len = 0;
        for (int i = 0 ;i < s.size();i++){
            int n = s[i];
            auto f = mm.find(n);
            if (f == mm.end()){
                len = max(len,i-left+1);
            }else{
                int right = f->second;
                for (int si = left;si <= right;si++){
                    int x =  mm[s[si]];
                    if (x == si){
                        mm.erase(s[si]);
                    }
                }
                left = right+1;
            }
            mm[n] = i;
        }
        return len;
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


