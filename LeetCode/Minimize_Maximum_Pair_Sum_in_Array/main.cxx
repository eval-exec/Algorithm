#include <bits/stdc++.h>
#include <gtest/gtest.h>
using namespace std;


//// START
/*
## Minimize Maximum Pair Sum in Array

*/

class Solution {
public:
    int minPairSum(vector<int>& nums) {
      sort(nums.begin(),nums.end());
      int ret = 0;
      int left = 0,right = nums.size()-1;
      while(left < right){
        ret  = max(ret,nums[left]+nums[right]);
        left++;
        right--;
      }
      return ret;
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


