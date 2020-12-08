#include <bits/stdc++.h>
#include <gtest/gtest.h>

using namespace std;

class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        vector<int> nums(arr);
        sort(nums.begin(),nums.end());

        int suma = 0,sumn=0,count=0;

        for (int i  =0; i < arr.size(); i++){
            suma+=arr[i];
            sumb+=nums[i];
            if (suma == sumb) count++;
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


