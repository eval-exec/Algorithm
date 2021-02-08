#include <bits/stdc++.h>
#include <gtest/gtest.h>

using namespace std;

class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int left= 0,right = nums.size()-1;
        int count=0;
        while(left < right){
            if (nums[left]+nums[right] == k){
                left++;
                right--;
                count++;
            }else if (nums[left]+nums[right] < k){
                left++;
            }else{
                right--;
            }
        }
        return count;
        
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


