#include <bits/stdc++.h>
#include <gtest/gtest.h>

using namespace std;

class Solution {
    public:
        int numPairsDivisibleBy60(vector<int>& time) {
            array<int,60> aa={0};
            int count=0;
            for (const int &t : time){
                int x = t%60;
                count += aa[(60 - x)%60];
                aa[x]+=1;
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


