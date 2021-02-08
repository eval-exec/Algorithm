#include <bits/stdc++.h>
#include <gtest/gtest.h>

using namespace std;
class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
		vector<int> rets(nums.size());
		int left = 0,right = nums.size()-1;
        int i = nums.size()-1;
        while(left <= right){
            if (abs(nums[left]) > abs(nums[right])){
                rets[i] = nums[left] * nums[left];
                left++;
            }else{
                rets[i] = nums[right] * nums[right];
                right--;
            }
            i--;
        }
        return rets;
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


