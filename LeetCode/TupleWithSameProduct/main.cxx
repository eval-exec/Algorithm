#include <bits/stdc++.h>
#include <gtest/gtest.h>

using namespace std;
class Solution {
public:
    int tupleSameProduct(vector<int>& nums) {
        unordered_map<int,int> mm;
        for (int i = 1;i < nums.size();i++){
            for (int j = i-1;j >= 0 ;j--){
                mm[nums[i]*nums[j]]+=1;
            }
        }
        int count = 0;
        for (auto  m : mm){
            int n = m.second;
            if (n == 1) continue;
            // c(4,2) * 8;
            count += n*(n-1) *4;
        }
        return count;
    }
};





struct T{
    vector<int> nums;
    int e;
};

TEST(Solution,test){
    T ts[] = {
        {
            {1,2,4,5,10},
            16
        },

    };


    for (T t : ts){
    Solution solution;
    EXPECT_EQ(solution.tupleSameProduct(t.nums),t.e);

    }
}

int main() {
    testing::InitGoogleTest();

    return RUN_ALL_TESTS();
}


