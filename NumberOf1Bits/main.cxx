#include <bits/stdc++.h>
#include <gtest/gtest.h>

using namespace std;

class Solution {
public:
    int hammingWeight(uint32_t n) {
        int one = 0;
        while(n > 0){
            if ((n & 1) == 1){
                one++;
            }
            n >>= 1;
        }
        return one;
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


