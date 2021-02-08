#include <bits/stdc++.h>
#include <gtest/gtest.h>

using namespace std;


class Solution {
public:
    bool kLengthApart(vector<int>& nums, int k) {
        int last = 0;
        while(last < nums.size() && nums[last] == 0 ){
            last++;
        }
        if (last == nums.size()) return true;
        for (int i = last+1;i< nums.size();i++){
            if (nums[i]== 1){
                if (i - last -1 < k) return false;
                last = i;
            }
        }
        return true;
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


