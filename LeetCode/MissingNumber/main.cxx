#include <bits/stdc++.h>
#include <gtest/gtest.h>
using namespace std;

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int sum = 0;
        int b = 0;
        int count = 0;
        for (int n : nums){
            sum+=n;
            if (n > b) b = n;
            count++;
        }
        int s2 = b*(b+1)/2;
        if (sum == s2 {
            return count == b ? 0 : b + 1;
        }
        return s2 - sum;
    }
};




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


