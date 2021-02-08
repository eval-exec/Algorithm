#include <bits/stdc++.h>
#include <gtest/gtest.h>

using namespace std;


class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.size() <=2) return nums.size();
        // 0 1 2 3 4 5 
        int l1 = nums[0];
        int l2 = nums[1];
        int j = 2;
        for (int i = 2;i < nums.size();i++){
            if (nums[i] == l1&& nums[i] ==l2){
                continue;
            }else{
                l1 = l2;
                l2 = nums[i];
                nums[j] = nums[i];
                j++;
            }
        }
        return j;
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


