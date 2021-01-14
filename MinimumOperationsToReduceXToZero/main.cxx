#include <bits/stdc++.h>
#include <gtest/gtest.h>

using namespace std;



class Solution {
    public:
        int minOperations(vector<int>& nums, int x) {
            int sum = 0;
            for (const int &n : nums){
                sum+=n;
            }
            if (x > sum) return -1;
            if (x == sum) return nums.size();
            op(nums,0,0,nums.size()-1,x);
            if (min_count > nums.size()){
                return -1;
            }
            return min_count;
        }
    private:
        int min_count = INT_MAX;
        void op(const vector<int> & nums,int count, int left, int right, int x){
            if (x == 0 ) {
                min_count = min(min_count,count);
                return;
            }
            if (x < 0 || left > right){
                return;
            }
            op(nums,count+1,left+1,right,x - nums[left]);
            op(nums,count+1,left,right-1,x - nums[right]);
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


