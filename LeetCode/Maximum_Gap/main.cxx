#include <bits/stdc++.h>
#include <gtest/gtest.h>
using namespace std;


//// START
/*
## Maximum Gap

*/
class Solution {
public:
    int maximumGap(vector<int>& nums) {
    
        sort(nums.begin(),nums.end());
        int li = -1;
        int ret = 0;
        for (int i = 0;i < nums.size();i++){
            if (li == -1){
                li = nums[i];
            }else{
                ret = max(ret,nums[i]-li);
                
            }
            li = nums[i];
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


