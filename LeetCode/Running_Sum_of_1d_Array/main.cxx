#include <bits/stdc++.h>
#include <gtest/gtest.h>
using namespace std;


//// START
/*
## Running Sum of 1d Array

*/
class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
        vector<int> rets(nums.size());
        int sum  = 0;
        for (int i = 0 ;i  < nums.size();i++){
            sum += nums[i];
            rets[i] = sum;
        }
        return rets;
    }
};



//// END
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


