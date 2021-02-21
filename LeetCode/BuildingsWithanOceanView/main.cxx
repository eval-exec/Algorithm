#include <bits/stdc++.h>
#include <gtest/gtest.h>

using namespace std;

class Solution {
public:
    vector<int> findBuildings(vector<int>& heights) {
        int len = heights.size();
        vector<int> ret;
        int rm = 0;
        for (int i  = len-1;i>= 0 ;i--){
            if (heights[i] > rm){
                ret.push_back(i);
            }
            rm = max(rm,heights[i]);
        }
        reverse(ret.begin(),ret.end());
        return ret;
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


