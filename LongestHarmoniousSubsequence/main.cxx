#include <bits/stdc++.h>
#include <gtest/gtest.h>

using namespace std;

class Solution {
public:
    int findLHS(vector<int>& nums) {
        int max_len = 0;
        map<int,int> mm;
        for (int n: nums ){
            mm[n]++;
        }
        int lastn = INT_MAX;
        int lastc = 0;
        for (auto m : mm){
            if (lastn != INT_MAX && lastn + 1 == m.first){
                max_len = max(max_len,lastc + m.second);
            }
            lastn = m.first;
            lastc = m.second;
        }
        return max_len;
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


