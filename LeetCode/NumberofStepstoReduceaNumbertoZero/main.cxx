#include <bits/stdc++.h>
#include <gtest/gtest.h>

using namespace std;

class Solution {
public:
    int numberOfSteps (int num) {
        int count = 0;
        while(num != 0){
            if ((num & 1) == 0){
                num /= 2;
            }else{
                num--;
            }
            count++;
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


    for (T t : ts){
        Solution solution;

    }
}

int main() {
    testing::InitGoogleTest();

    return RUN_ALL_TESTS();
}


