#include <bits/stdc++.h>
#include <gtest/gtest.h>

using namespace std;


class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        if (nums.empty()) return ;
        int len = nums.size();
        int max_i= len-1;
        for (int i = len-1;i >= -1;i--){
            if (i == -1){
                sort(nums.begin(),nums.end());
                return;
            }
            if (nums[i] < nums[max_i]){
                int si = max_i;
                for (int j = i+1;j< len;j++){
                    if (nums[j] > nums[i] && nums[j] < nums[si]) si = j;
                }
                swap(nums[i],nums[si]);
                sort(nums.begin()+i+1,nums.end());
                return;
            }else{
                max_i = i;
            }
        }
        return;
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


