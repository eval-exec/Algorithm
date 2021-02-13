#include <bits/stdc++.h>
#include <gtest/gtest.h>

using namespace std;


class Solution {
public:
    int maximumScore(int a, int b, int c) {
        vector<int> nums = {a,b,c};
        sort(nums.begin(),nums.end());
        int scores = 0;
        while(nums[2] != 0 && nums[1] != 0){
            proc(nums);
            scores++;
            sort(nums.begin(),nums.end());
        }
        return scores;
    }
private:
    void proc(vector<int> &nums){
        if (nums[0] != 0 ){
            nums[0]--;
        }else if (nums[1] != 0){
            nums[1]--;
        }else{
            return;
        }
        nums[2]--;
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


