#include <bits/stdc++.h>
#include <gtest/gtest.h>

using namespace std;

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int,int> mm;
        mm[0]+=1;
        int count=0;
        int sum=0;
        for (int i = 0;i< nums.size();i++){
            sum += nums[i];
            auto f = mm.find(sum-k);
            if (f != mm.end()){
                count += f->second;
            }
            mm[sum]+=1;
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


