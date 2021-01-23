#include <bits/stdc++.h>
#include <gtest/gtest.h>

using namespace std;


class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int left = 0,right = 0;
        int max_len = 0;
        int zero = -1;
        for (int i = 0; i < nums.size(); i++){
            if (nums[i] == 1){
                right++;
            }else{
                int len = 0;
                if (zero == -1){
                    len = right + 1;
                }else{
                    len = left + 1 + right;
                }
                max_len = max(max_len, len);
                zero = i;
                left = right;
                right = 0;
            }
        }
        if (zero == -1){
            len = right;
        }else{
            len = left + 1 + right;
        }
        max_len = max(max_len, len);
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


    for (T t : ts){
        Solution solution;

    }
}

int main() {
    testing::InitGoogleTest();

    return RUN_ALL_TESTS();
}


