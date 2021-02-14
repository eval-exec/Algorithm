#include <bits/stdc++.h>
#include <gtest/gtest.h>

using namespace std;


class Solution {
public:
    int sumOfUnique(vector<int>& nums) {
        unordered_map<int,int> mm;
        for (int n : nums){
            mm[n]++;
        }
        int sum = 0;
        for (auto m : mm){
            if (m.second == 1) sum += m.first;
        }

        return sum;
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


