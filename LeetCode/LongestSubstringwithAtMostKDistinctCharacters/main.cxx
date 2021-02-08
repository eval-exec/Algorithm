#include <bits/stdc++.h>
#include <gtest/gtest.h>

using namespace std;




class Solution {
    public:
        int lengthOfLongestSubstringKDistinct(string s, int k) {
            if (k == 0 ) return 0;
            if (k >= s.size() ) return s.size();
            int max_len = 0;
            int left = 0;
            unordered_map<char,int> mm;
            for (int i = 0;i < s.size();i++){
                mm[s[i]]++;
                while(mm.size()> k){
                    mm[s[left]]--;
                    if (mm[s[left]] == 0 )      mm.erase(s[left]);
                    left++;
                }
                max_len = max(max_len,i - left + 1);
            }
            return max_len;
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


